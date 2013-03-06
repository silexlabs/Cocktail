#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTransformFunctionValue
#include <cocktail/core/css/CSSTransformFunctionValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTranslationValue
#include <cocktail/core/css/CSSTranslationValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_VisualEffectStylesComputer
#include <cocktail/core/layout/computer/VisualEffectStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{

Void VisualEffectStylesComputer_obj::__construct()
{
HX_STACK_PUSH("VisualEffectStylesComputer::new","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",33);
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

Void VisualEffectStylesComputer_obj::compute( ::cocktail::core::css::CoreStyle style){
{
		HX_STACK_PUSH("VisualEffectStylesComputer::compute","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",48);
		HX_STACK_ARG(style,"style");
		HX_STACK_LINE(50)
		style->usedValues->transformOrigin = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTransformOrigin(style);
		HX_STACK_LINE(53)
		style->usedValues->transform = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTransform(style);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,compute,(void))

::cocktail::core::geom::PointVO VisualEffectStylesComputer_obj::getComputedTransformOrigin( ::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("VisualEffectStylesComputer::getComputedTransformOrigin","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",65);
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(66)
	Float x = 0.0;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(67)
	Float y = 0.0;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(69)
	::cocktail::core::css::CSSPropertyValue transformOriginX = null();		HX_STACK_VAR(transformOriginX,"transformOriginX");
	HX_STACK_LINE(70)
	::cocktail::core::css::CSSPropertyValue transformOriginY = null();		HX_STACK_VAR(transformOriginY,"transformOriginY");
	HX_STACK_LINE(72)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (style->getComputedOrInitialProperty((int)60));
		switch((_switch_1)->GetIndex()){
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_1->__Param(0);
{
					HX_STACK_LINE(75)
					transformOriginX = value->__get((int)0);
					HX_STACK_LINE(76)
					transformOriginY = value->__get((int)1);
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(83)
	{
		::cocktail::core::css::CSSPropertyValue _switch_2 = (transformOriginX);
		switch((_switch_2)->GetIndex()){
			case 18: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(85)
					x = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(88)
					x = (style->usedValues->width * ((value * 0.01)));
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_2->__Param(0);
{
					HX_STACK_LINE(91)
					{
						::cocktail::core::css::CSSKeywordValue _switch_3 = (value);
						switch((_switch_3)->GetIndex()){
							case 11: {
								HX_STACK_LINE(94)
								x = (style->usedValues->width * 0.);
							}
							;break;
							case 13: {
								HX_STACK_LINE(97)
								x = (style->usedValues->width * 0.5);
							}
							;break;
							case 12: {
								HX_STACK_LINE(100)
								x = style->usedValues->width;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(111)
	{
		::cocktail::core::css::CSSPropertyValue _switch_4 = (transformOriginY);
		switch((_switch_4)->GetIndex()){
			case 18: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(113)
					y = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(116)
					y = (style->usedValues->width * ((value * 0.01)));
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_4->__Param(0);
{
					HX_STACK_LINE(119)
					{
						::cocktail::core::css::CSSKeywordValue _switch_5 = (value);
						switch((_switch_5)->GetIndex()){
							case 22: {
								HX_STACK_LINE(122)
								y = (style->usedValues->width * 0.);
							}
							;break;
							case 13: {
								HX_STACK_LINE(125)
								y = (style->usedValues->width * 0.5);
							}
							;break;
							case 25: {
								HX_STACK_LINE(128)
								y = style->usedValues->width;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(139)
	::cocktail::core::geom::PointVO transformOriginPoint = ::cocktail::core::geom::PointVO_obj::__new(x,y);		HX_STACK_VAR(transformOriginPoint,"transformOriginPoint");
	HX_STACK_LINE(141)
	return transformOriginPoint;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getComputedTransformOrigin,return )

::cocktail::core::geom::Matrix VisualEffectStylesComputer_obj::getComputedTransform( ::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("VisualEffectStylesComputer::getComputedTransform","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",149);
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(152)
	if ((style->isNone(style->getComputedOrInitialProperty((int)61)))){
		HX_STACK_LINE(153)
		return ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	}
	HX_STACK_LINE(158)
	::cocktail::core::geom::Matrix matrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(160)
	Array< ::cocktail::core::css::CSSTransformFunctionValue > transformFunctions = Array_obj< ::cocktail::core::css::CSSTransformFunctionValue >::__new();		HX_STACK_VAR(transformFunctions,"transformFunctions");
	HX_STACK_LINE(161)
	::cocktail::core::geom::PointVO transformOrigin = style->usedValues->transformOrigin;		HX_STACK_VAR(transformOrigin,"transformOrigin");
	HX_STACK_LINE(164)
	{
		::cocktail::core::css::CSSPropertyValue _switch_6 = (style->getComputedOrInitialProperty((int)61));
		switch((_switch_6)->GetIndex()){
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_6->__Param(0);
{
					HX_STACK_LINE(167)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = value->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(167)
					while(((_g1 < _g))){
						HX_STACK_LINE(167)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(169)
						{
							::cocktail::core::css::CSSPropertyValue _switch_7 = (value->__get(i));
							switch((_switch_7)->GetIndex()){
								case 21: {
									::cocktail::core::css::CSSTransformFunctionValue value1 = _switch_7->__Param(0);
{
										HX_STACK_LINE(171)
										transformFunctions->push(value1);
									}
								}
								;break;
								default: {
								}
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(184)
	matrix->translate(transformOrigin->x,transformOrigin->y);
	HX_STACK_LINE(187)
	{
		HX_STACK_LINE(187)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = transformFunctions->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(187)
		while(((_g1 < _g))){
			HX_STACK_LINE(187)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(189)
			::cocktail::core::css::CSSTransformFunctionValue transformFunction = transformFunctions->__get(i);		HX_STACK_VAR(transformFunction,"transformFunction");
			HX_STACK_LINE(191)
			{
				::cocktail::core::css::CSSTransformFunctionValue _switch_8 = (transformFunction);
				switch((_switch_8)->GetIndex()){
					case 0: {
						Float f = _switch_8->__Param(5);
						Float e = _switch_8->__Param(4);
						Float d = _switch_8->__Param(3);
						Float c = _switch_8->__Param(2);
						Float b = _switch_8->__Param(1);
						Float a = _switch_8->__Param(0);
{
							HX_STACK_LINE(194)
							matrix->concatenate(::cocktail::core::geom::Matrix_obj::__new(a,b,c,d,e,f));
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSAngleValue value = _switch_8->__Param(0);
{
							HX_STACK_LINE(199)
							Float angle = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getRadFromAngle(value);		HX_STACK_VAR(angle,"angle");
							HX_STACK_LINE(200)
							matrix->rotate(angle);
						}
					}
					;break;
					case 4: {
						Float sy = _switch_8->__Param(1);
						Float sx = _switch_8->__Param(0);
{
							HX_STACK_LINE(203)
							matrix->scale(sx,sy);
						}
					}
					;break;
					case 5: {
						Float sx = _switch_8->__Param(0);
{
							HX_STACK_LINE(207)
							matrix->scale(sx,(int)1);
						}
					}
					;break;
					case 6: {
						Float sy = _switch_8->__Param(0);
{
							HX_STACK_LINE(211)
							matrix->scale((int)1,sy);
						}
					}
					;break;
					case 10: {
						::cocktail::core::css::CSSAngleValue angleY = _switch_8->__Param(1);
						::cocktail::core::css::CSSAngleValue angleX = _switch_8->__Param(0);
{
							HX_STACK_LINE(216)
							Float skewX = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getRadFromAngle(angleX);		HX_STACK_VAR(skewX,"skewX");
							HX_STACK_LINE(217)
							Float skewY = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getRadFromAngle(angleY);		HX_STACK_VAR(skewY,"skewY");
							HX_STACK_LINE(218)
							matrix->skew(skewX,skewY);
						}
					}
					;break;
					case 8: {
						::cocktail::core::css::CSSAngleValue angleX = _switch_8->__Param(0);
{
							HX_STACK_LINE(222)
							Float skewX = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getRadFromAngle(angleX);		HX_STACK_VAR(skewX,"skewX");
							HX_STACK_LINE(223)
							matrix->skew(skewX,(int)0);
						}
					}
					;break;
					case 9: {
						::cocktail::core::css::CSSAngleValue angleY = _switch_8->__Param(0);
{
							HX_STACK_LINE(227)
							Float skewY = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getRadFromAngle(angleY);		HX_STACK_VAR(skewY,"skewY");
							HX_STACK_LINE(228)
							matrix->skew((int)0,skewY);
						}
					}
					;break;
					case 1: {
						::cocktail::core::css::CSSTranslationValue ty = _switch_8->__Param(1);
						::cocktail::core::css::CSSTranslationValue tx = _switch_8->__Param(0);
{
							HX_STACK_LINE(232)
							Float translationX = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,tx,style->usedValues->width);		HX_STACK_VAR(translationX,"translationX");
							HX_STACK_LINE(233)
							Float translationY = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,ty,style->usedValues->height);		HX_STACK_VAR(translationY,"translationY");
							HX_STACK_LINE(234)
							matrix->translate(translationX,translationY);
						}
					}
					;break;
					case 2: {
						::cocktail::core::css::CSSTranslationValue tx = _switch_8->__Param(0);
{
							HX_STACK_LINE(238)
							Float translationX = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,tx,style->usedValues->width);		HX_STACK_VAR(translationX,"translationX");
							HX_STACK_LINE(239)
							matrix->translate(translationX,0.0);
						}
					}
					;break;
					case 3: {
						::cocktail::core::css::CSSTranslationValue ty = _switch_8->__Param(0);
{
							HX_STACK_LINE(243)
							Float translationY = ::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::getComputedTranslation(style,ty,style->usedValues->height);		HX_STACK_VAR(translationY,"translationY");
							HX_STACK_LINE(244)
							matrix->translate(0.0,translationY);
						}
					}
					;break;
				}
			}
		}
	}
	HX_STACK_LINE(250)
	matrix->translate((transformOrigin->x * (int)-1),(transformOrigin->y * (int)-1));
	HX_STACK_LINE(252)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getComputedTransform,return )

Float VisualEffectStylesComputer_obj::getComputedTranslation( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSTranslationValue translation,Float percentReference){
	HX_STACK_PUSH("VisualEffectStylesComputer::getComputedTranslation","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",259);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(translation,"translation");
	HX_STACK_ARG(percentReference,"percentReference");
	HX_STACK_LINE(260)
	Float computedTranslation = 0.0;		HX_STACK_VAR(computedTranslation,"computedTranslation");
	HX_STACK_LINE(262)
	{
		::cocktail::core::css::CSSTranslationValue _switch_9 = (translation);
		switch((_switch_9)->GetIndex()){
			case 0: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(264)
					computedTranslation = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(267)
					computedTranslation = (percentReference * ((value * 0.01)));
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(273)
	return computedTranslation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VisualEffectStylesComputer_obj,getComputedTranslation,return )

Float VisualEffectStylesComputer_obj::getRadFromAngle( ::cocktail::core::css::CSSAngleValue value){
	HX_STACK_PUSH("VisualEffectStylesComputer::getRadFromAngle","cocktail/core/layout/computer/VisualEffectStylesComputer.hx",280);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(281)
	Float angle;		HX_STACK_VAR(angle,"angle");
	HX_STACK_LINE(283)
	{
		::cocktail::core::css::CSSAngleValue _switch_10 = (value);
		switch((_switch_10)->GetIndex()){
			case 0: {
				Float value1 = _switch_10->__Param(0);
{
					HX_STACK_LINE(285)
					angle = (value1 * ((Float(::Math_obj::PI) / Float((int)180))));
				}
			}
			;break;
			case 2: {
				Float value1 = _switch_10->__Param(0);
{
					HX_STACK_LINE(288)
					angle = value1;
				}
			}
			;break;
			case 3: {
				Float value1 = _switch_10->__Param(0);
{
					HX_STACK_LINE(291)
					angle = ((value1 * (int)360) * ((Float(::Math_obj::PI) / Float((int)180))));
				}
			}
			;break;
			case 1: {
				Float value1 = _switch_10->__Param(0);
{
					HX_STACK_LINE(294)
					angle = (value1 * ((Float(::Math_obj::PI) / Float((int)200))));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(298)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VisualEffectStylesComputer_obj,getRadFromAngle,return )


VisualEffectStylesComputer_obj::VisualEffectStylesComputer_obj()
{
}

void VisualEffectStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VisualEffectStylesComputer);
	HX_MARK_END_CLASS();
}

void VisualEffectStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic VisualEffectStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getRadFromAngle") ) { return getRadFromAngle_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedTransform") ) { return getComputedTransform_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getComputedTranslation") ) { return getComputedTranslation_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getComputedTransformOrigin") ) { return getComputedTransformOrigin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VisualEffectStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void VisualEffectStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compute"),
	HX_CSTRING("getComputedTransformOrigin"),
	HX_CSTRING("getComputedTransform"),
	HX_CSTRING("getComputedTranslation"),
	HX_CSTRING("getRadFromAngle"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VisualEffectStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VisualEffectStylesComputer_obj::__mClass,"__mClass");
};

Class VisualEffectStylesComputer_obj::__mClass;

void VisualEffectStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.VisualEffectStylesComputer"), hx::TCanCast< VisualEffectStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VisualEffectStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
