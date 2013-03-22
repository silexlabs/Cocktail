#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#define INCLUDED_cocktail_core_html_HTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLFormElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLInputElement)
HX_DECLARE_CLASS3(cocktail,core,html,ValueModeValue)
namespace cocktail{
namespace core{
namespace html{


class HTMLInputElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLInputElement"); }

		virtual ::String set_name( ::String value);
		Dynamic set_name_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual ::String set_type( ::String value);
		Dynamic set_type_dyn();

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual bool get_disabled( );
		Dynamic get_disabled_dyn();

		virtual bool set_readonly( bool value);
		Dynamic set_readonly_dyn();

		virtual bool get_readonly( );
		Dynamic get_readonly_dyn();

		virtual bool set_checked( bool value);
		Dynamic set_checked_dyn();

		virtual bool get_checked( );
		Dynamic get_checked_dyn();

		virtual int get_maxLength( );
		Dynamic get_maxLength_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual Dynamic get_intrinsicHeight( );

		virtual Dynamic get_intrinsicWidth( );

		virtual Void onUserInput( );
		Dynamic onUserInput_dyn();

		virtual Void onUserActivation( );
		Dynamic onUserActivation_dyn();

		virtual ::String getElementRendererValue( );
		Dynamic getElementRendererValue_dyn();

		virtual Void dissociateFormElement( ::cocktail::core::html::HTMLFormElement form);
		Dynamic dissociateFormElement_dyn();

		virtual Void associateFormElement( ::cocktail::core::html::HTMLFormElement form);
		Dynamic associateFormElement_dyn();

		virtual ::cocktail::core::html::HTMLFormElement getFirstFormAncestor( );
		Dynamic getFirstFormAncestor_dyn();

		virtual Void resetFormOwner( );
		Dynamic resetFormOwner_dyn();

		virtual Void updateRadioButtonGroup( );
		Dynamic updateRadioButtonGroup_dyn();

		virtual Void updateCheckedness( bool value);
		Dynamic updateCheckedness_dyn();

		virtual bool readonlyApplies( );
		Dynamic readonlyApplies_dyn();

		virtual bool isMutable( );
		Dynamic isMutable_dyn();

		virtual ::String applyValueSanitization( ::String value,::String type);
		Dynamic applyValueSanitization_dyn();

		virtual bool useDefaultOrDefaultOnMode( ::String type);
		Dynamic useDefaultOrDefaultOnMode_dyn();

		virtual bool useValueMode( ::String type);
		Dynamic useValueMode_dyn();

		virtual Void updateInputType( ::String oldType);
		Dynamic updateInputType_dyn();

		virtual Void updateInputRendererState( );
		Dynamic updateInputRendererState_dyn();

		virtual Void runPostClickActivationStep( ::cocktail::core::event::MouseEvent event);

		virtual Void runPreClickActivation( );

		virtual bool hasActivationBehaviour( );

		virtual Void removed( );

		virtual Void appended( );

		virtual bool isDefaultFocusable( );

		virtual Void createElementRenderer( );

		virtual Void reset( );

		virtual Void setAttribute( ::String name,::String value);

		virtual bool dispatchEvent( ::cocktail::core::event::Event evt);

		virtual bool isVoidElement( );

		::cocktail::core::html::HTMLFormElement form; /* REM */ 
		::String name; /* REM */ 
		::String type; /* REM */ 
		bool disabled; /* REM */ 
		bool readOnly; /* REM */ 
		bool checked; /* REM */ 
		int maxLength; /* REM */ 
		::String value; /* REM */ 
		bool _checkednessIsDirty; /* REM */ 
		bool _checkedness; /* REM */ 
		bool _valueIsDirty; /* REM */ 
		::cocktail::core::html::ValueModeValue _valueMode; /* REM */ 
		::String _value; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLInputElement */ 
