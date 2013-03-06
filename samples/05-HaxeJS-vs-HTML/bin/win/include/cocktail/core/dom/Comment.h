#ifndef INCLUDED_cocktail_core_dom_Comment
#define INCLUDED_cocktail_core_dom_Comment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/CharacterData.h>
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Comment)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace dom{


class Comment_obj : public ::cocktail::core::dom::CharacterData_obj{
	public:
		typedef ::cocktail::core::dom::CharacterData_obj super;
		typedef Comment_obj OBJ_;
		Comment_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Comment_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Comment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Comment"); }

		virtual int get_nodeType( );

		virtual Void detach( bool recursive);

		virtual Void attach( bool recursive);

		virtual Void updateElementRenderer( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Comment */ 
