#ifndef INCLUDED_cocktail_core_style_formatter_BlockFormattingContext
#define INCLUDED_cocktail_core_style_formatter_BlockFormattingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/formatter/FormattingContext.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,BlockFormattingContext)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
namespace cocktail{
namespace core{
namespace style{
namespace formatter{


class BlockFormattingContext_obj : public ::cocktail::core::style::formatter::FormattingContext_obj{
	public:
		typedef ::cocktail::core::style::formatter::FormattingContext_obj super;
		typedef BlockFormattingContext_obj OBJ_;
		BlockFormattingContext_obj();
		Void __construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);

	public:
		static hx::ObjectPtr< BlockFormattingContext_obj > __new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlockFormattingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlockFormattingContext"); }

		virtual Void doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext);
		Dynamic doFormat_dyn();

		virtual Void doFormat2( ::cocktail::core::renderer::ElementRenderer elementRenderer,int concatenatedX);
		Dynamic doFormat2_dyn();

		virtual int getCollapsedMarginBottom( ::cocktail::core::renderer::ElementRenderer child);
		Dynamic getCollapsedMarginBottom_dyn();

		virtual Void insertFloat( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic insertFloat_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter

#endif /* INCLUDED_cocktail_core_style_formatter_BlockFormattingContext */ 
