#ifndef INCLUDED_nme_media_SoundTransform
#define INCLUDED_nme_media_SoundTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,media,SoundTransform)
namespace nme{
namespace media{


class SoundTransform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundTransform_obj OBJ_;
		SoundTransform_obj();
		Void __construct(Dynamic __o_vol,Dynamic __o_panning);

	public:
		static hx::ObjectPtr< SoundTransform_obj > __new(Dynamic __o_vol,Dynamic __o_panning);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundTransform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundTransform"); }

		double pan; /* REM */ 
		double volume; /* REM */ 
		virtual ::nme::media::SoundTransform clone( );
		Dynamic clone_dyn();

};

} // end namespace nme
} // end namespace media

#endif /* INCLUDED_nme_media_SoundTransform */ 
