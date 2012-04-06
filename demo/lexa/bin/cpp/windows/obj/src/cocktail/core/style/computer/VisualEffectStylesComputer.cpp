#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Overflow
#include <cocktail/core/style/Overflow.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Transform
#include <cocktail/core/style/Transform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformFunction
#include <cocktail/core/style/TransformFunction.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginX
#include <cocktail/core/style/TransformOriginX.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginY
#include <cocktail/core/style/TransformOriginY.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Translation
#include <cocktail/core/style/Translation.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Visibility
#include <cocktail/core/style/Visibility.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_VisualEffectStylesComputer
#include <cocktail/core/style/computer/VisualEffectStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Angle
#include <cocktail/core/unit/Angle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{

Void VisualEffectStylesComputer_obj::__construct()
{
{
}
;
	return null();
}

VisualEffectStylesComputer_obj::~VisualEffectStylesComputer_obj() { }

Dynamic VisualEffectStylesComputer_obj::__CreateEmpty() { return  new VisualEffectStylesComputer_obj; }
hx::ObjectPtr< VisualEffectStylesComputer_obj > VisualEffectStylesComputer_obj::__new()
{  hx::ObjectPtr< VisualEffectStylesComputer_obj > result = new VisualEffectStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic VisualEffectStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VisualEffectStylesComputer_obj > result = new VisualEffectStylesComputer_obj();
	result->__construct();
	return result;}

Void VisualEffectStylesComputer_obj::compute( ::cocktail::core::style::AbstractCoreStyle style){
{
		HX_SOURCE_PUSH("VisualEffectStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",49)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",52)
		computedStyle->__FieldRef(HX_CSTRING("opacity")) = style->getOpacity();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",55)
		computedStyle->__FieldRef(HX_CSTRING("visibility")) = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedVisibility(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",58)
		computedStyle->__FieldRef(HX_CSTRING("overflowX")) = style->getOverflowX();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",59)
		computedStyle->__FieldRef(HX_CSTRING("overflowY")) = style->getOverflowY();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",62)
		computedStyle->__FieldRef(HX_CSTRING("transformOrigin")) = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTransformOrigin(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",65)
		computedStyle->__FieldRef(HX_CSTRING("transform")) = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTransform(style);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,compute,(void))

bool VisualEffectStylesComputer_obj::getComputedVisibility( ::cocktail::core::style::AbstractCoreStyle style){
	HX_SOURCE_PUSH("VisualEffectStylesComputer_obj::getComputedVisibility")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",77)
	bool visibility;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",79)
	{
::cocktail::core::style::Visibility _switch_1 = (style->getVisibility());
		switch((_switch_1)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",81)
				visibility = true;
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",84)
				visibility = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",88)
	return visibility;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getComputedVisibility,return )

Dynamic VisualEffectStylesComputer_obj::getComputedTransformOrigin( ::cocktail::core::style::AbstractCoreStyle style){
	HX_SOURCE_PUSH("VisualEffectStylesComputer_obj::getComputedTransformOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",97)
	double x;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",98)
	double y;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",101)
	{
::cocktail::core::style::TransformOriginX _switch_2 = (style->getTransformOrigin()->__Field(HX_CSTRING("x")));
		switch((_switch_2)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",103)
					x = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 1: {
				int value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",106)
					x = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,style->getComputedStyle()->__Field(HX_CSTRING("width")));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",109)
				x = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)0,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",112)
				x = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)50,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",115)
				x = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)100,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",120)
	{
::cocktail::core::style::TransformOriginY _switch_3 = (style->getTransformOrigin()->__Field(HX_CSTRING("y")));
		switch((_switch_3)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_3->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",122)
					y = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 1: {
				int value = _switch_3->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",125)
					y = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,style->getComputedStyle()->__Field(HX_CSTRING("width")));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",128)
				y = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)0,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",131)
				y = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)50,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",134)
				y = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)100,style->getComputedStyle()->__Field(HX_CSTRING("width")));
			}
			;break;
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( double &x,double &y){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , x,false);
			__result->Add(HX_CSTRING("y") , y,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",139)
	Dynamic transformOriginPoint = _Function_1_1::Block(x,y);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",144)
	return transformOriginPoint;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getComputedTransformOrigin,return )

::cocktail::core::geom::Matrix VisualEffectStylesComputer_obj::getComputedTransform( ::cocktail::core::style::AbstractCoreStyle style){
	HX_SOURCE_PUSH("VisualEffectStylesComputer_obj::getComputedTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",153)
	Array< ::cocktail::core::style::TransformFunction > transformFunctions;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",154)
	Dynamic transformOrigin = style->getComputedStyle()->__Field(HX_CSTRING("transformOrigin"));
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",157)
	::cocktail::core::geom::Matrix matrix = ::cocktail::core::geom::Matrix_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",160)
	{
::cocktail::core::style::Transform _switch_4 = (style->getTransform());
		switch((_switch_4)->GetIndex()){
			case 1: {
				Array< ::cocktail::core::style::TransformFunction > value = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",162)
					transformFunctions = value;
				}
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",165)
				transformFunctions = Array_obj< ::cocktail::core::style::TransformFunction >::__new();
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",170)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",170)
		int _g1 = (int)0;
		int _g = transformFunctions->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",170)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",170)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",172)
			::cocktail::core::style::TransformFunction transformFunction = transformFunctions->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",174)
			{
::cocktail::core::style::TransformFunction _switch_5 = (transformFunction);
				switch((_switch_5)->GetIndex()){
					case 0: {
						Dynamic data = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",177)
							matrix->concatenate(::cocktail::core::geom::Matrix_obj::__new(data));
						}
					}
					;break;
					case 7: {
						::cocktail::core::unit::Angle value = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",182)
							double angle = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getRadFromAngle(value));
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",183)
							matrix->rotate(angle,transformOrigin);
						}
					}
					;break;
					case 4: {
						double sys = _switch_5->__Param(1);
						double sx = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",186)
							matrix->scale(sx,sys,transformOrigin);
						}
					}
					;break;
					case 5: {
						double sx = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",190)
							matrix->scale(sx,(int)1,transformOrigin);
						}
					}
					;break;
					case 6: {
						double sy = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",194)
							matrix->scale((int)1,sy,transformOrigin);
						}
					}
					;break;
					case 10: {
						::cocktail::core::unit::Angle angleY = _switch_5->__Param(1);
						::cocktail::core::unit::Angle angleX = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",199)
							double skewX = ::cocktail::core::unit::UnitManager_obj::getRadFromAngle(angleX);
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",200)
							double skewY = ::cocktail::core::unit::UnitManager_obj::getRadFromAngle(angleY);
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",201)
							matrix->skew(skewX,skewY,transformOrigin);
						}
					}
					;break;
					case 8: {
						::cocktail::core::unit::Angle angleX = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",205)
							double skewX = ::cocktail::core::unit::UnitManager_obj::getRadFromAngle(angleX);
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",206)
							matrix->skew(skewX,(int)1,transformOrigin);
						}
					}
					;break;
					case 9: {
						::cocktail::core::unit::Angle angleY = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",210)
							double skewY = ::cocktail::core::unit::UnitManager_obj::getRadFromAngle(angleY);
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",211)
							matrix->skew((int)1,skewY,transformOrigin);
						}
					}
					;break;
					case 1: {
						::cocktail::core::style::Translation ty = _switch_5->__Param(1);
						::cocktail::core::style::Translation tx = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",215)
							double translationX = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,tx,style->getComputedStyle()->__Field(HX_CSTRING("width")));
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",216)
							double translationY = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,ty,style->getComputedStyle()->__Field(HX_CSTRING("height")));
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",217)
							matrix->translate(translationX,translationY);
						}
					}
					;break;
					case 2: {
						::cocktail::core::style::Translation tx = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",221)
							double translationX = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,tx,style->getComputedStyle()->__Field(HX_CSTRING("width")));
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",222)
							matrix->translate(translationX,0.0);
						}
					}
					;break;
					case 3: {
						::cocktail::core::style::Translation ty = _switch_5->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",226)
							double translationY = ::cocktail::core::style::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,ty,style->getComputedStyle()->__Field(HX_CSTRING("height")));
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",227)
							matrix->translate(0.0,translationY);
						}
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",231)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getComputedTransform,return )

double VisualEffectStylesComputer_obj::getComputedTranslation( ::cocktail::core::style::AbstractCoreStyle style,::cocktail::core::style::Translation translation,int percentReference){
	HX_SOURCE_PUSH("VisualEffectStylesComputer_obj::getComputedTranslation")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",239)
	double computedTranslation;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",241)
	{
::cocktail::core::style::Translation _switch_6 = (translation);
		switch((_switch_6)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",243)
					computedTranslation = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 1: {
				int value = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",246)
					computedTranslation = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,percentReference);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/VisualEffectStylesComputer.hx",250)
	return computedTranslation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VisualEffectStylesComputer_obj,getComputedTranslation,return )


VisualEffectStylesComputer_obj::VisualEffectStylesComputer_obj()
{
}

void VisualEffectStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VisualEffectStylesComputer);
	HX_MARK_END_CLASS();
}

Dynamic VisualEffectStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedTransform") ) { return getComputedTransform_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedVisibility") ) { return getComputedVisibility_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getComputedTranslation") ) { return getComputedTranslation_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getComputedTransformOrigin") ) { return getComputedTransformOrigin_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic VisualEffectStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void VisualEffectStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compute"),
	HX_CSTRING("getComputedVisibility"),
	HX_CSTRING("getComputedTransformOrigin"),
	HX_CSTRING("getComputedTransform"),
	HX_CSTRING("getComputedTranslation"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class VisualEffectStylesComputer_obj::__mClass;

void VisualEffectStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.VisualEffectStylesComputer"), hx::TCanCast< VisualEffectStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void VisualEffectStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
