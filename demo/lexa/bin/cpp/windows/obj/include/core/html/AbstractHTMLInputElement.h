#ifndef INCLUDED_core_html_AbstractHTMLInputElement
#define INCLUDED_core_html_AbstractHTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLInputElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace html{


class AbstractHTMLInputElement_obj : public ::port::flash_player::HTMLElement_obj{
	public:
		typedef ::port::flash_player::HTMLElement_obj super;
		typedef AbstractHTMLInputElement_obj OBJ_;
		AbstractHTMLInputElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractHTMLInputElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractHTMLInputElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractHTMLInputElement"); }

		Dynamic _onChange; /* REM */ 
	Dynamic &_onChange_dyn() { return _onChange;}
		Dynamic onChange; /* REM */ 
	Dynamic &onChange_dyn() { return onChange;}
		bool _disabled; /* REM */ 
		bool disabled; /* REM */ 
		int _maxLength; /* REM */ 
		int maxLength; /* REM */ 
		::String _value; /* REM */ 
		::String value; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void initStyle( );
		Dynamic initStyle_dyn();

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

} // end namespace core
} // end namespace html

#endif /* INCLUDED_core_html_AbstractHTMLInputElement */ 
