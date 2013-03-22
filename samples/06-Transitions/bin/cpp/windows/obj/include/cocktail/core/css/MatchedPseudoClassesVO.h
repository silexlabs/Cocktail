#ifndef INCLUDED_cocktail_core_css_MatchedPseudoClassesVO
#define INCLUDED_cocktail_core_css_MatchedPseudoClassesVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,MatchedPseudoClassesVO)
namespace cocktail{
namespace core{
namespace css{


class MatchedPseudoClassesVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MatchedPseudoClassesVO_obj OBJ_;
		MatchedPseudoClassesVO_obj();
		Void __construct(bool hover,bool focus,bool active,bool link,bool enabled,bool disabled,bool checked,bool hasId,bool hasClasses,::String nodeId,Array< ::String > nodeClassList,::String nodeType);

	public:
		static hx::ObjectPtr< MatchedPseudoClassesVO_obj > __new(bool hover,bool focus,bool active,bool link,bool enabled,bool disabled,bool checked,bool hasId,bool hasClasses,::String nodeId,Array< ::String > nodeClassList,::String nodeType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MatchedPseudoClassesVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MatchedPseudoClassesVO"); }

		::String nodeType; /* REM */ 
		Array< ::String > nodeClassList; /* REM */ 
		bool hasClasses; /* REM */ 
		::String nodeId; /* REM */ 
		bool hasId; /* REM */ 
		bool checked; /* REM */ 
		bool disabled; /* REM */ 
		bool enabled; /* REM */ 
		bool link; /* REM */ 
		bool active; /* REM */ 
		bool focus; /* REM */ 
		bool hover; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_MatchedPseudoClassesVO */ 
