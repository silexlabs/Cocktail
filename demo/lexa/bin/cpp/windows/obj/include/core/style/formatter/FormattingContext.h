#ifndef INCLUDED_core_style_formatter_FormattingContext
#define INCLUDED_core_style_formatter_FormattingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,style,Clear)
HX_DECLARE_CLASS3(core,style,floats,FloatsManager)
HX_DECLARE_CLASS3(core,style,formatter,FormattingContext)
namespace core{
namespace style{
namespace formatter{


class FormattingContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FormattingContext_obj OBJ_;
		FormattingContext_obj();
		Void __construct(::core::renderer::BlockBoxRenderer formattingContextRoot);

	public:
		static hx::ObjectPtr< FormattingContext_obj > __new(::core::renderer::BlockBoxRenderer formattingContextRoot);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FormattingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FormattingContext"); }

		::core::renderer::BlockBoxRenderer _formattingContextRoot; /* REM */ 
		::core::style::floats::FloatsManager _floatsManager; /* REM */ 
		Dynamic _formattingContextData; /* REM */ 
		Array< ::core::renderer::ElementRenderer > _elementsInFormattingContext; /* REM */ 
		::core::renderer::ElementRenderer _lastInsertedElement; /* REM */ 
		int maxWidth; /* REM */ 
		bool _layOutLastLine; /* REM */ 
		virtual Void initFormattingContextData( );
		Dynamic initFormattingContextData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void insertElement( ::core::renderer::ElementRenderer element);
		Dynamic insertElement_dyn();

		virtual Void format( );
		Dynamic format_dyn();

		virtual Dynamic getStaticPosition( ::core::renderer::ElementRenderer element);
		Dynamic getStaticPosition_dyn();

		virtual int getChildrenHeight( ::core::renderer::FlowBoxRenderer elementRenderer);
		Dynamic getChildrenHeight_dyn();

		virtual Dynamic getBounds( Array< ::core::renderer::ElementRenderer > elements);
		Dynamic getBounds_dyn();

		virtual Void doFormat( Array< ::core::renderer::ElementRenderer > elementsInFormattingContext);
		Dynamic doFormat_dyn();

		virtual Void doInsertElement( ::core::renderer::ElementRenderer element,bool isNextElementALineFeed);
		Dynamic doInsertElement_dyn();

		virtual Array< ::core::renderer::ElementRenderer > getChildElementRenderers( ::core::renderer::FlowBoxRenderer elementRenderer);
		Dynamic getChildElementRenderers_dyn();

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

		virtual Void insertFloat( ::core::renderer::ElementRenderer element);
		Dynamic insertFloat_dyn();

		virtual Void clearFloat( ::core::style::Clear clear);
		Dynamic clearFloat_dyn();

		virtual Void removeFloats( );
		Dynamic removeFloats_dyn();

		virtual bool isNextElementALineFeed( Array< ::core::renderer::ElementRenderer > elementsInFormattingContext,int currentIndex);
		Dynamic isNextElementALineFeed_dyn();

		virtual int getMaxWidth( );
		Dynamic getMaxWidth_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace formatter

#endif /* INCLUDED_core_style_formatter_FormattingContext */ 
