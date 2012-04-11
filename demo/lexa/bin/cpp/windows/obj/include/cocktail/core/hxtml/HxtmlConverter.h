#ifndef INCLUDED_cocktail_core_hxtml_HxtmlConverter
#define INCLUDED_cocktail_core_hxtml_HxtmlConverter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,hxtml,HxtmlConverter)
namespace cocktail{
namespace core{
namespace hxtml{


class HxtmlConverter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HxtmlConverter_obj OBJ_;
		HxtmlConverter_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HxtmlConverter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HxtmlConverter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HxtmlConverter"); }

		static ::cocktail::core::dom::Node getNode( ::String htmlString);
		static Dynamic getNode_dyn();

		static Void appendChild( ::cocktail::core::dom::Node parent,::cocktail::core::dom::Node element);
		static Dynamic appendChild_dyn();

		static Void invalidate( );
		static Dynamic invalidate_dyn();

		static Void setAttribute( ::cocktail::core::dom::Node element,::String a,::String v);
		static Dynamic setAttribute_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace hxtml

#endif /* INCLUDED_cocktail_core_hxtml_HxtmlConverter */ 
