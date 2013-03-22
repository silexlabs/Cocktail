#ifndef INCLUDED_cocktail_core_utils_FastNode
#define INCLUDED_cocktail_core_utils_FastNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace utils{


class FastNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FastNode_obj OBJ_;
		FastNode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FastNode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FastNode"); }

		virtual Void insertBefore( Dynamic newChild,Dynamic refChild);
		Dynamic insertBefore_dyn();

		virtual Void removeFromParentIfNecessary( Dynamic newChild);
		Dynamic removeFromParentIfNecessary_dyn();

		virtual Void appendChild( Dynamic newChild);
		Dynamic appendChild_dyn();

		virtual Void removeChild( Dynamic oldChild);
		Dynamic removeChild_dyn();

		Dynamic previousSibling; /* REM */ 
		Dynamic nextSibling; /* REM */ 
		Dynamic lastChild; /* REM */ 
		Dynamic firstChild; /* REM */ 
		Dynamic parentNode; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace utils

#endif /* INCLUDED_cocktail_core_utils_FastNode */ 
