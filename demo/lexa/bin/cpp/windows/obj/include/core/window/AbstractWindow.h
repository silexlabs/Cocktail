#ifndef INCLUDED_core_window_AbstractWindow
#define INCLUDED_core_window_AbstractWindow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/event/IEventTarget.h>
HX_DECLARE_CLASS2(core,dom,Document)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,window,AbstractWindow)
namespace core{
namespace window{


class AbstractWindow_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractWindow_obj OBJ_;
		AbstractWindow_obj();
		Void __construct(::core::dom::Document document);

	public:
		static hx::ObjectPtr< AbstractWindow_obj > __new(::core::dom::Document document);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractWindow_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::core::event::IEventTarget_obj *()
			{ return new ::core::event::IEventTarget_delegate_< AbstractWindow_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("AbstractWindow"); }

		Dynamic _onResize; /* REM */ 
	Dynamic &_onResize_dyn() { return _onResize;}
		Dynamic onResize; /* REM */ 
	Dynamic &onResize_dyn() { return onResize;}
		::core::dom::Document _document; /* REM */ 
		::core::dom::Document document; /* REM */ 
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

		virtual ::core::dom::Document get_document( );
		Dynamic get_document_dyn();

};

} // end namespace core
} // end namespace window

#endif /* INCLUDED_core_window_AbstractWindow */ 
