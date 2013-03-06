#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_GeomUtils
#include <cocktail/core/geom/GeomUtils.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void GeomUtils_obj::__construct()
{
HX_STACK_PUSH("GeomUtils::new","cocktail/core/geom/GeomUtils.hx",25);
{
}
;
	return null();
}

GeomUtils_obj::~GeomUtils_obj() { }

Dynamic GeomUtils_obj::__CreateEmpty() { return  new GeomUtils_obj; }
hx::ObjectPtr< GeomUtils_obj > GeomUtils_obj::__new()
{  hx::ObjectPtr< GeomUtils_obj > result = new GeomUtils_obj();
	result->__construct();
	return result;}

Dynamic GeomUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GeomUtils_obj > result = new GeomUtils_obj();
	result->__construct();
	return result;}

Void GeomUtils_obj::addBounds( ::cocktail::core::geom::RectangleVO addedBounds,::cocktail::core::geom::RectangleVO bounds,hx::Null< bool >  __o_getHorizontalBounds,hx::Null< bool >  __o_getVerticalBounds){
bool getHorizontalBounds = __o_getHorizontalBounds.Default(true);
bool getVerticalBounds = __o_getVerticalBounds.Default(true);
	HX_STACK_PUSH("GeomUtils::addBounds","cocktail/core/geom/GeomUtils.hx",39);
	HX_STACK_ARG(addedBounds,"addedBounds");
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_ARG(getHorizontalBounds,"getHorizontalBounds");
	HX_STACK_ARG(getVerticalBounds,"getVerticalBounds");
{
		HX_STACK_LINE(41)
		if (((getHorizontalBounds == true))){
			HX_STACK_LINE(43)
			if (((addedBounds->x < bounds->x))){
				HX_STACK_LINE(44)
				bounds->x = addedBounds->x;
			}
			HX_STACK_LINE(47)
			if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
				HX_STACK_LINE(48)
				bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
			}
		}
		HX_STACK_LINE(54)
		if (((getVerticalBounds == true))){
			HX_STACK_LINE(56)
			if (((addedBounds->y < bounds->y))){
				HX_STACK_LINE(57)
				bounds->y = addedBounds->y;
			}
			HX_STACK_LINE(61)
			if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
				HX_STACK_LINE(62)
				bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GeomUtils_obj,addBounds,(void))

Void GeomUtils_obj::intersectBounds( ::cocktail::core::geom::RectangleVO bounds1,::cocktail::core::geom::RectangleVO bounds2,::cocktail::core::geom::RectangleVO resultBounds){
{
		HX_STACK_PUSH("GeomUtils::intersectBounds","cocktail/core/geom/GeomUtils.hx",78);
		HX_STACK_ARG(bounds1,"bounds1");
		HX_STACK_ARG(bounds2,"bounds2");
		HX_STACK_ARG(resultBounds,"resultBounds");
		HX_STACK_LINE(78)
		if (((bool((bool((bool(((bounds1->x + bounds1->width) < bounds2->x)) || bool(((bounds2->x + bounds2->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < bounds2->y)))) || bool(((bounds2->y + bounds2->height) < bounds1->y))))){
			HX_STACK_LINE(88)
			resultBounds->x = (int)0;
			HX_STACK_LINE(89)
			resultBounds->y = (int)0;
			HX_STACK_LINE(90)
			resultBounds->height = (int)0;
			HX_STACK_LINE(91)
			resultBounds->width = (int)0;
		}
		else{
			HX_STACK_LINE(95)
			Float left = (int)0;		HX_STACK_VAR(left,"left");
			HX_STACK_LINE(96)
			Float right = (int)0;		HX_STACK_VAR(right,"right");
			HX_STACK_LINE(97)
			Float top = (int)0;		HX_STACK_VAR(top,"top");
			HX_STACK_LINE(98)
			Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
			HX_STACK_LINE(100)
			if (((bounds1->x < bounds2->x))){
				HX_STACK_LINE(101)
				left = bounds2->x;
			}
			else{
				HX_STACK_LINE(105)
				left = bounds1->x;
			}
			HX_STACK_LINE(109)
			if ((((bounds1->x + bounds1->width) < (bounds2->x + bounds2->width)))){
				HX_STACK_LINE(110)
				right = (bounds1->x + bounds1->width);
			}
			else{
				HX_STACK_LINE(114)
				right = (bounds2->x + bounds2->width);
			}
			HX_STACK_LINE(118)
			if (((bounds1->y < bounds2->y))){
				HX_STACK_LINE(119)
				top = bounds2->y;
			}
			else{
				HX_STACK_LINE(123)
				top = bounds1->y;
			}
			HX_STACK_LINE(127)
			if ((((bounds1->y + bounds1->height) < (bounds2->y + bounds2->height)))){
				HX_STACK_LINE(128)
				bottom = (bounds1->y + bounds1->height);
			}
			else{
				HX_STACK_LINE(132)
				bottom = (bounds2->y + bounds2->height);
			}
			HX_STACK_LINE(137)
			resultBounds->x = left;
			HX_STACK_LINE(138)
			resultBounds->y = top;
			HX_STACK_LINE(139)
			resultBounds->width = (right - left);
			HX_STACK_LINE(140)
			resultBounds->height = (bottom - top);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GeomUtils_obj,intersectBounds,(void))

Void GeomUtils_obj::getCenteredBounds( Float maximumWidth,Float maximumHeight,Float boundsWidth,Float boundsHeight,::cocktail::core::geom::RectangleVO resultBounds){
{
		HX_STACK_PUSH("GeomUtils::getCenteredBounds","cocktail/core/geom/GeomUtils.hx",161);
		HX_STACK_ARG(maximumWidth,"maximumWidth");
		HX_STACK_ARG(maximumHeight,"maximumHeight");
		HX_STACK_ARG(boundsWidth,"boundsWidth");
		HX_STACK_ARG(boundsHeight,"boundsHeight");
		HX_STACK_ARG(resultBounds,"resultBounds");
		HX_STACK_LINE(163)
		if (((bool((bool((bool((maximumWidth == (int)0)) || bool((maximumHeight == (int)0)))) || bool((boundsWidth == (int)0)))) || bool((boundsHeight == (int)0))))){
			HX_STACK_LINE(164)
			return null();
		}
		HX_STACK_LINE(170)
		Float width;		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(171)
		Float height;		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(173)
		if (((maximumWidth > maximumHeight))){
			HX_STACK_LINE(176)
			Float ratio = (Float(boundsHeight) / Float(maximumHeight));		HX_STACK_VAR(ratio,"ratio");
			HX_STACK_LINE(179)
			if ((((Float(boundsWidth) / Float(ratio)) < maximumWidth))){
				HX_STACK_LINE(182)
				width = (Float(boundsWidth) / Float(ratio));
				HX_STACK_LINE(183)
				height = maximumHeight;
			}
			else{
				HX_STACK_LINE(188)
				ratio = (Float(boundsWidth) / Float(maximumWidth));
				HX_STACK_LINE(189)
				width = maximumWidth;
				HX_STACK_LINE(190)
				height = (Float(boundsHeight) / Float(ratio));
			}
		}
		else{
			HX_STACK_LINE(196)
			Float ratio = (Float(boundsWidth) / Float(maximumWidth));		HX_STACK_VAR(ratio,"ratio");
			HX_STACK_LINE(198)
			if ((((Float(boundsHeight) / Float(ratio)) < maximumHeight))){
				HX_STACK_LINE(200)
				height = (Float(boundsHeight) / Float(ratio));
				HX_STACK_LINE(201)
				width = maximumWidth;
			}
			else{
				HX_STACK_LINE(205)
				ratio = (Float(boundsHeight) / Float(maximumHeight));
				HX_STACK_LINE(206)
				width = (Float(boundsWidth) / Float(ratio));
				HX_STACK_LINE(207)
				height = maximumHeight;
			}
		}
		HX_STACK_LINE(212)
		Float xOffset = (Float(((maximumWidth - width))) / Float((int)2));		HX_STACK_VAR(xOffset,"xOffset");
		HX_STACK_LINE(213)
		Float yOffset = (Float(((maximumHeight - height))) / Float((int)2));		HX_STACK_VAR(yOffset,"yOffset");
		HX_STACK_LINE(215)
		resultBounds->x = xOffset;
		HX_STACK_LINE(216)
		resultBounds->y = yOffset;
		HX_STACK_LINE(217)
		resultBounds->width = width;
		HX_STACK_LINE(218)
		resultBounds->height = height;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GeomUtils_obj,getCenteredBounds,(void))


GeomUtils_obj::GeomUtils_obj()
{
}

void GeomUtils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GeomUtils);
	HX_MARK_END_CLASS();
}

void GeomUtils_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic GeomUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"addBounds") ) { return addBounds_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intersectBounds") ) { return intersectBounds_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getCenteredBounds") ) { return getCenteredBounds_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GeomUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GeomUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("addBounds"),
	HX_CSTRING("intersectBounds"),
	HX_CSTRING("getCenteredBounds"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GeomUtils_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GeomUtils_obj::__mClass,"__mClass");
};

Class GeomUtils_obj::__mClass;

void GeomUtils_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.GeomUtils"), hx::TCanCast< GeomUtils_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GeomUtils_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
