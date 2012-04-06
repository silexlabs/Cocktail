#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#define INCLUDED_cocktail_core_window_AbstractWindow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/IEventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,window,AbstractWindow)
namespace cocktail{
namespace core{
namespace window{


class AbstractWindow_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractWindow_obj OBJ_;
		AbstractWindow_obj();
		Void __construct(::cocktail::core::dom::Document document);

	public:
		static hx::ObjectPtr< AbstractWindow_obj > __new(::cocktail::core::dom::Document document);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractWindow_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::cocktail::core::event::IEventTarget_obj *()
			{ return new ::cocktail::core::event::IEventTarget_delegate_< AbstractWindow_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("AbstractWindow"); }

		Dynamic _onResize; /* REM */ 
	Dynamic &_onResize_dyn() { return _onResize;}
		Dynamic onResize; /* REM */ 
	Dynamic &onResize_dyn() { return onResize;}
		::cocktail::core::dom::Document _document; /* REM */ 
		::cocktail::core::dom::Document document; /* REM */ 
		int innerHeight; /* REM */ 
		int innerWidth; /* REM */ 
		virtual Dynamic set_onResize( Dynamic value);
		Dynamic set_onResize_dyn();

		virtual Dynamic get_onResize( );
		Dynamic get_onResize_dyn();

		virtual int get_innerHeight( );
		Dynamic get_innerHeight_dyn();

		virtual int get_innerWidth( );
		Dynamic get_innerWidth_dyn();

		virtual ::cocktail::core::dom::Document get_document( );
		Dynamic get_document_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace window

#endif /* INCLUDED_cocktail_core_window_AbstractWindow */ 
