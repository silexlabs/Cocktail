#ifndef INCLUDED_nme_geom_ColorTransform
#define INCLUDED_nme_geom_ColorTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,geom,ColorTransform)
namespace nme{
namespace geom{


class ColorTransform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorTransform_obj OBJ_;
		ColorTransform_obj();
		Void __construct(Dynamic __o_inRedMultiplier,Dynamic __o_inGreenMultiplier,Dynamic __o_inBlueMultiplier,Dynamic __o_inAlphaMultiplier,Dynamic __o_inRedOffset,Dynamic __o_inGreenOffset,Dynamic __o_inBlueOffset,Dynamic __o_inAlphaOffset);

	public:
		static hx::ObjectPtr< ColorTransform_obj > __new(Dynamic __o_inRedMultiplier,Dynamic __o_inGreenMultiplier,Dynamic __o_inBlueMultiplier,Dynamic __o_inAlphaMultiplier,Dynamic __o_inRedOffset,Dynamic __o_inGreenOffset,Dynamic __o_inBlueOffset,Dynamic __o_inAlphaOffset);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorTransform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColorTransform"); }

		double alphaMultiplier; /* REM */ 
		double alphaOffset; /* REM */ 
		double blueMultiplier; /* REM */ 
		double blueOffset; /* REM */ 
		double greenMultiplier; /* REM */ 
		double greenOffset; /* REM */ 
		double redMultiplier; /* REM */ 
		double redOffset; /* REM */ 
		virtual Void concat( ::nme::geom::ColorTransform second);
		Dynamic concat_dyn();

};

} // end namespace nme
} // end namespace geom

#endif /* INCLUDED_nme_geom_ColorTransform */ 
