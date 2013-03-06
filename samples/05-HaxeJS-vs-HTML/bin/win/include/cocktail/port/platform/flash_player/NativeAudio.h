#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeAudio
#define INCLUDED_cocktail_port_platform_flash_player_NativeAudio

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/NativeMedia.h>
HX_DECLARE_CLASS3(cocktail,port,base,NativeMedia)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeAudio)
HX_DECLARE_CLASS2(native,events,ErrorEvent)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,IOErrorEvent)
HX_DECLARE_CLASS2(native,events,TextEvent)
HX_DECLARE_CLASS2(native,media,Sound)
HX_DECLARE_CLASS2(native,media,SoundChannel)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class NativeAudio_obj : public ::cocktail::port::base::NativeMedia_obj{
	public:
		typedef ::cocktail::port::base::NativeMedia_obj super;
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

		virtual ::String set_src( ::String value);

		virtual Float get_currentTime( );

		virtual Float get_duration( );

		virtual Float get_bytesLoaded( );

		virtual Float get_bytesTotal( );

		virtual Float set_volume( Float value);

		virtual Void onIOError( ::native::events::IOErrorEvent e);
		Dynamic onIOError_dyn();

		virtual Void initSound( ::String src);
		Dynamic initSound_dyn();

		virtual Void onID3DataReceived( ::native::events::Event event);
		Dynamic onID3DataReceived_dyn();

		virtual ::String canPlayType( ::String type);

		virtual Void seek( Float time);

		virtual Void pause( );

		virtual Void play( );

		bool _isPlaying; /* REM */ 
		Float _currentTime; /* REM */ 
		::native::media::SoundChannel _soundChannel; /* REM */ 
		::native::media::Sound _sound; /* REM */ 
		static ::String MP3_EXTENSION; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_NativeAudio */ 
