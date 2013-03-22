#ifndef INCLUDED_cocktail_core_animation_PendingAnimationVO
#define INCLUDED_cocktail_core_animation_PendingAnimationVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,animation,PendingAnimationVO)
namespace cocktail{
namespace core{
namespace animation{


class PendingAnimationVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PendingAnimationVO_obj OBJ_;
		PendingAnimationVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PendingAnimationVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PendingAnimationVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PendingAnimationVO"); }

		Float startValue; /* REM */ 
		int propertyIndex; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace animation

#endif /* INCLUDED_cocktail_core_animation_PendingAnimationVO */ 
