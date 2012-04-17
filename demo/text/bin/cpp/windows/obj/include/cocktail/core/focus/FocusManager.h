#ifndef INCLUDED_cocktail_core_focus_FocusManager
#define INCLUDED_cocktail_core_focus_FocusManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,focus,FocusManager)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
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

		virtual ::cocktail::core::html::HTMLElement getNextFocusedElement( bool reverse,::cocktail::core::html::HTMLElement rootElement,::cocktail::core::html::HTMLElement activeElement);
		Dynamic getNextFocusedElement_dyn();

		virtual int getElementTabListIndex( ::cocktail::core::html::HTMLElement element,Array< ::cocktail::core::html::HTMLElement > tabList);
		Dynamic getElementTabListIndex_dyn();

		virtual Array< ::cocktail::core::html::HTMLElement > buildTabList( ::cocktail::core::html::HTMLElement rootElement);
		Dynamic buildTabList_dyn();

		virtual Void doBuildTabList( ::cocktail::core::html::HTMLElement htmlElement,Array< ::cocktail::core::html::HTMLElement > orderedTabList,Array< ::cocktail::core::html::HTMLElement > indexedTabList);
		Dynamic doBuildTabList_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace focus

#endif /* INCLUDED_cocktail_core_focus_FocusManager */ 
