#ifndef INCLUDED_haxe_Timer
#define INCLUDED_haxe_Timer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Timer)
namespace haxe{


class Timer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(double time);

	public:
		static hx::ObjectPtr< Timer_obj > __new(double time);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Timer"); }

		double mTime; /* REM */ 
		double mFireAt; /* REM */ 
		bool mRunning; /* REM */ 
		Dynamic run;
		inline Dynamic &run_dyn() {return run; }

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void nmeCheck( double inTime);
		Dynamic nmeCheck_dyn();

		static Array< ::haxe::Timer > sRunningTimers; /* REM */ 
		static double nmeNextWake( double limit);
		static Dynamic nmeNextWake_dyn();

		static Void nmeCheckTimers( );
		static Dynamic nmeCheckTimers_dyn();

		static double GetMS( );
		static Dynamic GetMS_dyn();

		static ::haxe::Timer delay( Dynamic f,int time);
		static Dynamic delay_dyn();

		static double stamp( );
		static Dynamic stamp_dyn();

		static Dynamic nme_time_stamp; /* REM */ 
	Dynamic &nme_time_stamp_dyn() { return nme_time_stamp;}
};

} // end namespace haxe

#endif /* INCLUDED_haxe_Timer */ 
