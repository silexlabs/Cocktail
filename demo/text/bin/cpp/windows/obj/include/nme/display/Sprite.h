#ifndef INCLUDED_nme_display_Sprite
#define INCLUDED_nme_display_Sprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
namespace display{


class Sprite_obj : public ::nme::display::DisplayObjectContainer_obj{
	public:
		typedef ::nme::display::DisplayObjectContainer_obj super;
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
		::String __ToString() const { return HX_CSTRING("Sprite"); }

		bool buttonMode; /* REM */ 
		bool useHandCursor; /* REM */ 
		virtual ::String nmeGetType( );
		Dynamic nmeGetType_dyn();

		virtual Void startDrag( Dynamic lockCenter,::nme::geom::Rectangle bounds);
		Dynamic startDrag_dyn();

		virtual Void stopDrag( );
		Dynamic stopDrag_dyn();

};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Sprite */ 
