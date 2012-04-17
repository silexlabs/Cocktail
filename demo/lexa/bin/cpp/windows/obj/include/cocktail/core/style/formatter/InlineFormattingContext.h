#ifndef INCLUDED_cocktail_core_style_formatter_InlineFormattingContext
#define INCLUDED_cocktail_core_style_formatter_InlineFormattingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/formatter/FormattingContext.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InlineBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,WhiteSpace)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,InlineFormattingContext)
namespace cocktail{
namespace core{
namespace style{
namespace formatter{


class InlineFormattingContext_obj : public ::cocktail::core::style::formatter::FormattingContext_obj{
	public:
		typedef ::cocktail::core::style::formatter::FormattingContext_obj super;
		typedef InlineFormattingContext_obj OBJ_;
		InlineFormattingContext_obj();
		Void __construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);

	public:
		static hx::ObjectPtr< InlineFormattingContext_obj > __new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineFormattingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineFormattingContext"); }

		Array< ::cocktail::core::renderer::ElementRenderer > _elementsInLineBox; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > _unbreakableLineBoxElements; /* REM */ 
		int _unbreakableWidth; /* REM */ 
		Dynamic _currentInlineBoxesData; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext);
		Dynamic doFormat_dyn();

		virtual int getRemainingLineWidth( );
		Dynamic getRemainingLineWidth_dyn();

		virtual Void insertEmbeddedElement( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertEmbeddedElement_dyn();

		virtual Void insertFormattingContextRootElement( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertFormattingContextRootElement_dyn();

		virtual Void insertContainerElement( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertContainerElement_dyn();

		virtual Void insertText( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertText_dyn();

		virtual Void insertSpace( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic insertSpace_dyn();

		virtual Void insertHorizontalOffset( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertHorizontalOffset_dyn();

		virtual Void insertTab( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic insertTab_dyn();

		virtual Void insertLineFeed( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertLineFeed_dyn();

		virtual Void insertBreakOpportunity( bool forced,Dynamic isLastLine);
		Dynamic insertBreakOpportunity_dyn();

		virtual Void addWidth( int width);
		Dynamic addWidth_dyn();

		virtual bool shouldTabBeConvertedToSpace( ::cocktail::core::style::WhiteSpace whiteSpace);
		Dynamic shouldTabBeConvertedToSpace_dyn();

		virtual bool isLineFeedAllowed( ::cocktail::core::style::WhiteSpace whiteSpace);
		Dynamic isLineFeedAllowed_dyn();

		virtual bool shouldInsertSpace( ::cocktail::core::style::WhiteSpace whiteSpace,bool isNexElementALineFeed);
		Dynamic shouldInsertSpace_dyn();

		virtual bool isCollapsed( ::cocktail::core::renderer::ElementRenderer lastInsertedElement,::cocktail::core::style::WhiteSpace whiteSpace);
		Dynamic isCollapsed_dyn();

		virtual Dynamic getParentInlineBoxesData( ::cocktail::core::renderer::InlineBoxRenderer parent);
		Dynamic getParentInlineBoxesData_dyn();

		virtual Void startNewLine( int elementWidth,bool isLastLine);
		Dynamic startNewLine_dyn();

		virtual Void removeSpaces( );
		Dynamic removeSpaces_dyn();

		virtual int alignLineBox( bool isLastLine);
		Dynamic alignLineBox_dyn();

		virtual Void alignLeft( int flowX);
		Dynamic alignLeft_dyn();

		virtual Void alignCenter( int flowX,int remainingSpace);
		Dynamic alignCenter_dyn();

		virtual Void alignRight( int flowX,int remainingSpace);
		Dynamic alignRight_dyn();

		virtual Void alignJustify( int flowX,int remainingSpace);
		Dynamic alignJustify_dyn();

		virtual int computeLineBoxHeight( );
		Dynamic computeLineBoxHeight_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter

#endif /* INCLUDED_cocktail_core_style_formatter_InlineFormattingContext */ 
