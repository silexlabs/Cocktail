#ifndef INCLUDED_neash_media_Sound
#define INCLUDED_neash_media_Sound

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,media,ID3Info)
HX_DECLARE_CLASS2(neash,media,Sound)
HX_DECLARE_CLASS2(neash,media,SoundChannel)
HX_DECLARE_CLASS2(neash,media,SoundLoaderContext)
HX_DECLARE_CLASS2(neash,media,SoundTransform)
HX_DECLARE_CLASS2(neash,net,URLRequest)
HX_DECLARE_CLASS2(neash,utils,ByteArray)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
namespace neash{
namespace media{


class Sound_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef Sound_obj OBJ_;
		Sound_obj();
		Void __construct(::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic);

	public:
		static hx::ObjectPtr< Sound_obj > __new(::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  __o_forcePlayAsMusic);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sound_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Sound"); }

		virtual Float nmeGetLength( );
		Dynamic nmeGetLength_dyn();

		virtual bool nmeGetIsBuffering( );
		Dynamic nmeGetIsBuffering_dyn();

		virtual ::neash::media::ID3Info nmeGetID3( );
		Dynamic nmeGetID3_dyn();

		virtual ::neash::media::SoundChannel play( hx::Null< Float >  startTime,hx::Null< int >  loops,::neash::media::SoundTransform sndTransform);
		Dynamic play_dyn();

		virtual Void nmeOnError( ::String msg);
		Dynamic nmeOnError_dyn();

		virtual Void nmeCheckLoading( );
		Dynamic nmeCheckLoading_dyn();

		virtual Void loadPCMFromByteArray( ::neash::utils::ByteArray Bytes,int samples,::String format,hx::Null< bool >  stereo,hx::Null< Float >  sampleRate);
		Dynamic loadPCMFromByteArray_dyn();

		virtual Void loadCompressedDataFromByteArray( ::neash::utils::ByteArray bytes,int length,hx::Null< bool >  forcePlayAsMusic);
		Dynamic loadCompressedDataFromByteArray_dyn();

		virtual Void load( ::neash::net::URLRequest stream,::neash::media::SoundLoaderContext context,hx::Null< bool >  forcePlayAsMusic);
		Dynamic load_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void addEventListener( ::String type,Dynamic listener,hx::Null< bool >  useCapture,hx::Null< int >  priority,hx::Null< bool >  useWeakReference);

		bool nmeDynamicSound; /* REM */ 
		bool nmeLoading; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		::String url; /* REM */ 
		Float length; /* REM */ 
		bool isBuffering; /* REM */ 
		::neash::media::ID3Info id3; /* REM */ 
		int bytesTotal; /* REM */ 
		int bytesLoaded; /* REM */ 
		static Dynamic nme_sound_from_file; /* REM */ 
		static Dynamic &nme_sound_from_file_dyn() { return nme_sound_from_file;}
		static Dynamic nme_sound_from_data; /* REM */ 
		static Dynamic &nme_sound_from_data_dyn() { return nme_sound_from_data;}
		static Dynamic nme_sound_get_id3; /* REM */ 
		static Dynamic &nme_sound_get_id3_dyn() { return nme_sound_get_id3;}
		static Dynamic nme_sound_get_length; /* REM */ 
		static Dynamic &nme_sound_get_length_dyn() { return nme_sound_get_length;}
		static Dynamic nme_sound_close; /* REM */ 
		static Dynamic &nme_sound_close_dyn() { return nme_sound_close;}
		static Dynamic nme_sound_get_status; /* REM */ 
		static Dynamic &nme_sound_get_status_dyn() { return nme_sound_get_status;}
		static Dynamic nme_sound_channel_create_dynamic; /* REM */ 
		static Dynamic &nme_sound_channel_create_dynamic_dyn() { return nme_sound_channel_create_dynamic;}
};

} // end namespace neash
} // end namespace media

#endif /* INCLUDED_neash_media_Sound */ 
