#ifndef INCLUDED_cocktail_core_background_InitialBlockBackgroundManager
#define INCLUDED_cocktail_core_background_InitialBlockBackgroundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/background/BackgroundManager.h>
HX_DECLARE_CLASS3(cocktail,core,background,BackgroundManager)
HX_DECLARE_CLASS3(cocktail,core,background,InitialBlockBackgroundManager)
namespace cocktail{
namespace core{
namespace background{


class InitialBlockBackgroundManager_obj : public ::cocktail::core::background::BackgroundManager_obj{
	public:
		typedef ::cocktail::core::background::BackgroundManager_obj super;
		typedef InitialBlockBackgroundManager_obj OBJ_;
		InitialBlockBackgroundManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InitialBlockBackgroundManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InitialBlockBackgroundManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InitialBlockBackgroundManager"); }

		virtual Dynamic getBackgroundPaintingBox( Dynamic computedBackgroundBox);
		Dynamic getBackgroundPaintingBox_dyn();

		virtual Dynamic getBackgroundPositioningBox( Dynamic computedPositioningBox);
		Dynamic getBackgroundPositioningBox_dyn();

		virtual Dynamic getWindowRectangleData( );
		Dynamic getWindowRectangleData_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace background

#endif /* INCLUDED_cocktail_core_background_InitialBlockBackgroundManager */ 
