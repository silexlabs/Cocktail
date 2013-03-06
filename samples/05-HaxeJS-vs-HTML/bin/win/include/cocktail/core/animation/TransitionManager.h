#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#define INCLUDED_cocktail_core_animation_TransitionManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,animation,Transition)
HX_DECLARE_CLASS3(cocktail,core,animation,TransitionManager)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
namespace cocktail{
namespace core{
namespace animation{


class TransitionManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TransitionManager_obj OBJ_;
		TransitionManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TransitionManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransitionManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TransitionManager"); }

		virtual Void onTransitionTick( Float timeStamp);
		Dynamic onTransitionTick_dyn();

		virtual Void startTransitionUpdate( );
		Dynamic startTransitionUpdate_dyn();

		virtual Array< ::cocktail::core::animation::Transition > getTransitionsForProperty( int propertyIndex);
		Dynamic getTransitionsForProperty_dyn();

		virtual Void stopTransition( ::cocktail::core::animation::Transition transition);
		Dynamic stopTransition_dyn();

		virtual Void startTransition( ::cocktail::core::css::CoreStyle target,int propertyIndex,Float startValue,Float endValue,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Dynamic onComplete,Dynamic onUpdate);
		Dynamic startTransition_dyn();

		virtual ::cocktail::core::animation::Transition getTransition( int propertyIndex,::cocktail::core::css::CoreStyle style);
		Dynamic getTransition_dyn();

		virtual Void initTransitions( );
		Dynamic initTransitions_dyn();

		Float _lastTick; /* REM */ 
		bool hasTransitionsInProgress; /* REM */ 
		int _currentTransitionsNumber; /* REM */ 
		Array< Array< ::cocktail::core::animation::Transition > > _transitions; /* REM */ 
		static ::cocktail::core::animation::TransitionManager _instance; /* REM */ 
		static ::cocktail::core::animation::TransitionManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace animation

#endif /* INCLUDED_cocktail_core_animation_TransitionManager */ 
