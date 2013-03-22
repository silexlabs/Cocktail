#ifndef INCLUDED_cocktail_core_animation_Animator
#define INCLUDED_cocktail_core_animation_Animator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,animation,Animator)
HX_DECLARE_CLASS3(cocktail,core,animation,PendingAnimationVO)
HX_DECLARE_CLASS3(cocktail,core,animation,Transition)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
namespace cocktail{
namespace core{
namespace animation{


class Animator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Animator_obj OBJ_;
		Animator_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Animator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Animator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Animator"); }

		virtual Void onTransitionUpdate( ::cocktail::core::animation::Transition transition);
		Dynamic onTransitionUpdate_dyn();

		virtual Void onTransitionComplete( ::cocktail::core::animation::Transition transition);
		Dynamic onTransitionComplete_dyn();

		virtual int getRepeatedIndex( int index,int length);
		Dynamic getRepeatedIndex_dyn();

		virtual Float getTransitionDelayOrDurationAsFloat( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getTransitionDelayOrDurationAsFloat_dyn();

		virtual Array< Float > getAsFloatArray( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getAsFloatArray_dyn();

		virtual Array< ::cocktail::core::css::CSSPropertyValue > getTransitionTimingFunctionsAsArray( ::cocktail::core::css::CSSPropertyValue transitionTimingFunction);
		Dynamic getTransitionTimingFunctionsAsArray_dyn();

		virtual Float getEndValue( ::cocktail::core::css::CoreStyle style,int propertyIndex);
		Dynamic getEndValue_dyn();

		virtual int getIndexOfPropertyInTransitionProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue transitionProperty);
		Dynamic getIndexOfPropertyInTransitionProperty_dyn();

		virtual bool startTransitionIfNeeded( ::cocktail::core::animation::PendingAnimationVO pendingAnimation,::cocktail::core::css::CoreStyle style);
		Dynamic startTransitionIfNeeded_dyn();

		virtual bool revertTransitionIfNeeded( ::cocktail::core::animation::Transition currentTransition,Float currentValue,::cocktail::core::css::CoreStyle style);
		Dynamic revertTransitionIfNeeded_dyn();

		virtual Void registerPendingAnimation( int propertyIndex,Float startValue);
		Dynamic registerPendingAnimation_dyn();

		virtual bool startPendingAnimations( ::cocktail::core::css::CoreStyle style);
		Dynamic startPendingAnimations_dyn();

		Dynamic onTransitionUpdateCallback; /* REM */ 
		Dynamic &onTransitionUpdateCallback_dyn() { return onTransitionUpdateCallback;}
		Dynamic onTransitionCompleteCallback; /* REM */ 
		Dynamic &onTransitionCompleteCallback_dyn() { return onTransitionCompleteCallback;}
		Array< ::cocktail::core::animation::PendingAnimationVO > _pendingAnimations; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace animation

#endif /* INCLUDED_cocktail_core_animation_Animator */ 
