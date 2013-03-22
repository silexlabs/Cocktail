#ifndef INCLUDED_cocktail_port_platform_flash_player_TimerImpl
#define INCLUDED_cocktail_port_platform_flash_player_TimerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/timer/AbstractTimerImpl.h>
HX_DECLARE_CLASS3(cocktail,core,timer,AbstractTimerImpl)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,TimerImpl)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class TimerImpl_obj : public ::cocktail::core::timer::AbstractTimerImpl_obj{
	public:
		typedef ::cocktail::core::timer::AbstractTimerImpl_obj super;
		typedef TimerImpl_obj OBJ_;
		TimerImpl_obj();
		Void __construct(Dynamic updateCallback);

	public:
		static hx::ObjectPtr< TimerImpl_obj > __new(Dynamic updateCallback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimerImpl"); }

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_TimerImpl */ 
