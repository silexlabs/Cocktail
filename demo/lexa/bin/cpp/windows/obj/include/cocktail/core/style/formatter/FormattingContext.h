#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#define INCLUDED_cocktail_core_style_formatter_FormattingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,Clear)
HX_DECLARE_CLASS4(cocktail,core,style,floats,FloatsManager)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
namespace cocktail{
namespace core{
namespace style{
namespace formatter{


class FormattingContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FormattingContext_obj OBJ_;
		FormattingContext_obj();
		Void __construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);

	public:
		static hx::ObjectPtr< FormattingContext_obj > __new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FormattingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FormattingContext"); }

		::cocktail::core::renderer::BlockBoxRenderer _formattingContextRoot; /* REM */ 
		::cocktail::core::style::floats::FloatsManager _floatsManager; /* REM */ 
		Dynamic _formattingContextData; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > _elementsInFormattingContext; /* REM */ 
		::cocktail::core::renderer::ElementRenderer _lastInsertedElement; /* REM */ 
		int maxWidth; /* REM */ 
		bool _layOutLastLine; /* REM */ 
		virtual Void initFormattingContextData( );
		Dynamic initFormattingContextData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void insertElement( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertElement_dyn();

		virtual Void format( );
		Dynamic format_dyn();

		virtual Dynamic getStaticPosition( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic getStaticPosition_dyn();

		virtual int getChildrenHeight( ::cocktail::core::renderer::FlowBoxRenderer elementRenderer);
		Dynamic getChildrenHeight_dyn();

		virtual Dynamic getBounds( Array< ::cocktail::core::renderer::ElementRenderer > elements);
		Dynamic getBounds_dyn();

		virtual Void doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext);
		Dynamic doFormat_dyn();

		virtual Void doInsertElement( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic doInsertElement_dyn();

		virtual Array< ::cocktail::core::renderer::ElementRenderer > getChildElementRenderers( ::cocktail::core::renderer::FlowBoxRenderer elementRenderer);
		Dynamic getChildElementRenderers_dyn();

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

		virtual Void insertFloat( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertFloat_dyn();

		virtual Void clearFloat( ::cocktail::core::style::Clear clear);
		Dynamic clearFloat_dyn();

		virtual Void removeFloats( );
		Dynamic removeFloats_dyn();

		virtual bool isNextElementALineFeed( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext,int currentIndex);
		Dynamic isNextElementALineFeed_dyn();

		virtual int getMaxWidth( );
		Dynamic getMaxWidth_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter

#endif /* INCLUDED_cocktail_core_style_formatter_FormattingContext */ 
