#ifndef INCLUDED_neash_display_IBitmapDrawable
#define INCLUDED_neash_display_IBitmapDrawable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,geom,ColorTransform)
HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace display{


class IBitmapDrawable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IBitmapDrawable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void nmeDrawToSurface( Dynamic inSurface,::neash::geom::Matrix matrix,::neash::geom::ColorTransform colorTransform,::String blendMode,::neash::geom::Rectangle clipRect,bool smoothing)=0;
		Dynamic nmeDrawToSurface_dyn();
};

#define DELEGATE_neash_display_IBitmapDrawable \
virtual Void nmeDrawToSurface( Dynamic inSurface,::neash::geom::Matrix matrix,::neash::geom::ColorTransform colorTransform,::String blendMode,::neash::geom::Rectangle clipRect,bool smoothing) { return mDelegate->nmeDrawToSurface(inSurface,matrix,colorTransform,blendMode,clipRect,smoothing);}  \
virtual Dynamic nmeDrawToSurface_dyn() { return mDelegate->nmeDrawToSurface_dyn();}  \


template<typename IMPL>
class IBitmapDrawable_delegate_ : public IBitmapDrawable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IBitmapDrawable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_neash_display_IBitmapDrawable
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_IBitmapDrawable */ 
