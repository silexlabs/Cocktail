#ifndef INCLUDED_cocktail_core_dom_DOMConstants
#define INCLUDED_cocktail_core_dom_DOMConstants

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,DOMConstants)
namespace cocktail{
namespace core{
namespace dom{


class DOMConstants_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DOMConstants_obj OBJ_;
		DOMConstants_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DOMConstants_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DOMConstants_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DOMConstants"); }

		static int ELEMENT_NODE; /* REM */ 
		static int ATTRIBUTE_NODE; /* REM */ 
		static int TEXT_NODE; /* REM */ 
		static int CDATA_SECTION_NODE; /* REM */ 
		static int ENTITY_REFERENCE_NODE; /* REM */ 
		static int ENTITY_NODE; /* REM */ 
		static int PROCESSING_INSTRUCTION_NODE; /* REM */ 
		static int COMMENT_NODE; /* REM */ 
		static int DOCUMENT_NODE; /* REM */ 
		static int DOCUMENT_TYPE_NODE; /* REM */ 
		static int DOCUMENT_FRAGMENT_NODE; /* REM */ 
		static int NOTATION_NODE; /* REM */ 
		static ::String EVENT_INTERFACE; /* REM */ 
		static ::String UI_EVENT_INTERFACE; /* REM */ 
		static ::String MOUSE_EVENT_INTERFACE; /* REM */ 
		static ::String FOCUS_EVENT_INTERFACE; /* REM */ 
		static ::String KEYBOARD_EVENT_INTERFACE; /* REM */ 
		static ::String WHEEL_EVENT_INTERFACE; /* REM */ 
		static ::String CUSTOM_EVENT_INTERFACE; /* REM */ 
		static ::String TRANSITION_EVENT_INTERFACE; /* REM */ 
		static ::String POPSTATE_EVENT_INTERFACE; /* REM */ 
		static ::String MATCH_ALL_TAG_NAME; /* REM */ 
		static ::String TEXT_NODE_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_DOMConstants */ 
