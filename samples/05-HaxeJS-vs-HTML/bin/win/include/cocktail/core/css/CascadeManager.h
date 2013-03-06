#ifndef INCLUDED_cocktail_core_css_CascadeManager
#define INCLUDED_cocktail_core_css_CascadeManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CascadeManager)
namespace cocktail{
namespace core{
namespace css{


class CascadeManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CascadeManager_obj OBJ_;
		CascadeManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CascadeManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CascadeManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CascadeManager"); }

		virtual Void unFlagProperty( int index);
		Dynamic unFlagProperty_dyn();

		virtual Void flagProperty( int index);
		Dynamic flagProperty_dyn();

		virtual Void shouldCascadeAll( );
		Dynamic shouldCascadeAll_dyn();

		virtual Void removePropertyToCascade( int index);
		Dynamic removePropertyToCascade_dyn();

		virtual Void addPropertyToCascade( int index);
		Dynamic addPropertyToCascade_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		bool hasOutlineColor; /* REM */ 
		bool hasOutlineStyle; /* REM */ 
		bool hasBottomBorderColor; /* REM */ 
		bool hasTopBorderColor; /* REM */ 
		bool hasRightBorderColor; /* REM */ 
		bool hasLeftBorderColor; /* REM */ 
		bool hasBottomBorderStyle; /* REM */ 
		bool hasTopBorderStyle; /* REM */ 
		bool hasRightBorderStyle; /* REM */ 
		bool hasLeftBorderStyle; /* REM */ 
		bool hasTransitionProperty; /* REM */ 
		bool hasMarginBottom; /* REM */ 
		bool hasMarginRight; /* REM */ 
		bool hasMarginTop; /* REM */ 
		bool hasMarginLeft; /* REM */ 
		bool hasRight; /* REM */ 
		bool hasLeft; /* REM */ 
		bool hasBottom; /* REM */ 
		bool hasTop; /* REM */ 
		bool hasTextAlign; /* REM */ 
		bool hasMaxWidth; /* REM */ 
		bool hasMaxHeight; /* REM */ 
		bool hasHeight; /* REM */ 
		bool hasWidth; /* REM */ 
		bool hasWhiteSpace; /* REM */ 
		bool hasClear; /* REM */ 
		bool hasVerticalAlign; /* REM */ 
		bool hasBackgroundImage; /* REM */ 
		bool hasOpacity; /* REM */ 
		bool hasVisible; /* REM */ 
		bool hasPosition; /* REM */ 
		bool hasZIndex; /* REM */ 
		bool hasTransform; /* REM */ 
		bool hasOverflowY; /* REM */ 
		bool hasOverflowX; /* REM */ 
		bool hasFloat; /* REM */ 
		bool hasLetterSpacing; /* REM */ 
		bool hasLineHeight; /* REM */ 
		bool hasDisplay; /* REM */ 
		bool hasColor; /* REM */ 
		bool hasBackgroundColor; /* REM */ 
		bool hasFontFamily; /* REM */ 
		bool hasFontSize; /* REM */ 
		bool hasPropertiesToCascade; /* REM */ 
		bool cascadeAll; /* REM */ 
		Array< bool > propertiesToCascade; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CascadeManager */ 
