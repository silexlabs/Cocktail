#ifndef INCLUDED_cocktail_core_http_XMLHttpRequestUpload
#define INCLUDED_cocktail_core_http_XMLHttpRequestUpload

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,XMLHttpRequestEventTarget)
HX_DECLARE_CLASS3(cocktail,core,http,XMLHttpRequestUpload)
namespace cocktail{
namespace core{
namespace http{


class XMLHttpRequestUpload_obj : public ::cocktail::core::event::XMLHttpRequestEventTarget_obj{
	public:
		typedef ::cocktail::core::event::XMLHttpRequestEventTarget_obj super;
		typedef XMLHttpRequestUpload_obj OBJ_;
		XMLHttpRequestUpload_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< XMLHttpRequestUpload_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~XMLHttpRequestUpload_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("XMLHttpRequestUpload"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace http

#endif /* INCLUDED_cocktail_core_http_XMLHttpRequestUpload */ 
