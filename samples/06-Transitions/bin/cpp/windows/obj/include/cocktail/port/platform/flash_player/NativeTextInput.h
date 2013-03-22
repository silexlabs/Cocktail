#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#define INCLUDED_cocktail_port_platform_flash_player_NativeTextInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/NativeTextInputBase.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeTextInput)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,text,TextField)
HX_DECLARE_CLASS2(neash,text,TextFormat)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class NativeTextInput_obj : public ::cocktail::port::base::NativeTextInputBase_obj{
	public:
		typedef ::cocktail::port::base::NativeTextInputBase_obj super;
		typedef NativeTextInput_obj OBJ_;
		NativeTextInput_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< NativeTextInput_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeTextInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeTextInput"); }

		virtual Float get_letterSpacing( );

		virtual Float set_letterSpacing( Float value);

		virtual int set_maxLength( int value);

		virtual ::String set_value( ::String textValue);

		virtual ::String get_value( );

		virtual ::String get_fontFamily( );

		virtual ::String set_fontFamily( ::String value);

		virtual int get_color( );

		virtual int set_color( int value);

		virtual bool set_bold( bool value);

		virtual bool get_bold( );

		virtual bool get_italic( );

		virtual bool set_italic( bool value);

		virtual Float get_fontSize( );

		virtual Float set_fontSize( Float value);

		virtual ::cocktail::core::geom::RectangleVO set_clipRect( ::cocktail::core::geom::RectangleVO value);

		virtual ::cocktail::core::geom::RectangleVO get_clipRect( );

		virtual ::cocktail::core::geom::RectangleVO set_viewport( ::cocktail::core::geom::RectangleVO value);

		virtual ::cocktail::core::geom::RectangleVO get_viewport( );

		virtual Void updateTextFormat( );
		Dynamic updateTextFormat_dyn();

		virtual Void blur( );

		virtual Void focus( );

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicContext);

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicContext);

		::neash::display::Sprite _mask; /* REM */ 
		::neash::text::TextFormat _textFormat; /* REM */ 
		::neash::text::TextField _textField; /* REM */ 
		static ::String SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_GENERIC_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_FLASH_FONT_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_NativeTextInput */ 
