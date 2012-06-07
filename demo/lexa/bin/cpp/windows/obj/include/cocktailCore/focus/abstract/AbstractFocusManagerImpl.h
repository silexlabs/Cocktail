#ifndef INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl
#define INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktailCore,focus,abstract,AbstractFocusManagerImpl)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,KeyboardEvent)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,HTMLBodyElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace cocktailCore{
namespace focus{
namespace abstract{


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

		::core::html::HTMLBodyElement _bodyElement; /* REM */ 
		::core::html::HTMLBodyElement bodyElement; /* REM */ 
		::port::flash_player::HTMLElement _activeElement; /* REM */ 
		::port::flash_player::HTMLElement activeElement; /* REM */ 
		Array< ::port::flash_player::HTMLElement > _tabList; /* REM */ 
		int _tabListIndex; /* REM */ 
		virtual Void initKeyboardListeners( );
		Dynamic initKeyboardListeners_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void onKeyDown( ::core::event::KeyboardEvent keyboardEvent);
		Dynamic onKeyDown_dyn();

		virtual Void onKeyUp( ::core::event::KeyboardEvent keyEventData);
		Dynamic onKeyUp_dyn();

		virtual Void doTabFocus( bool reverse);
		Dynamic doTabFocus_dyn();

		virtual Array< ::port::flash_player::HTMLElement > buildTabList( ::port::flash_player::HTMLElement htmlElement);
		Dynamic buildTabList_dyn();

		virtual Void doBuildTabList( ::port::flash_player::HTMLElement htmlElement,Array< ::port::flash_player::HTMLElement > orderedTabList,Array< ::port::flash_player::HTMLElement > indexedTabList);
		Dynamic doBuildTabList_dyn();

		virtual Void simulateMouseClick( ::core::event::KeyboardEvent keyEventData);
		Dynamic simulateMouseClick_dyn();

		virtual ::port::flash_player::HTMLElement setActiveElement( ::port::flash_player::HTMLElement value);
		Dynamic setActiveElement_dyn();

		virtual ::port::flash_player::HTMLElement getActiveElement( );
		Dynamic getActiveElement_dyn();

		virtual ::core::html::HTMLBodyElement setBodyElement( ::core::html::HTMLBodyElement value);
		Dynamic setBodyElement_dyn();

		virtual ::core::html::HTMLBodyElement getBodyElement( );
		Dynamic getBodyElement_dyn();

};

} // end namespace cocktailCore
} // end namespace focus
} // end namespace abstract

#endif /* INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl */ 
