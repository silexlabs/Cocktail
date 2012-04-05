#ifndef INCLUDED_nme_media_SoundChannel
#define INCLUDED_nme_media_SoundChannel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/EventDispatcher.h>
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,media,SoundChannel)
HX_DECLARE_CLASS2(nme,media,SoundTransform)
namespace nme{
namespace media{


class SoundChannel_obj : public ::nme::events::EventDispatcher_obj{
	public:
		typedef ::nme::events::EventDispatcher_obj super;
		typedef SoundChannel_obj OBJ_;
		SoundChannel_obj();
		Void __construct(Dynamic inSoundHandle,double startTime,int loops,::nme::media::SoundTransform sndTransform);

	public:
		static hx::ObjectPtr< SoundChannel_obj > __new(Dynamic inSoundHandle,double startTime,int loops,::nme::media::SoundTransform sndTransform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundChannel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundChannel"); }

		double leftPeak; /* REM */ 
		double rightPeak; /* REM */ 
		double position; /* REM */ 
		::nme::media::SoundTransform soundTransform; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		::nme::media::SoundTransform nmeTransform; /* REM */ 
		virtual bool nmeCheckComplete( );
		Dynamic nmeCheckComplete_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual double nmeGetLeft( );
		Dynamic nmeGetLeft_dyn();

		virtual double nmeGetRight( );
		Dynamic nmeGetRight_dyn();

		virtual double nmeGetPosition( );
		Dynamic nmeGetPosition_dyn();

		virtual ::nme::media::SoundTransform nmeGetTransform( );
		Dynamic nmeGetTransform_dyn();

		virtual ::nme::media::SoundTransform nmeSetTransform( ::nme::media::SoundTransform inTransform);
		Dynamic nmeSetTransform_dyn();

		static Array< ::nme::media::SoundChannel > nmeIncompleteList; /* REM */ 
		static bool nmeCompletePending( );
		static Dynamic nmeCompletePending_dyn();

		static Void nmePollComplete( );
		static Dynamic nmePollComplete_dyn();

		static Dynamic nme_sound_channel_is_complete; /* REM */ 
	Dynamic &nme_sound_channel_is_complete_dyn() { return nme_sound_channel_is_complete;}
		static Dynamic nme_sound_channel_get_left; /* REM */ 
	Dynamic &nme_sound_channel_get_left_dyn() { return nme_sound_channel_get_left;}
		static Dynamic nme_sound_channel_get_right; /* REM */ 
	Dynamic &nme_sound_channel_get_right_dyn() { return nme_sound_channel_get_right;}
		static Dynamic nme_sound_channel_get_position; /* REM */ 
	Dynamic &nme_sound_channel_get_position_dyn() { return nme_sound_channel_get_position;}
		static Dynamic nme_sound_channel_stop; /* REM */ 
	Dynamic &nme_sound_channel_stop_dyn() { return nme_sound_channel_stop;}
		static Dynamic nme_sound_channel_create; /* REM */ 
	Dynamic &nme_sound_channel_create_dyn() { return nme_sound_channel_create;}
		static Dynamic nme_sound_channel_set_transform; /* REM */ 
	Dynamic &nme_sound_channel_set_transform_dyn() { return nme_sound_channel_set_transform;}
};

} // end namespace nme
} // end namespace media

#endif /* INCLUDED_nme_media_SoundChannel */ 
