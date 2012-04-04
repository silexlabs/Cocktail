#ifndef INCLUDED_cocktail_core_focus_AbstractFocusManagerImpl
#define INCLUDED_cocktail_core_focus_AbstractFocusManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,focus,AbstractFocusManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBodyElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace focus{


class AbstractFocusManagerImpl_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractFocusManagerImpl_obj OBJ_;
		AbstractFocusManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractFocusManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractFocusManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractFocusManagerImpl"); }

		::cocktail::core::html::HTMLBodyElement _bodyElement; /* REM */ 
		::cocktail::core::html::HTMLBodyElement bodyElement; /* REM */ 
		::cocktail::port::flash_player::HTMLElement _activeElement; /* REM */ 
		::cocktail::port::flash_player::HTMLElement activeElement; /* REM */ 
		Array< ::cocktail::port::flash_player::HTMLElement > _tabList; /* REM */ 
		int _tabListIndex; /* REM */ 
		virtual Void initKeyboardListeners( );
		Dynamic initKeyboardListeners_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void onKeyDown( ::cocktail::core::event::KeyboardEvent keyboardEvent);
		Dynamic onKeyDown_dyn();

		virtual Void onKeyUp( ::cocktail::core::event::KeyboardEvent keyEventData);
		Dynamic onKeyUp_dyn();

		virtual Void doTabFocus( bool reverse);
		Dynamic doTabFocus_dyn();

		virtual Array< ::cocktail::port::flash_player::HTMLElement > buildTabList( ::cocktail::port::flash_player::HTMLElement htmlElement);
		Dynamic buildTabList_dyn();

		virtual Void doBuildTabList( ::cocktail::port::flash_player::HTMLElement htmlElement,Array< ::cocktail::port::flash_player::HTMLElement > orderedTabList,Array< ::cocktail::port::flash_player::HTMLElement > indexedTabList);
		Dynamic doBuildTabList_dyn();

		virtual Void simulateMouseClick( ::cocktail::core::event::KeyboardEvent keyEventData);
		Dynamic simulateMouseClick_dyn();

		virtual ::cocktail::port::flash_player::HTMLElement setActiveElement( ::cocktail::port::flash_player::HTMLElement value);
		Dynamic setActiveElement_dyn();

		virtual ::cocktail::port::flash_player::HTMLElement getActiveElement( );
		Dynamic getActiveElement_dyn();

		virtual ::cocktail::core::html::HTMLBodyElement setBodyElement( ::cocktail::core::html::HTMLBodyElement value);
		Dynamic setBodyElement_dyn();

		virtual ::cocktail::core::html::HTMLBodyElement getBodyElement( );
		Dynamic getBodyElement_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace focus

#endif /* INCLUDED_cocktail_core_focus_AbstractFocusManagerImpl */ 
