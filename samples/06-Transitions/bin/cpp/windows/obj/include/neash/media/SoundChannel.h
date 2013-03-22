#ifndef INCLUDED_neash_media_SoundChannel
#define INCLUDED_neash_media_SoundChannel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,media,SoundChannel)
HX_DECLARE_CLASS2(neash,media,SoundTransform)
HX_DECLARE_CLASS2(neash,utils,ByteArray)
HX_DECLARE_CLASS2(neash,utils,IDataInput)
namespace neash{
namespace media{


class SoundChannel_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef SoundChannel_obj OBJ_;
		SoundChannel_obj();
		Void __construct(Dynamic inSoundHandle,Float startTime,int loops,::neash::media::SoundTransform sndTransform);

	public:
		static hx::ObjectPtr< SoundChannel_obj > __new(Dynamic inSoundHandle,Float startTime,int loops,::neash::media::SoundTransform sndTransform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundChannel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundChannel"); }

		virtual ::neash::media::SoundTransform nmeSetTransform( ::neash::media::SoundTransform inTransform);
		Dynamic nmeSetTransform_dyn();

		virtual ::neash::media::SoundTransform nmeGetTransform( );
		Dynamic nmeGetTransform_dyn();

		virtual Float nmeGetPosition( );
		Dynamic nmeGetPosition_dyn();

		virtual Float nmeGetRight( );
		Dynamic nmeGetRight_dyn();

		virtual Float nmeGetLeft( );
		Dynamic nmeGetLeft_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual bool nmeCheckComplete( );
		Dynamic nmeCheckComplete_dyn();

		::neash::events::EventDispatcher nmeDataProvider; /* REM */ 
		::neash::media::SoundTransform nmeTransform; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		::neash::media::SoundTransform soundTransform; /* REM */ 
		Float position; /* REM */ 
		Float rightPeak; /* REM */ 
		Float leftPeak; /* REM */ 
		static int nmeDynamicSoundCount; /* REM */ 
		static Array< ::neash::media::SoundChannel > nmeIncompleteList; /* REM */ 
		static ::neash::media::SoundChannel createDynamic( Dynamic inSoundHandle,::neash::media::SoundTransform sndTransform,::neash::events::EventDispatcher dataProvider);
		static Dynamic createDynamic_dyn();

		static bool nmeCompletePending( );
		static Dynamic nmeCompletePending_dyn();

		static Void nmePollComplete( );
		static Dynamic nmePollComplete_dyn();

		static Dynamic nme_sound_channel_is_complete; /* REM */ 
		static Dynamic &nme_sound_channel_is_complete_dyn() { return nme_sound_channel_is_complete;}
		static Dynamic nme_sound_channel_get_left; /* REM */ 
		static Dynamic &nme_sound_channel_get_left_dyn() { return nme_sound_channel_get_left;}
		static Dynamic nme_sound_channel_get_right; /* REM */ 
		static Dynamic &nme_sound_channel_get_right_dyn() { return nme_sound_channel_get_right;}
		static Dynamic nme_sound_channel_get_position; /* REM */ 
		static Dynamic &nme_sound_channel_get_position_dyn() { return nme_sound_channel_get_position;}
		static Dynamic nme_sound_channel_get_data_position; /* REM */ 
		static Dynamic &nme_sound_channel_get_data_position_dyn() { return nme_sound_channel_get_data_position;}
		static Dynamic nme_sound_channel_stop; /* REM */ 
		static Dynamic &nme_sound_channel_stop_dyn() { return nme_sound_channel_stop;}
		static Dynamic nme_sound_channel_create; /* REM */ 
		static Dynamic &nme_sound_channel_create_dyn() { return nme_sound_channel_create;}
		static Dynamic nme_sound_channel_set_transform; /* REM */ 
		static Dynamic &nme_sound_channel_set_transform_dyn() { return nme_sound_channel_set_transform;}
		static Dynamic nme_sound_channel_needs_data; /* REM */ 
		static Dynamic &nme_sound_channel_needs_data_dyn() { return nme_sound_channel_needs_data;}
		static Dynamic nme_sound_channel_add_data; /* REM */ 
		static Dynamic &nme_sound_channel_add_data_dyn() { return nme_sound_channel_add_data;}
};

} // end namespace neash
} // end namespace media

#endif /* INCLUDED_neash_media_SoundChannel */ 
