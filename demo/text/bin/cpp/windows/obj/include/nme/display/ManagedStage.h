#ifndef INCLUDED_nme_display_ManagedStage
#define INCLUDED_nme_display_ManagedStage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Stage.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,ManagedStage)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{
namespace display{


class ManagedStage_obj : public ::nme::display::Stage_obj{
	public:
		typedef ::nme::display::Stage_obj super;
		typedef ManagedStage_obj OBJ_;
		ManagedStage_obj();
		Void __construct(int inWidth,int inHeight);

	public:
		static hx::ObjectPtr< ManagedStage_obj > __new(int inWidth,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ManagedStage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ManagedStage"); }

		Dynamic beginRender;
		inline Dynamic &beginRender_dyn() {return beginRender; }

		Dynamic endRender;
		inline Dynamic &endRender_dyn() {return endRender; }

		virtual double nmeDoProcessStageEvent( Dynamic inEvent);
		Dynamic nmeDoProcessStageEvent_dyn();

		virtual Void nmeRender( bool inSendEnterFrame);
		Dynamic nmeRender_dyn();

		virtual Void pumpEvent( Dynamic inEvent);
		Dynamic pumpEvent_dyn();

		virtual Void resize( int inWidth,int inHeight);
		Dynamic resize_dyn();

		virtual Void sendQuit( );
		Dynamic sendQuit_dyn();

		Dynamic setNextWake;
		inline Dynamic &setNextWake_dyn() {return setNextWake; }

		static int etUnknown; /* REM */ 
		static int etKeyDown; /* REM */ 
		static int etChar; /* REM */ 
		static int etKeyUp; /* REM */ 
		static int etMouseMove; /* REM */ 
		static int etMouseDown; /* REM */ 
		static int etMouseClick; /* REM */ 
		static int etMouseUp; /* REM */ 
		static int etResize; /* REM */ 
		static int etPoll; /* REM */ 
		static int etQuit; /* REM */ 
		static int etFocus; /* REM */ 
		static int etShouldRotate; /* REM */ 
		static int etDestroyHandler; /* REM */ 
		static int etRedraw; /* REM */ 
		static int etTouchBegin; /* REM */ 
		static int etTouchMove; /* REM */ 
		static int etTouchEnd; /* REM */ 
		static int etTouchTap; /* REM */ 
		static int etChange; /* REM */ 
		static int efLeftDown; /* REM */ 
		static int efShiftDown; /* REM */ 
		static int efCtrlDown; /* REM */ 
		static int efAltDown; /* REM */ 
		static int efCommandDown; /* REM */ 
		static int efMiddleDown; /* REM */ 
		static int efRightDown; /* REM */ 
		static int efLocationRight; /* REM */ 
		static int efPrimaryTouch; /* REM */ 
		static Dynamic nme_managed_stage_create; /* REM */ 
	Dynamic &nme_managed_stage_create_dyn() { return nme_managed_stage_create;}
		static Dynamic nme_managed_stage_pump_event; /* REM */ 
	Dynamic &nme_managed_stage_pump_event_dyn() { return nme_managed_stage_pump_event;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_ManagedStage */ 
