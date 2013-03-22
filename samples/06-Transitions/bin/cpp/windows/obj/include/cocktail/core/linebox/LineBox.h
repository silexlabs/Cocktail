#ifndef INCLUDED_cocktail_core_linebox_LineBox
#define INCLUDED_cocktail_core_linebox_LineBox

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,LineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace linebox{


class LineBox_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LineBox_obj OBJ_;
		LineBox_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float availableWidth,bool isFirstLine,::cocktail::core::layout::LayoutStateValue layoutState);

	public:
		static hx::ObjectPtr< LineBox_obj > __new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float availableWidth,bool isFirstLine,::cocktail::core::layout::LayoutStateValue layoutState);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LineBox_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LineBox"); }

		virtual Float getAlignedSubTreeHeight( ::cocktail::core::linebox::InlineBox inlineBox,Float alignedSubTreeHeight,Float addedY,bool includeChildTopAndBottomInlineBoxes);
		Dynamic getAlignedSubTreeHeight_dyn();

		virtual bool isBottomAligned( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic isBottomAligned_dyn();

		virtual bool isTopAligned( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic isTopAligned_dyn();

		virtual bool isTopOrBottomAligned( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic isTopOrBottomAligned_dyn();

		virtual Void getLineBoxHeight( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::geom::RectangleVO lineBoxBounds,Float addedY);
		Dynamic getLineBoxHeight_dyn();

		virtual Void applyMinimumTop( ::cocktail::core::linebox::InlineBox inlineBox,Float minimumTop);
		Dynamic applyMinimumTop_dyn();

		virtual Float getMinimumTop( ::cocktail::core::linebox::InlineBox inlineBox,Float minimumTop);
		Dynamic getMinimumTop_dyn();

		virtual Void updateOffsetFromLineBox( ::cocktail::core::linebox::InlineBox inlineBox,Float lineBoxHeight,Float addedY);
		Dynamic updateOffsetFromLineBox_dyn();

		virtual Void updateOffsetFromParentInlineBox( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic updateOffsetFromParentInlineBox_dyn();

		virtual Void updateInlineBoxBounds( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic updateInlineBoxBounds_dyn();

		virtual Void updateInlineBoxesBounds( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic updateInlineBoxesBounds_dyn();

		virtual Float alignInlineBoxesVertically( );
		Dynamic alignInlineBoxesVertically_dyn();

		virtual Void alignJustify( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox,int spacesInLine);
		Dynamic alignJustify_dyn();

		virtual Float alignRight( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic alignRight_dyn();

		virtual Float alignCenter( Float x,Float remainingSpace,::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic alignCenter_dyn();

		virtual Float alignLeft( Float x,::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic alignLeft_dyn();

		virtual Float alignInlineBoxesHorizontally( ::cocktail::core::linebox::InlineBox rootInlineBox,bool isLastLine,Float concatenatedLength);
		Dynamic alignInlineBoxesHorizontally_dyn();

		virtual bool isEmptyLineBox( ::cocktail::core::linebox::InlineBox rootInlineBox);
		Dynamic isEmptyLineBox_dyn();

		virtual bool getTrailingSpacesWidth( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic getTrailingSpacesWidth_dyn();

		virtual bool removeTrailingSpaces( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic removeTrailingSpaces_dyn();

		virtual Void layout( bool isLastLine,::cocktail::core::linebox::InlineBox parentInlineBox);
		Dynamic layout_dyn();

		virtual bool introduceBreakOpportunity( ::cocktail::core::linebox::InlineBox inlineBox);
		Dynamic introduceBreakOpportunity_dyn();

		virtual Void addUnbreakableInlineBoxesToLineBox( ::cocktail::core::linebox::InlineBox parentInlineBox);
		Dynamic addUnbreakableInlineBoxesToLineBox_dyn();

		virtual bool insert( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::linebox::InlineBox parentInlineBox,bool force);
		Dynamic insert_dyn();

		virtual bool widthCanFit( Float width);
		Dynamic widthCanFit_dyn();

		virtual Void addUnbreakableWidth( Float width);
		Dynamic addUnbreakableWidth_dyn();

		Float _trailingSpaceWidth; /* REM */ 
		::cocktail::core::layout::LayoutStateValue _layoutState; /* REM */ 
		bool _firstInlineBoxInserted; /* REM */ 
		int _spacesNumber; /* REM */ 
		::cocktail::core::renderer::ElementRenderer _elementRenderer; /* REM */ 
		bool _isFirstLine; /* REM */ 
		::cocktail::core::geom::RectangleVO bounds; /* REM */ 
		Float _availableWidth; /* REM */ 
		Float _addedWidth; /* REM */ 
		::cocktail::core::linebox::InlineBox rootInlineBox; /* REM */ 
		int unbreakableWidth; /* REM */ 
		Array< ::cocktail::core::linebox::InlineBox > _unbreakableInlineBoxes; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _childBounds; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _lineBoxesBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace linebox

#endif /* INCLUDED_cocktail_core_linebox_LineBox */ 
