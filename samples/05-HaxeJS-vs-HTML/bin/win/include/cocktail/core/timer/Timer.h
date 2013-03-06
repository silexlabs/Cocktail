#ifndef INCLUDED_cocktail_core_timer_Timer
#define INCLUDED_cocktail_core_timer_Timer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,timer,AbstractTimerImpl)
HX_DECLARE_CLASS3(cocktail,core,timer,Timer)
HX_DECLARE_CLASS3(cocktail,core,timer,TimerCallbackVO)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,TimerImpl)
namespace cocktail{
namespace core{
namespace timer{


class Timer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Timer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Timer"); }

		virtual Void onUpdate( );
		Dynamic onUpdate_dyn();

		virtual Void delay( Dynamic timerCallback,hx::Null< Float >  delay);
		Dynamic delay_dyn();

		::cocktail::port::platform::flash_player::TimerImpl _timerImpl; /* REM */ 
		int _pendingCount; /* REM */ 
		Array< ::cocktail::core::timer::TimerCallbackVO > _pendingCallbacks; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace timer

#endif /* INCLUDED_cocktail_core_timer_Timer */ 
