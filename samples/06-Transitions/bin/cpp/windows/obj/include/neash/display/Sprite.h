#ifndef INCLUDED_neash_display_Sprite
#define INCLUDED_neash_display_Sprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace display{


class Sprite_obj : public ::neash::display::DisplayObjectContainer_obj{
	public:
		typedef ::neash::display::DisplayObjectContainer_obj super;
		typedef Sprite_obj OBJ_;
		Sprite_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Sprite_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Sprite"); }

		virtual Void stopDrag( );
		Dynamic stopDrag_dyn();

		virtual Void startDrag( hx::Null< bool >  lockCenter,::neash::geom::Rectangle bounds);
		Dynamic startDrag_dyn();

		virtual ::String nmeGetType( );
		Dynamic nmeGetType_dyn();

		bool useHandCursor; /* REM */ 
		bool buttonMode; /* REM */ 
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Sprite */ 
