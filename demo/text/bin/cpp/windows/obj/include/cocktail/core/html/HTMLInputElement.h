#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#define INCLUDED_cocktail_core_html_HTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLInputElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLInputElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLInputElement_obj OBJ_;
		HTMLInputElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLInputElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLInputElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLInputElement"); }

		Dynamic _onChange; /* REM */ 
	Dynamic &_onChange_dyn() { return _onChange;}
		Dynamic onchange; /* REM */ 
	Dynamic &onchange_dyn() { return onchange;}
		bool _disabled; /* REM */ 
		bool disabled; /* REM */ 
		int _maxLength; /* REM */ 
		int maxLength; /* REM */ 
		::String _value; /* REM */ 
		::String value; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		virtual Dynamic set_onChange( Dynamic value);
		Dynamic set_onChange_dyn();

		virtual Dynamic get_onChange( );
		Dynamic get_onChange_dyn();

		virtual Void onChangeCallback( );
		Dynamic onChangeCallback_dyn();

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual bool get_disabled( );
		Dynamic get_disabled_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual int get_maxLength( );
		Dynamic get_maxLength_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		static ::String HTML_INPUT_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLInputElement */ 
