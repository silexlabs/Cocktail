#ifndef INCLUDED_cocktail_port_platform_nme_NativeAudio
#define INCLUDED_cocktail_port_platform_nme_NativeAudio

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/platform/flash_player/NativeAudio.h>
HX_DECLARE_CLASS3(cocktail,port,base,NativeMedia)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeAudio)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeAudio)
namespace cocktail{
namespace port{
namespace platform{
namespace nme{


class NativeAudio_obj : public ::cocktail::port::platform::flash_player::NativeAudio_obj{
	public:
		typedef ::cocktail::port::platform::flash_player::NativeAudio_obj super;
		typedef NativeAudio_obj OBJ_;
		NativeAudio_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeAudio_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeAudio_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeAudio"); }

		virtual Void initSound( ::String src);

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_cocktail_port_platform_nme_NativeAudio */ 
