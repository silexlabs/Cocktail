#ifndef INCLUDED_neash_geom_ColorTransform
#define INCLUDED_neash_geom_ColorTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,ColorTransform)
namespace neash{
namespace geom{


class ColorTransform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorTransform_obj OBJ_;
		ColorTransform_obj();
		Void __construct(hx::Null< Float >  __o_inRedMultiplier,hx::Null< Float >  __o_inGreenMultiplier,hx::Null< Float >  __o_inBlueMultiplier,hx::Null< Float >  __o_inAlphaMultiplier,hx::Null< Float >  __o_inRedOffset,hx::Null< Float >  __o_inGreenOffset,hx::Null< Float >  __o_inBlueOffset,hx::Null< Float >  __o_inAlphaOffset);

	public:
		static hx::ObjectPtr< ColorTransform_obj > __new(hx::Null< Float >  __o_inRedMultiplier,hx::Null< Float >  __o_inGreenMultiplier,hx::Null< Float >  __o_inBlueMultiplier,hx::Null< Float >  __o_inAlphaMultiplier,hx::Null< Float >  __o_inRedOffset,hx::Null< Float >  __o_inGreenOffset,hx::Null< Float >  __o_inBlueOffset,hx::Null< Float >  __o_inAlphaOffset);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorTransform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColorTransform"); }

		virtual int nmeSetColor( int value);
		Dynamic nmeSetColor_dyn();

		virtual int nmeGetColor( );
		Dynamic nmeGetColor_dyn();

		virtual Void concat( ::neash::geom::ColorTransform second);
		Dynamic concat_dyn();

		Float redOffset; /* REM */ 
		Float redMultiplier; /* REM */ 
		Float greenOffset; /* REM */ 
		Float greenMultiplier; /* REM */ 
		int color; /* REM */ 
		Float blueOffset; /* REM */ 
		Float blueMultiplier; /* REM */ 
		Float alphaOffset; /* REM */ 
		Float alphaMultiplier; /* REM */ 
};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_ColorTransform */ 
