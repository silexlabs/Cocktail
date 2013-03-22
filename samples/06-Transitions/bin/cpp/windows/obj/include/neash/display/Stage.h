#ifndef INCLUDED_neash_display_Stage
#define INCLUDED_neash_display_Stage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS0(IntHash)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,display,Stage)
HX_DECLARE_CLASS2(neash,display,StageAlign)
HX_DECLARE_CLASS2(neash,display,StageDisplayState)
HX_DECLARE_CLASS2(neash,display,StageQuality)
HX_DECLARE_CLASS2(neash,display,StageScaleMode)
HX_DECLARE_CLASS2(neash,display,TouchInfo)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace display{


class Stage_obj : public ::neash::display::DisplayObjectContainer_obj{
	public:
		typedef ::neash::display::DisplayObjectContainer_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Stage"); }

		virtual int nmeGetStageWidth( );
		Dynamic nmeGetStageWidth_dyn();

		virtual int nmeGetStageHeight( );
		Dynamic nmeGetStageHeight_dyn();

		virtual bool nmeSetStageFocusRect( bool inVal);
		Dynamic nmeSetStageFocusRect_dyn();

		virtual bool nmeGetStageFocusRect( );
		Dynamic nmeGetStageFocusRect_dyn();

		virtual ::neash::display::StageScaleMode nmeSetScaleMode( ::neash::display::StageScaleMode inMode);
		Dynamic nmeSetScaleMode_dyn();

		virtual ::neash::display::StageScaleMode nmeGetScaleMode( );
		Dynamic nmeGetScaleMode_dyn();

		virtual ::neash::display::StageQuality nmeSetQuality( ::neash::display::StageQuality inQuality);
		Dynamic nmeSetQuality_dyn();

		virtual ::neash::display::StageQuality nmeGetQuality( );
		Dynamic nmeGetQuality_dyn();

		virtual bool nmeIsOpenGL( );
		Dynamic nmeIsOpenGL_dyn();

		virtual Float nmeSetFrameRate( Float inRate);
		Dynamic nmeSetFrameRate_dyn();

		virtual ::neash::display::InteractiveObject nmeSetFocus( ::neash::display::InteractiveObject inObject);
		Dynamic nmeSetFocus_dyn();

		virtual ::neash::display::InteractiveObject nmeGetFocus( );
		Dynamic nmeGetFocus_dyn();

		virtual Float nmeGetDPIScale( );
		Dynamic nmeGetDPIScale_dyn();

		virtual ::neash::display::StageDisplayState nmeSetDisplayState( ::neash::display::StageDisplayState inState);
		Dynamic nmeSetDisplayState_dyn();

		virtual ::neash::display::StageDisplayState nmeGetDisplayState( );
		Dynamic nmeGetDisplayState_dyn();

		virtual ::neash::display::StageAlign nmeSetAlign( ::neash::display::StageAlign inMode);
		Dynamic nmeSetAlign_dyn();

		virtual ::neash::display::StageAlign nmeGetAlign( );
		Dynamic nmeGetAlign_dyn();

		virtual Void showCursor( bool inShow);
		Dynamic showCursor_dyn();

		virtual Float nmeUpdateNextWake( );
		Dynamic nmeUpdateNextWake_dyn();

		virtual Void nmeStopDrag( ::neash::display::Sprite sprite);
		Dynamic nmeStopDrag_dyn();

		virtual Void nmeStartDrag( ::neash::display::Sprite sprite,bool lockCenter,::neash::geom::Rectangle bounds);
		Dynamic nmeStartDrag_dyn();

		virtual Void nmeSetActive( bool inActive);
		Dynamic nmeSetActive_dyn();

		virtual Void nmeRender( bool inSendEnterFrame);
		Dynamic nmeRender_dyn();

		virtual Void nmePollTimers( );
		Dynamic nmePollTimers_dyn();

		virtual Void nmeOnTouch( Dynamic inEvent,::String inType,::neash::display::TouchInfo touchInfo);
		Dynamic nmeOnTouch_dyn();

		virtual Void nmeOnResize( Float inW,Float inH);
		Dynamic nmeOnResize_dyn();

		virtual Void nmeOnMouse( Dynamic inEvent,::String inType,bool inFromMouse);
		Dynamic nmeOnMouse_dyn();

		virtual Void nmeOnKey( Dynamic inEvent,::String inType);
		Dynamic nmeOnKey_dyn();

		virtual Void nmeOnJoystick( Dynamic inEvent,::String inType);
		Dynamic nmeOnJoystick_dyn();

		virtual Void nmeOnFocus( Dynamic inEvent);
		Dynamic nmeOnFocus_dyn();

		virtual Void nmeOnChange( Dynamic inEvent);
		Dynamic nmeOnChange_dyn();

		virtual Float nmeNextFrameDue( Float inOtherTimers);
		Dynamic nmeNextFrameDue_dyn();

		virtual ::neash::display::Stage nmeGetStage( );

		virtual Void nmeDrag( ::neash::geom::Point inMouse);
		Dynamic nmeDrag_dyn();

		virtual Dynamic nmeProcessStageEvent( Dynamic inEvent);
		Dynamic nmeProcessStageEvent_dyn();

		virtual Void dummyTrace( );
		Dynamic dummyTrace_dyn();

		virtual Float nmeDoProcessStageEvent( Dynamic inEvent);
		Dynamic nmeDoProcessStageEvent_dyn();

		virtual Void nmeCheckRender( );
		Dynamic nmeCheckRender_dyn();

		virtual bool nmeCheckInOuts( ::neash::events::MouseEvent inEvent,Array< ::neash::display::InteractiveObject > inStack,::neash::display::TouchInfo touchInfo);
		Dynamic nmeCheckInOuts_dyn();

		virtual Void nmeCheckFocusInOuts( Dynamic inEvent,Array< ::neash::display::InteractiveObject > inStack);
		Dynamic nmeCheckFocusInOuts_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		::IntHash nmeTouchInfo; /* REM */ 
		Array< ::neash::display::InteractiveObject > nmeMouseOverObjects; /* REM */ 
		Float nmeLastRender; /* REM */ 
		Array< ::neash::display::InteractiveObject > nmeLastDown; /* REM */ 
		Float nmeLastClickTime; /* REM */ 
		bool nmeInvalid; /* REM */ 
		Float nmeFramePeriod; /* REM */ 
		Array< ::neash::display::InteractiveObject > nmeFocusOverObjects; /* REM */ 
		Float nmeDragOffsetY; /* REM */ 
		Float nmeDragOffsetX; /* REM */ 
		::neash::display::Sprite nmeDragObject; /* REM */ 
		::neash::geom::Rectangle nmeDragBounds; /* REM */ 
		::IntHash nmeJoyAxisData; /* REM */ 
		int stageWidth; /* REM */ 
		int stageHeight; /* REM */ 
		bool stageFocusRect; /* REM */ 
		::neash::display::StageScaleMode scaleMode; /* REM */ 
		Dynamic renderRequest; /* REM */ 
		Dynamic &renderRequest_dyn() { return renderRequest;}
		::neash::display::StageQuality quality; /* REM */ 
		bool pauseWhenDeactivated; /* REM */ 
		Dynamic onQuit; /* REM */ 
		Dynamic &onQuit_dyn() { return onQuit;}
		Dynamic onKey; /* REM */ 
		Dynamic &onKey_dyn() { return onKey;}
		bool isOpenGL; /* REM */ 
		Float frameRate; /* REM */ 
		::neash::display::InteractiveObject focus; /* REM */ 
		Float dpiScale; /* REM */ 
		::neash::display::StageDisplayState displayState; /* REM */ 
		::neash::display::StageAlign align; /* REM */ 
		bool active; /* REM */ 
		static Float nmeEarlyWakeup; /* REM */ 
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

		static Dynamic getNormalOrientation;
		static inline Dynamic &getNormalOrientation_dyn() {return getNormalOrientation; }

		static Void setFixedOrientation( int inOrientation);
		static Dynamic setFixedOrientation_dyn();

		static Dynamic shouldRotateInterface;
		static inline Dynamic &shouldRotateInterface_dyn() {return shouldRotateInterface; }

		static Dynamic nme_set_stage_handler; /* REM */ 
		static Dynamic &nme_set_stage_handler_dyn() { return nme_set_stage_handler;}
		static Dynamic nme_render_stage; /* REM */ 
		static Dynamic &nme_render_stage_dyn() { return nme_render_stage;}
		static Dynamic nme_stage_get_focus_id; /* REM */ 
		static Dynamic &nme_stage_get_focus_id_dyn() { return nme_stage_get_focus_id;}
		static Dynamic nme_stage_set_focus; /* REM */ 
		static Dynamic &nme_stage_set_focus_dyn() { return nme_stage_set_focus;}
		static Dynamic nme_stage_get_focus_rect; /* REM */ 
		static Dynamic &nme_stage_get_focus_rect_dyn() { return nme_stage_get_focus_rect;}
		static Dynamic nme_stage_set_focus_rect; /* REM */ 
		static Dynamic &nme_stage_set_focus_rect_dyn() { return nme_stage_set_focus_rect;}
		static Dynamic nme_stage_is_opengl; /* REM */ 
		static Dynamic &nme_stage_is_opengl_dyn() { return nme_stage_is_opengl;}
		static Dynamic nme_stage_get_stage_width; /* REM */ 
		static Dynamic &nme_stage_get_stage_width_dyn() { return nme_stage_get_stage_width;}
		static Dynamic nme_stage_get_stage_height; /* REM */ 
		static Dynamic &nme_stage_get_stage_height_dyn() { return nme_stage_get_stage_height;}
		static Dynamic nme_stage_get_dpi_scale; /* REM */ 
		static Dynamic &nme_stage_get_dpi_scale_dyn() { return nme_stage_get_dpi_scale;}
		static Dynamic nme_stage_get_scale_mode; /* REM */ 
		static Dynamic &nme_stage_get_scale_mode_dyn() { return nme_stage_get_scale_mode;}
		static Dynamic nme_stage_set_scale_mode; /* REM */ 
		static Dynamic &nme_stage_set_scale_mode_dyn() { return nme_stage_set_scale_mode;}
		static Dynamic nme_stage_get_align; /* REM */ 
		static Dynamic &nme_stage_get_align_dyn() { return nme_stage_get_align;}
		static Dynamic nme_stage_set_align; /* REM */ 
		static Dynamic &nme_stage_set_align_dyn() { return nme_stage_set_align;}
		static Dynamic nme_stage_get_quality; /* REM */ 
		static Dynamic &nme_stage_get_quality_dyn() { return nme_stage_get_quality;}
		static Dynamic nme_stage_set_quality; /* REM */ 
		static Dynamic &nme_stage_set_quality_dyn() { return nme_stage_set_quality;}
		static Dynamic nme_stage_get_display_state; /* REM */ 
		static Dynamic &nme_stage_get_display_state_dyn() { return nme_stage_get_display_state;}
		static Dynamic nme_stage_set_display_state; /* REM */ 
		static Dynamic &nme_stage_set_display_state_dyn() { return nme_stage_set_display_state;}
		static Dynamic nme_stage_set_next_wake; /* REM */ 
		static Dynamic &nme_stage_set_next_wake_dyn() { return nme_stage_set_next_wake;}
		static Dynamic nme_stage_request_render; /* REM */ 
		static Dynamic nme_stage_show_cursor; /* REM */ 
		static Dynamic &nme_stage_show_cursor_dyn() { return nme_stage_show_cursor;}
		static Dynamic nme_stage_set_fixed_orientation; /* REM */ 
		static Dynamic &nme_stage_set_fixed_orientation_dyn() { return nme_stage_set_fixed_orientation;}
		static Dynamic nme_stage_get_orientation; /* REM */ 
		static Dynamic &nme_stage_get_orientation_dyn() { return nme_stage_get_orientation;}
		static Dynamic nme_stage_get_normal_orientation; /* REM */ 
		static Dynamic &nme_stage_get_normal_orientation_dyn() { return nme_stage_get_normal_orientation;}
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Stage */ 
