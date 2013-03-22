#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#define INCLUDED_cocktail_core_html_HTMLMediaElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLMediaElement)
HX_DECLARE_CLASS3(cocktail,core,html,TimeRanges)
HX_DECLARE_CLASS3(cocktail,port,base,NativeMedia)
namespace cocktail{
namespace core{
namespace html{


class HTMLMediaElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
		typedef HTMLMediaElement_obj OBJ_;
		HTMLMediaElement_obj();
		Void __construct(::String tagName);

	public:
		static hx::ObjectPtr< HTMLMediaElement_obj > __new(::String tagName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLMediaElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLMediaElement"); }

		virtual Float set_currentTime( Float value);
		Dynamic set_currentTime_dyn();

		virtual Float get_currentTime( );
		Dynamic get_currentTime_dyn();

		virtual ::cocktail::core::html::TimeRanges get_buffered( );
		Dynamic get_buffered_dyn();

		virtual Float set_volume( Float value);
		Dynamic set_volume_dyn();

		virtual bool set_muted( bool value);
		Dynamic set_muted_dyn();

		virtual ::String set_preload( ::String value);
		Dynamic set_preload_dyn();

		virtual ::String get_preload( );
		Dynamic get_preload_dyn();

		virtual bool set_loop( bool value);
		Dynamic set_loop_dyn();

		virtual bool get_loop( );
		Dynamic get_loop_dyn();

		virtual bool set_autoplay( bool value);
		Dynamic set_autoplay_dyn();

		virtual bool get_autoplay( );
		Dynamic get_autoplay_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual ::String get_src( );
		Dynamic get_src_dyn();

		virtual Void onProgressTick( Float timeStamp);
		Dynamic onProgressTick_dyn();

		virtual Void onTimeUpdateTick( Float timeStamp);
		Dynamic onTimeUpdateTick_dyn();

		virtual Void onNativeMediaLoadedMetaData( ::cocktail::core::event::Event e);
		Dynamic onNativeMediaLoadedMetaData_dyn();

		virtual Void onLoadingError( ::cocktail::core::event::Event error);
		Dynamic onLoadingError_dyn();

		virtual bool hasChildSourceElement( );
		Dynamic hasChildSourceElement_dyn();

		virtual Void establishMediaTimeline( );
		Dynamic establishMediaTimeline_dyn();

		virtual bool isPotentiallyPlaying( );
		Dynamic isPotentiallyPlaying_dyn();

		virtual Void setReadyState( int newReadyState);
		Dynamic setReadyState_dyn();

		virtual Void seek( Float newPlaybackPosition);
		Dynamic seek_dyn();

		virtual Void fetchResource( ::String url);
		Dynamic fetchResource_dyn();

		virtual Void doSelectResource( Float time);
		Dynamic doSelectResource_dyn();

		virtual Void selectResource( );
		Dynamic selectResource_dyn();

		virtual Void loadResource( );
		Dynamic loadResource_dyn();

		virtual Void doPlay( );
		Dynamic doPlay_dyn();

		virtual ::String canPlayType( ::String type);
		Dynamic canPlayType_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual Void play( );
		Dynamic play_dyn();

		virtual ::String getAttribute( ::String name);

		virtual Void setAttribute( ::String name,::String value);

		virtual Dynamic appendChild( Dynamic _tmp_newChild);

		virtual Void initNativeMedia( );
		Dynamic initNativeMedia_dyn();

		virtual Void init( );

		bool _autoplaying; /* REM */ 
		bool _loadedDataWasDispatched; /* REM */ 
		Float _earliestPossiblePosition; /* REM */ 
		Float _defaultPlaybackStartPosition; /* REM */ 
		Float _currentPlaybackPosition; /* REM */ 
		Float _officialPlaybackPosition; /* REM */ 
		Float _initialPlaybackPosition; /* REM */ 
		bool _stalledByPreload; /* REM */ 
		::cocktail::port::base::NativeMedia nativeMedia; /* REM */ 
		Float volume; /* REM */ 
		bool muted; /* REM */ 
		bool ended; /* REM */ 
		bool paused; /* REM */ 
		::cocktail::core::html::TimeRanges buffered; /* REM */ 
		Float duration; /* REM */ 
		::String currentSrc; /* REM */ 
		Float currentTime; /* REM */ 
		bool seeking; /* REM */ 
		int readyState; /* REM */ 
		int networkState; /* REM */ 
		::String preload; /* REM */ 
		bool loop; /* REM */ 
		bool autoplay; /* REM */ 
		::String src; /* REM */ 
		static int RESOURCE_SELECTION_ATTRIBUTE_MODE; /* REM */ 
		static int RESOURCE_SELECTION_CHILDREN_MODE; /* REM */ 
		static int TIME_UPDATE_FREQUENCY; /* REM */ 
		static int PROGRESS_FREQUENCY; /* REM */ 
		static Float PLAYBACK_END_DELTA; /* REM */ 
		static int NETWORK_EMPTY; /* REM */ 
		static int NETWORK_IDLE; /* REM */ 
		static int NETWORK_LOADING; /* REM */ 
		static int NETWORK_NO_SOURCE; /* REM */ 
		static ::String CAN_PLAY_TYPE_MAYBE; /* REM */ 
		static ::String CAN_PLAY_TYPE_PROBABLY; /* REM */ 
		static int HAVE_NOTHING; /* REM */ 
		static int HAVE_METADATA; /* REM */ 
		static int HAVE_CURRENT_DATA; /* REM */ 
		static int HAVE_FUTURE_DATA; /* REM */ 
		static int HAVE_ENOUGH_DATA; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLMediaElement */ 
