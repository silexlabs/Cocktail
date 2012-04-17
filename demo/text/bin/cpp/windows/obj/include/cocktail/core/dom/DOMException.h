#ifndef INCLUDED_cocktail_core_dom_DOMException
#define INCLUDED_cocktail_core_dom_DOMException

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,DOMException)
namespace cocktail{
namespace core{
namespace dom{


class DOMException_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DOMException_obj OBJ_;
		DOMException_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DOMException_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DOMException_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("DOMException"); }

		static int INDEX_SIZE_ERR; /* REM */ 
		static int DOMSTRING_SIZE_ERR; /* REM */ 
		static int HIERARCHY_REQUEST_ERR; /* REM */ 
		static int WRONG_DOCUMENT_ERR; /* REM */ 
		static int INVALID_CHARACTER_ERR; /* REM */ 
		static int NO_DATA_ALLOWED_ERR; /* REM */ 
		static int NO_MODIFICATION_ALLOWED_ERR; /* REM */ 
		static int NOT_FOUND_ERR; /* REM */ 
		static int NOT_SUPPORTED_ERR; /* REM */ 
		static int INUSE_ATTRIBUTE_ERR; /* REM */ 
		static int INVALID_STATE_ERR; /* REM */ 
		static int SYNTAX_ERR; /* REM */ 
		static int INVALID_MODIFICATION_ERR; /* REM */ 
		static int NAMESPACE_ERR; /* REM */ 
		static int INVALID_ACCESS_ERR; /* REM */ 
		static int VALIDATION_ERR; /* REM */ 
		static int TYPE_MISMATCH_ERR; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_DOMException */ 
