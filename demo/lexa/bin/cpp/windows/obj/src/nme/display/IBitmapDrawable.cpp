#include <hxcpp.h>

#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace display{

HX_DEFINE_DYNAMIC_FUNC6(IBitmapDrawable_obj,nmeDrawToSurface,)


Class IBitmapDrawable_obj::__mClass;

void IBitmapDrawable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.IBitmapDrawable"), hx::TCanCast< IBitmapDrawable_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace nme
} // end namespace display
