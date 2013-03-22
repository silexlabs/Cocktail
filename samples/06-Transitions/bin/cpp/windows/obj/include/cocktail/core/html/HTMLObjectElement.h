#ifndef INCLUDED_cocktail_core_html_HTMLObjectElement
#define INCLUDED_cocktail_core_html_HTMLObjectElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLObjectElement)
HX_DECLARE_CLASS2(cocktail,plugin,Plugin)
namespace cocktail{
namespace core{
namespace html{


class HTMLObjectElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
		typedef HTMLObjectElement_obj OBJ_;
		HTMLObjectElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLObjectElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLObjectElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLObjectElement"); }

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual ::String set_type( ::String value);
		Dynamic set_type_dyn();

		virtual ::String get_data( );
		Dynamic get_data_dyn();

		virtual ::String set_data( ::String value);
		Dynamic set_data_dyn();

		virtual Void onLoadError( );
		Dynamic onLoadError_dyn();

		virtual Void onLoadComplete( );
		Dynamic onLoadComplete_dyn();

		virtual Void createElementRenderer( );

		virtual Void onPluginResourceLoaded( ::cocktail::core::event::Event e);
		Dynamic onPluginResourceLoaded_dyn();

		virtual Void deletePlugin( );
		Dynamic deletePlugin_dyn();

		virtual Void createPlugin( );
		Dynamic createPlugin_dyn();

		virtual Void removedFromDOM( );

		virtual Void addedToDOM( );

		virtual Void attach( bool recursive);

		virtual Void setAttribute( ::String name,::String value);

		bool _pluginReady; /* REM */ 
		::cocktail::plugin::Plugin plugin; /* REM */ 
		::String type; /* REM */ 
		::String data; /* REM */ 
		static Float HTML_OBJECT_INTRISIC_WIDTH; /* REM */ 
		static Float HTML_OBJECT_INTRINSIC_HEIGHT; /* REM */ 
		static ::String SWF_FILE_EXTENSION; /* REM */ 
		static ::String SWF_FILE_MIME_TYPE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLObjectElement */ 
