#ifndef INCLUDED_cocktail_core_config_Config
#define INCLUDED_cocktail_core_config_Config

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,config,Config)
namespace cocktail{
namespace core{
namespace config{


class Config_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Config_obj OBJ_;
		Config_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Config_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Config_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Config"); }

		virtual Void updateStringParam( ::String name,::String value);
		Dynamic updateStringParam_dyn();

		virtual Void updateIntParam( ::String name,::String value);
		Dynamic updateIntParam_dyn();

		virtual Void updateBoolParam( ::String name,::String value);
		Dynamic updateBoolParam_dyn();

		virtual Void updateConfig( ::String name,::String value);
		Dynamic updateConfig_dyn();

		bool videoBelowWhenNoCompositing; /* REM */ 
		bool objectBelowWhenNoCompositing; /* REM */ 
		bool enableCompositing; /* REM */ 
		int thickBorderWidth; /* REM */ 
		int mediumBorderWidth; /* REM */ 
		int thinBorderWidth; /* REM */ 
		int xxLargeFontSize; /* REM */ 
		int xLargeFontSize; /* REM */ 
		int largeFontSize; /* REM */ 
		int mediumFontSize; /* REM */ 
		int smallFontSize; /* REM */ 
		int xSmallFontSize; /* REM */ 
		int xxSmallFontSize; /* REM */ 
		::String defaultFontColor; /* REM */ 
		::String defaultFont; /* REM */ 
		bool useStageVideoIfAvailable; /* REM */ 
		bool useAdvancedHitTesting; /* REM */ 
		bool enableSynchronousUpdate; /* REM */ 
		bool useLowStageQuality; /* REM */ 
		bool enableBitmapSmoothing; /* REM */ 
		int touchMovePreventClickDistance; /* REM */ 
		bool enableMouseEvent; /* REM */ 
		static ::cocktail::core::config::Config _instance; /* REM */ 
		static ::cocktail::core::config::Config getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace config

#endif /* INCLUDED_cocktail_core_config_Config */ 
