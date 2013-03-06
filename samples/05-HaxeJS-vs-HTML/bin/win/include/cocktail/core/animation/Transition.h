#ifndef INCLUDED_cocktail_core_animation_Transition
#define INCLUDED_cocktail_core_animation_Transition

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,animation,Transition)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,geom,CubicBezier)
namespace cocktail{
namespace core{
namespace animation{


class Transition_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Transition_obj OBJ_;
		Transition_obj();
		Void __construct(int propertyIndex,::cocktail::core::css::CoreStyle target,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Float startValue,Float endValue,Dynamic onComplete,Dynamic onUpdate);

	public:
		static hx::ObjectPtr< Transition_obj > __new(int propertyIndex,::cocktail::core::css::CoreStyle target,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Float startValue,Float endValue,Dynamic onComplete,Dynamic onUpdate);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Transition_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Transition"); }

		virtual Float get_currentValue( );
		Dynamic get_currentValue_dyn();

		virtual bool get_complete( );
		Dynamic get_complete_dyn();

		virtual Void revert( );
		Dynamic revert_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void updateTime( Float delta);
		Dynamic updateTime_dyn();

		bool complete; /* REM */ 
		::cocktail::core::css::CoreStyle target; /* REM */ 
		Float transitionDuration; /* REM */ 
		Dynamic onUpdate; /* REM */ 
		Dynamic &onUpdate_dyn() { return onUpdate;}
		Dynamic onComplete; /* REM */ 
		Dynamic &onComplete_dyn() { return onComplete;}
		Float currentValue; /* REM */ 
		int propertyIndex; /* REM */ 
		::cocktail::core::geom::CubicBezier _cubicBezier; /* REM */ 
		Float _elapsedTime; /* REM */ 
		Float endValue; /* REM */ 
		Float startValue; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transitionTimingFunction; /* REM */ 
		Float transitionDelay; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace animation

#endif /* INCLUDED_cocktail_core_animation_Transition */ 
