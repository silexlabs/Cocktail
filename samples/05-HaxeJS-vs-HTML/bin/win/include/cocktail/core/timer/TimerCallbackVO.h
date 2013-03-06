#ifndef INCLUDED_cocktail_core_timer_TimerCallbackVO
#define INCLUDED_cocktail_core_timer_TimerCallbackVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,timer,TimerCallbackVO)
namespace cocktail{
namespace core{
namespace timer{


class TimerCallbackVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TimerCallbackVO_obj OBJ_;
		TimerCallbackVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TimerCallbackVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerCallbackVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimerCallbackVO"); }

		bool called; /* REM */ 
		Float callbackTime; /* REM */ 
		Dynamic timerCallback; /* REM */ 
		Dynamic &timerCallback_dyn() { return timerCallback;}
};

} // end namespace cocktail
} // end namespace core
} // end namespace timer

#endif /* INCLUDED_cocktail_core_timer_TimerCallbackVO */ 
