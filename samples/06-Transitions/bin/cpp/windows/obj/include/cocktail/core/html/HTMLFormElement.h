#ifndef INCLUDED_cocktail_core_html_HTMLFormElement
#define INCLUDED_cocktail_core_html_HTMLFormElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLFormElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLFormElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLFormElement_obj OBJ_;
		HTMLFormElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLFormElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLFormElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLFormElement"); }

		virtual ::String set_action( ::String value);
		Dynamic set_action_dyn();

		virtual ::String get_action( );
		Dynamic get_action_dyn();

		virtual ::String set_enctype( ::String value);
		Dynamic set_enctype_dyn();

		virtual ::String get_enctype( );
		Dynamic get_enctype_dyn();

		virtual ::String set_method( ::String value);
		Dynamic set_method_dyn();

		virtual ::String get_method( );
		Dynamic get_method_dyn();

		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual ::String getElementValue( ::cocktail::core::html::HTMLElement element);
		Dynamic getElementValue_dyn();

		virtual ::String getElementType( ::cocktail::core::html::HTMLElement element);
		Dynamic getElementType_dyn();

		virtual bool isUncheckedRadioOrCheckBox( ::cocktail::core::html::HTMLElement element);
		Dynamic isUncheckedRadioOrCheckBox_dyn();

		virtual bool isButton( ::cocktail::core::html::HTMLElement element);
		Dynamic isButton_dyn();

		virtual bool canBeSubmitted( ::cocktail::core::html::HTMLElement element,::cocktail::core::html::HTMLElement submitter);
		Dynamic canBeSubmitted_dyn();

		virtual Array< ::cocktail::core::html::HTMLElement > getSubmittablesElements( ::cocktail::core::html::HTMLElement rootElement,Array< ::cocktail::core::html::HTMLElement > submittableElements);
		Dynamic getSubmittablesElements_dyn();

		virtual Dynamic constructFormDataSet( ::cocktail::core::html::HTMLElement submitter);
		Dynamic constructFormDataSet_dyn();

		virtual ::String getSubmitTarget( ::cocktail::core::html::HTMLElement submitter);
		Dynamic getSubmitTarget_dyn();

		virtual ::String getSubmitMethod( ::cocktail::core::html::HTMLElement submitter);
		Dynamic getSubmitMethod_dyn();

		virtual ::String getSubmitEnctype( ::cocktail::core::html::HTMLElement submitter);
		Dynamic getSubmitEnctype_dyn();

		virtual ::String getSubmitAction( ::cocktail::core::html::HTMLElement submitter);
		Dynamic getSubmitAction_dyn();

		virtual ::String encodeAsURLQuery( Dynamic formDataSet);
		Dynamic encodeAsURLQuery_dyn();

		virtual Void submitAsEntityBody( Dynamic formDataSet,::String action,::String enctype);
		Dynamic submitAsEntityBody_dyn();

		virtual Void mutateActionUrl( Dynamic formDataSet,::String action);
		Dynamic mutateActionUrl_dyn();

		virtual Void doSubmit( ::cocktail::core::html::HTMLElement submitter);
		Dynamic doSubmit_dyn();

		virtual Void reset( );

		virtual Void submitFrom( ::cocktail::core::html::HTMLElement submitter);
		Dynamic submitFrom_dyn();

		virtual Void submit( );
		Dynamic submit_dyn();

		::String action; /* REM */ 
		::String enctype; /* REM */ 
		::String method; /* REM */ 
		bool _submittedFromSubmitMethod; /* REM */ 
		int length; /* REM */ 
		Array< ::cocktail::core::html::HTMLElement > elements; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLFormElement */ 
