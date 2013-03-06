#ifndef INCLUDED_cocktail_core_renderer_AnonymousBlockBoxRenderer
#define INCLUDED_cocktail_core_renderer_AnonymousBlockBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BlockBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,AnonymousBlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace renderer{


class AnonymousBlockBoxRenderer_obj : public ::cocktail::core::renderer::BlockBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BlockBoxRenderer_obj super;
		typedef AnonymousBlockBoxRenderer_obj OBJ_;
		AnonymousBlockBoxRenderer_obj();
		Void __construct(::cocktail::core::dom::Document document);

	public:
		static hx::ObjectPtr< AnonymousBlockBoxRenderer_obj > __new(::cocktail::core::dom::Document document);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AnonymousBlockBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AnonymousBlockBoxRenderer"); }

		virtual bool isInlineLevel( );

		virtual bool createOwnLayer( );

		virtual bool isAnonymousBlockBox( );

		virtual bool isPositioned( );

		virtual Void removeChild( Dynamic _tmp_oldChild);

		static ::cocktail::core::html::HTMLElement _node; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_AnonymousBlockBoxRenderer */ 
