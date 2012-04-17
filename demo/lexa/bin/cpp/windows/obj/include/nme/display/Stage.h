#ifndef INCLUDED_nme_display_Stage
#define INCLUDED_nme_display_Stage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,display,StageAlign)
HX_DECLARE_CLASS2(nme,display,StageDisplayState)
HX_DECLARE_CLASS2(nme,display,StageQuality)
HX_DECLARE_CLASS2(nme,display,StageScaleMode)
HX_DECLARE_CLASS2(nme,display,TouchInfo)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
namespace display{


class Stage_obj : public ::nme::display::DisplayObjectContainer_obj{
	public:
		typedef ::nme::display::DisplayObjectContainer_obj super;
		typedef Stage_obj OBJ_;
		Stage_obj();
		Void __construct(Dynamic inHandle,int inWidth,int inHeight);

	public:
		static hx::ObjectPtr< Stage_obj > __new(Dynamic inHandle,int inWidth,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Stage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Stage"); }

		bool active; /* REM */ 
		::nme::display::StageAlign align; /* REM */ 
		::nme::display::StageDisplayState displayState; /* REM */ 
		double dpiScale; /* REM */ 
		::nme::display::InteractiveObject focus; /* REM */ 
		double frameRate; /* REM */ 
		bool isOpenGL; /* REM */ 
		Dynamic onKey; /* REM */ 
	Dynamic &onKey_dyn() { return onKey;}
		Dynamic onQuit; /* REM */ 
	Dynamic &onQuit_dyn() { return onQuit;}
		bool pauseWhenDeactivated; /* REM */ 
		::nme::display::StageQuality quality; /* REM */ 
		Dynamic renderRequest; /* REM */ 
	Dynamic &renderRequest_dyn() { return renderRequest;}
		::nme::display::StageScaleMode scaleMode; /* REM */ 
		bool stageFocusRect; /* REM */ 
		int stageHeight; /* REM */ 
		int stageWidth; /* REM */ 
		::IntHash nmeJoyAxisData; /* REM */ 
		::nme::geom::Rectangle nmeDragBounds; /* REM */ 
		::nme::display::Sprite nmeDragObject; /* REM */ 
		double nmeDragOffsetX; /* REM */ 
		double nmeDragOffsetY; /* REM */ 
		Array< ::nme::display::InteractiveObject > nmeFocusOverObjects; /* REM */ 
		double nmeFramePeriod; /* REM */ 
		bool nmeInvalid; /* REM */ 
		double nmeLastClickTime; /* REM */ 
		Array< ::nme::display::InteractiveObject > nmeLastDown; /* REM */ 
		double nmeLastRender; /* REM */ 
		Array< ::nme::display::InteractiveObject > nmeMouseOverObjects; /* REM */ 
		::IntHash nmeTouchInfo; /* REM */ 
		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void nmeCheckFocusInOuts( Dynamic inEvent,Array< ::nme::display::InteractiveObject > inStack);
		Dynamic nmeCheckFocusInOuts_dyn();

		virtual bool nmeCheckInOuts( ::nme::events::MouseEvent inEvent,Array< ::nme::display::InteractiveObject > inStack,::nme::display::TouchInfo touchInfo);
		Dynamic nmeCheckInOuts_dyn();

		virtual Void nmeCheckRender( );
		Dynamic nmeCheckRender_dyn();

		virtual double nmeDoProcessStageEvent( Dynamic inEvent);
		Dynamic nmeDoProcessStageEvent_dyn();

		virtual Void dummyTrace( );
		Dynamic dummyTrace_dyn();

		virtual Dynamic nmeProcessStageEvent( Dynamic inEvent);
		Dynamic nmeProcessStageEvent_dyn();

		virtual Void nmeDrag( ::nme::geom::Point inMouse);
		Dynamic nmeDrag_dyn();

		virtual ::nme::display::Stage nmeGetStage( );
		Dynamic nmeGetStage_dyn();

		virtual double nmeNextFrameDue( double inOtherTimers);
		Dynamic nmeNextFrameDue_dyn();

		virtual Void nmeOnChange( Dynamic inEvent);
		Dynamic nmeOnChange_dyn();

		virtual Void nmeOnFocus( Dynamic inEvent);
		Dynamic nmeOnFocus_dyn();

		virtual Void nmeOnJoystick( Dynamic inEvent,::String inType);
		Dynamic nmeOnJoystick_dyn();

		virtual Void nmeOnKey( Dynamic inEvent,::String inType);
		Dynamic nmeOnKey_dyn();

		virtual Void nmeOnMouse( Dynamic inEvent,::String inType,bool inFromMouse);
		Dynamic nmeOnMouse_dyn();

		virtual Void nmeOnResize( double inW,double inH);
		Dynamic nmeOnResize_dyn();

		virtual Void nmeOnTouch( Dynamic inEvent,::String inType,::nme::display::TouchInfo touchInfo);
		Dynamic nmeOnTouch_dyn();

		virtual Void nmePollTimers( );
		Dynamic nmePollTimers_dyn();

		virtual Void nmeRender( bool inSendEnterFrame);
		Dynamic nmeRender_dyn();

		virtual Void nmeSetActive( bool inActive);
		Dynamic nmeSetActive_dyn();

		virtual Void nmeStartDrag( ::nme::display::Sprite sprite,bool lockCenter,::nme::geom::Rectangle bounds);
		Dynamic nmeStartDrag_dyn();

		virtual Void nmeStopDrag( ::nme::display::Sprite sprite);
		Dynamic nmeStopDrag_dyn();

		virtual double nmeUpdateNextWake( );
		Dynamic nmeUpdateNextWake_dyn();

		virtual Void showCursor( bool inShow);
		Dynamic showCursor_dyn();

		virtual ::nme::display::StageAlign nmeGetAlign( );
		Dynamic nmeGetAlign_dyn();

		virtual ::nme::display::StageAlign nmeSetAlign( ::nme::display::StageAlign inMode);
		Dynamic nmeSetAlign_dyn();

		virtual ::nme::display::StageDisplayState nmeGetDisplayState( );
		Dynamic nmeGetDisplayState_dyn();

		virtual ::nme::display::StageDisplayState nmeSetDisplayState( ::nme::display::StageDisplayState inState);
		Dynamic nmeSetDisplayState_dyn();

		virtual double nmeGetDPIScale( );
		Dynamic nmeGetDPIScale_dyn();

		virtual ::nme::display::InteractiveObject nmeGetFocus( );
		Dynamic nmeGetFocus_dyn();

		virtual ::nme::display::InteractiveObject nmeSetFocus( ::nme::display::InteractiveObject inObject);
		Dynamic nmeSetFocus_dyn();

		virtual double nmeSetFrameRate( double inRate);
		Dynamic nmeSetFrameRate_dyn();

		virtual bool nmeIsOpenGL( );
		Dynamic nmeIsOpenGL_dyn();

		virtual ::nme::display::StageQuality nmeGetQuality( );
		Dynamic nmeGetQuality_dyn();

		virtual ::nme::display::StageQuality nmeSetQuality( ::nme::display::StageQuality inQuality);
		Dynamic nmeSetQuality_dyn();

		virtual ::nme::display::StageScaleMode nmeGetScaleMode( );
		Dynamic nmeGetScaleMode_dyn();

		virtual ::nme::display::StageScaleMode nmeSetScaleMode( ::nme::display::StageScaleMode inMode);
		Dynamic nmeSetScaleMode_dyn();

		virtual bool nmeGetStageFocusRect( );
		Dynamic nmeGetStageFocusRect_dyn();

		virtual bool nmeSetStageFocusRect( bool inVal);
		Dynamic nmeSetStageFocusRect_dyn();

		virtual int nmeGetStageHeight( );
		Dynamic nmeGetStageHeight_dyn();

		virtual int nmeGetStageWidth( );
		Dynamic nmeGetStageWidth_dyn();

		static double nmeEarlyWakeup; /* REM */ 
		static int OrientationPortrait; /* REM */ 
		static int OrientationPortraitUpsideDown; /* REM */ 
		static int OrientationLandscapeRight; /* REM */ 
		static int OrientationLandscapeLeft; /* REM */ 
		static int OrientationFaceUp; /* REM */ 
		static int OrientationFaceDown; /* REM */ 
		static int efLeftDown; /* REM */ 
		static int efShiftDown; /* REM */ 
		static int efCtrlDown; /* REM */ 
		static int efAltDown; /* REM */ 
		static int efCommandDown; /* REM */ 
		static int efLocationRight; /* REM */ 
		static int efNoNativeClick; /* REM */ 
		static Array< ::String > nmeMouseChanges; /* REM */ 
		static Array< ::String > nmeTouchChanges; /* REM */ 
		static Array< ::String > sClickEvents; /* REM */ 
		static Array< ::String > sDownEvents; /* REM */ 
		static Array< ::String > sUpEvents; /* REM */ 
		static Dynamic getOrientation;
		static inline Dynamic &getOrientation_dyn() {return getOrientation; }

		static Void setFixedOrientation( int inOrientation);
		static Dynamic setFixedOrientation_dyn();

		static Dynamic shouldRotateInterface;
		static inline Dynamic &shouldRotateInterface_dyn() {return shouldRotateInterface; }

		static Dynamic nme_set_stage_handler; /* REM */ 
	Dynamic &nme_set_stage_handler_dyn() { return nme_set_stage_handler;}
		static Dynamic nme_render_stage; /* REM */ 
	Dynamic &nme_render_stage_dyn() { return nme_render_stage;}
		static Dynamic nme_stage_get_focus_id; /* REM */ 
	Dynamic &nme_stage_get_focus_id_dyn() { return nme_stage_get_focus_id;}
		static Dynamic nme_stage_set_focus; /* REM */ 
	Dynamic &nme_stage_set_focus_dyn() { return nme_stage_set_focus;}
		static Dynamic nme_stage_get_focus_rect; /* REM */ 
	Dynamic &nme_stage_get_focus_rect_dyn() { return nme_stage_get_focus_rect;}
		static Dynamic nme_stage_set_focus_rect; /* REM */ 
	Dynamic &nme_stage_set_focus_rect_dyn() { return nme_stage_set_focus_rect;}
		static Dynamic nme_stage_is_opengl; /* REM */ 
	Dynamic &nme_stage_is_opengl_dyn() { return nme_stage_is_opengl;}
		static Dynamic nme_stage_get_stage_width; /* REM */ 
	Dynamic &nme_stage_get_stage_width_dyn() { return nme_stage_get_stage_width;}
		static Dynamic nme_stage_get_stage_height; /* REM */ 
	Dynamic &nme_stage_get_stage_height_dyn() { return nme_stage_get_stage_height;}
		static Dynamic nme_stage_get_dpi_scale; /* REM */ 
	Dynamic &nme_stage_get_dpi_scale_dyn() { return nme_stage_get_dpi_scale;}
		static Dynamic nme_stage_get_scale_mode; /* REM */ 
	Dynamic &nme_stage_get_scale_mode_dyn() { return nme_stage_get_scale_mode;}
		static Dynamic nme_stage_set_scale_mode; /* REM */ 
	Dynamic &nme_stage_set_scale_mode_dyn() { return nme_stage_set_scale_mode;}
		static Dynamic nme_stage_get_align; /* REM */ 
	Dynamic &nme_stage_get_align_dyn() { return nme_stage_get_align;}
		static Dynamic nme_stage_set_align; /* REM */ 
	Dynamic &nme_stage_set_align_dyn() { return nme_stage_set_align;}
		static Dynamic nme_stage_get_quality; /* REM */ 
	Dynamic &nme_stage_get_quality_dyn() { return nme_stage_get_quality;}
		static Dynamic nme_stage_set_quality; /* REM */ 
	Dynamic &nme_stage_set_quality_dyn() { return nme_stage_set_quality;}
		static Dynamic nme_stage_get_display_state; /* REM */ 
	Dynamic &nme_stage_get_display_state_dyn() { return nme_stage_get_display_state;}
		static Dynamic nme_stage_set_display_state; /* REM */ 
	Dynamic &nme_stage_set_display_state_dyn() { return nme_stage_set_display_state;}
		static Dynamic nme_stage_set_next_wake; /* REM */ 
	Dynamic &nme_stage_set_next_wake_dyn() { return nme_stage_set_next_wake;}
		static Dynamic nme_stage_request_render; /* REM */ 
		static Dynamic nme_stage_show_cursor; /* REM */ 
	Dynamic &nme_stage_show_cursor_dyn() { return nme_stage_show_cursor;}
		static Dynamic nme_stage_set_fixed_orientation; /* REM */ 
	Dynamic &nme_stage_set_fixed_orientation_dyn() { return nme_stage_set_fixed_orientation;}
		static Dynamic nme_stage_get_orientation; /* REM */ 
	Dynamic &nme_stage_get_orientation_dyn() { return nme_stage_get_orientation;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Stage */ 
