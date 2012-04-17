#ifndef INCLUDED_hxtml_Browser
#define INCLUDED_hxtml_Browser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(hxtml,Browser)
HX_DECLARE_CLASS1(hxtml,IStyleProxy)
namespace hxtml{


class Browser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Browser_obj OBJ_;
		Browser_obj();
		Void __construct(Dynamic createElement,Dynamic createTextNode,Dynamic appendChild,Dynamic setAttribute,Dynamic invalidate,::hxtml::IStyleProxy styleProxy);

	public:
		static hx::ObjectPtr< Browser_obj > __new(Dynamic createElement,Dynamic createTextNode,Dynamic appendChild,Dynamic setAttribute,Dynamic invalidate,::hxtml::IStyleProxy styleProxy);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Browser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Browser"); }

		::String html; /* REM */ 
		Dynamic domRoot; /* REM */ 
		::Hash ids; /* REM */ 
		bool invalid; /* REM */ 
		Dynamic createElement; /* REM */ 
	Dynamic &createElement_dyn() { return createElement;}
		Dynamic createTextNode; /* REM */ 
	Dynamic &createTextNode_dyn() { return createTextNode;}
		Dynamic appendChild; /* REM */ 
	Dynamic &appendChild_dyn() { return appendChild;}
		Dynamic setAttribute; /* REM */ 
	Dynamic &setAttribute_dyn() { return setAttribute;}
		Dynamic invalidate; /* REM */ 
	Dynamic &invalidate_dyn() { return invalidate;}
		::hxtml::IStyleProxy styleProxy; /* REM */ 
		virtual Void _register( ::String id,Dynamic d);
		Dynamic _register_dyn();

		virtual Void setHtml( ::String data);
		Dynamic setHtml_dyn();

		virtual Void refresh( );
		Dynamic refresh_dyn();

		virtual Dynamic getById( ::String id);
		Dynamic getById_dyn();

		virtual Dynamic make( ::Xml x);
		Dynamic make_dyn();

};

} // end namespace hxtml

#endif /* INCLUDED_hxtml_Browser */ 
