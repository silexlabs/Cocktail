#ifndef INCLUDED_core_style_formatter_InlineFormattingContext
#define INCLUDED_core_style_formatter_InlineFormattingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/formatter/FormattingContext.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,InlineBoxRenderer)
HX_DECLARE_CLASS2(core,style,WhiteSpace)
HX_DECLARE_CLASS3(core,style,formatter,FormattingContext)
HX_DECLARE_CLASS3(core,style,formatter,InlineFormattingContext)
namespace core{
namespace style{
namespace formatter{


class InlineFormattingContext_obj : public ::core::style::formatter::FormattingContext_obj{
	public:
		typedef ::core::style::formatter::FormattingContext_obj super;
		typedef InlineFormattingContext_obj OBJ_;
		InlineFormattingContext_obj();
		Void __construct(::core::renderer::BlockBoxRenderer formattingContextRoot);

	public:
		static hx::ObjectPtr< InlineFormattingContext_obj > __new(::core::renderer::BlockBoxRenderer formattingContextRoot);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineFormattingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineFormattingContext"); }

		Array< ::core::renderer::ElementRenderer > _elementsInLineBox; /* REM */ 
		Array< ::core::renderer::ElementRenderer > _unbreakableLineBoxElements; /* REM */ 
		int _unbreakableWidth; /* REM */ 
		Dynamic _currentInlineBoxesData; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void doFormat( Array< ::core::renderer::ElementRenderer > elementsInFormattingContext);
		Dynamic doFormat_dyn();

		virtual int getRemainingLineWidth( );
		Dynamic getRemainingLineWidth_dyn();

		virtual Void insertEmbeddedElement( ::core::renderer::ElementRenderer element);
		Dynamic insertEmbeddedElement_dyn();

		virtual Void insertFormattingContextRootElement( ::core::renderer::ElementRenderer element);
		Dynamic insertFormattingContextRootElement_dyn();

		virtual Void insertContainerElement( ::core::renderer::ElementRenderer element);
		Dynamic insertContainerElement_dyn();

		virtual Void insertText( ::core::renderer::ElementRenderer element);
		Dynamic insertText_dyn();

		virtual Void insertSpace( ::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic insertSpace_dyn();

		virtual Void insertHorizontalOffset( ::core::renderer::ElementRenderer element);
		Dynamic insertHorizontalOffset_dyn();

		virtual Void insertTab( ::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic insertTab_dyn();

		virtual Void insertLineFeed( ::core::renderer::ElementRenderer element);
		Dynamic insertLineFeed_dyn();

		virtual Void insertBreakOpportunity( bool forced,Dynamic isLastLine);
		Dynamic insertBreakOpportunity_dyn();

		virtual Void addWidth( int width);
		Dynamic addWidth_dyn();

		virtual bool shouldTabBeConvertedToSpace( ::core::style::WhiteSpace whiteSpace);
		Dynamic shouldTabBeConvertedToSpace_dyn();

		virtual bool isLineFeedAllowed( ::core::style::WhiteSpace whiteSpace);
		Dynamic isLineFeedAllowed_dyn();

		virtual bool shouldInsertSpace( ::core::style::WhiteSpace whiteSpace,bool isNexElementALineFeed);
		Dynamic shouldInsertSpace_dyn();

		virtual bool isCollapsed( ::core::renderer::ElementRenderer lastInsertedElement,::core::style::WhiteSpace whiteSpace);
		Dynamic isCollapsed_dyn();

		virtual Dynamic getParentInlineBoxesData( ::core::renderer::InlineBoxRenderer parent);
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

} // end namespace core
} // end namespace style
} // end namespace formatter

#endif /* INCLUDED_core_style_formatter_InlineFormattingContext */ 
