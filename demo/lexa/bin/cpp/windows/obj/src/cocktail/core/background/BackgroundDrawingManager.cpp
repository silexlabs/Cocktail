#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_background_BackgroundDrawingManager
#include <cocktail/core/background/BackgroundDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_FillStyleValue
#include <cocktail/core/dom/FillStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_GradientTypeValue
#include <cocktail/core/dom/GradientTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_LineStyleValue
#include <cocktail/core/dom/LineStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_drawing_AbstractDrawingManager
#include <cocktail/core/drawing/AbstractDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundRepeatValue
#include <cocktail/core/style/BackgroundRepeatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Angle
#include <cocktail/core/unit/Angle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientAngle
#include <cocktail/core/unit/GradientAngle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientCornerValue
#include <cocktail/core/unit/GradientCornerValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientSideValue
#include <cocktail/core/unit/GradientSideValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientStopValue
#include <cocktail/core/unit/GradientStopValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientValue
#include <cocktail/core/unit/GradientValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_DrawingManager
#include <cocktail/port/flash_player/DrawingManager.h>
#endif
namespace cocktail{
namespace core{
namespace background{

Void BackgroundDrawingManager_obj::__construct(Dynamic nativeElement,Dynamic backgroundBox)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",40)
	super::__construct(nativeElement,::Math_obj::round(backgroundBox->__Field(HX_CSTRING("width"))),::Math_obj::round(backgroundBox->__Field(HX_CSTRING("height"))));
}
;
	return null();
}

BackgroundDrawingManager_obj::~BackgroundDrawingManager_obj() { }

Dynamic BackgroundDrawingManager_obj::__CreateEmpty() { return  new BackgroundDrawingManager_obj; }
hx::ObjectPtr< BackgroundDrawingManager_obj > BackgroundDrawingManager_obj::__new(Dynamic nativeElement,Dynamic backgroundBox)
{  hx::ObjectPtr< BackgroundDrawingManager_obj > result = new BackgroundDrawingManager_obj();
	result->__construct(nativeElement,backgroundBox);
	return result;}

Dynamic BackgroundDrawingManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BackgroundDrawingManager_obj > result = new BackgroundDrawingManager_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BackgroundDrawingManager_obj::drawBackgroundImage( Dynamic nativeImage,Dynamic backgroundPositioningBox,Dynamic backgroundPaintingBox,int intrinsicWidth,int intrinsicHeight,double intrinsicRatio,Dynamic computedBackgroundSize,Dynamic computedBackgroundPosition,Dynamic backgroundRepeat){
{
		HX_SOURCE_PUSH("BackgroundDrawingManager_obj::drawBackgroundImage")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",66)
		int totalWidth = (::Math_obj::round(computedBackgroundPosition->__Field(HX_CSTRING("x"))) + ::Math_obj::round(backgroundPositioningBox->__Field(HX_CSTRING("x"))));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",67)
		int maxWidth = ::Math_obj::round((backgroundPaintingBox->__Field(HX_CSTRING("x")) + backgroundPaintingBox->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",68)
		int imageWidth = ::Math_obj::round(computedBackgroundSize->__Field(HX_CSTRING("width")));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",70)
		{
::cocktail::core::style::BackgroundRepeatValue _switch_1 = (backgroundRepeat->__Field(HX_CSTRING("x")));
			switch((_switch_1)->GetIndex()){
				case 3: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",72)
					maxWidth = (totalWidth + imageWidth);
				}
				;break;
				case 0: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",75)
					while(((totalWidth > backgroundPaintingBox->__Field(HX_CSTRING("x"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",77)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
				case 1: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",82)
					imageWidth = ::Math_obj::round((double(backgroundPositioningBox->__Field(HX_CSTRING("width"))) / double(computedBackgroundSize->__Field(HX_CSTRING("width")))));
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",83)
					while(((totalWidth > backgroundPaintingBox->__Field(HX_CSTRING("x"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",84)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
				case 2: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",88)
					while(((totalWidth > backgroundPaintingBox->__Field(HX_CSTRING("x"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",90)
						hx::SubEq(totalWidth,imageWidth);
					}
				}
				;break;
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",94)
		int initialWidth = totalWidth;
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",96)
		double totalHeight = (computedBackgroundPosition->__Field(HX_CSTRING("y")) + ::Math_obj::round(backgroundPositioningBox->__Field(HX_CSTRING("y"))));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",97)
		double maxHeight = (backgroundPaintingBox->__Field(HX_CSTRING("y")) + backgroundPaintingBox->__Field(HX_CSTRING("height")));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",98)
		double imageHeight = computedBackgroundSize->__Field(HX_CSTRING("height"));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",100)
		{
::cocktail::core::style::BackgroundRepeatValue _switch_2 = (backgroundRepeat->__Field(HX_CSTRING("y")));
			switch((_switch_2)->GetIndex()){
				case 3: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",102)
					maxHeight = (totalHeight + imageHeight);
				}
				;break;
				case 0: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",105)
					while(((totalHeight > backgroundPaintingBox->__Field(HX_CSTRING("y"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",107)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
				case 1: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",112)
					imageHeight = (double(backgroundPositioningBox->__Field(HX_CSTRING("height"))) / double(computedBackgroundSize->__Field(HX_CSTRING("height"))));
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",113)
					while(((totalHeight > backgroundPaintingBox->__Field(HX_CSTRING("y"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",114)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
				case 2: {
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",118)
					while(((totalHeight > backgroundPaintingBox->__Field(HX_CSTRING("y"))))){
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",120)
						hx::SubEq(totalHeight,imageHeight);
					}
				}
				;break;
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",125)
		double initialHeight = totalHeight;
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",127)
		while(((totalHeight < maxHeight))){
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",129)
			::cocktail::core::geom::Matrix matrix = ::cocktail::core::geom::Matrix_obj::__new(null());
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",131)
			matrix->translate(totalWidth,totalHeight);
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , 0.0,false);
					__result->Add(HX_CSTRING("y") , 0.0,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",133)
			matrix->scale((double(imageWidth) / double(intrinsicWidth)),(double(imageHeight) / double(intrinsicHeight)),_Function_2_1::Block());
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",135)
			this->drawImage(nativeImage,matrix,backgroundPaintingBox);
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",137)
			hx::AddEq(totalWidth,imageWidth);
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",139)
			if (((totalWidth >= maxWidth))){
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",141)
				totalWidth = initialWidth;
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",142)
				hx::AddEq(totalHeight,imageHeight);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(BackgroundDrawingManager_obj,drawBackgroundImage,(void))

Void BackgroundDrawingManager_obj::drawBackgroundColor( Dynamic color,Dynamic backgroundPaintingBox){
{
		HX_SOURCE_PUSH("BackgroundDrawingManager_obj::drawBackgroundColor")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",156)
		::cocktail::core::dom::FillStyleValue fillStyle = ::cocktail::core::dom::FillStyleValue_obj::monochrome(color);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",157)
		::cocktail::core::dom::LineStyleValue lineStyle = ::cocktail::core::dom::LineStyleValue_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",159)
		this->beginFill(fillStyle,lineStyle);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",160)
		this->drawRect(::Math_obj::round(backgroundPaintingBox->__Field(HX_CSTRING("x"))),::Math_obj::round(backgroundPaintingBox->__Field(HX_CSTRING("y"))),::Math_obj::round(backgroundPaintingBox->__Field(HX_CSTRING("width"))),::Math_obj::round(backgroundPaintingBox->__Field(HX_CSTRING("height"))),null());
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",162)
		this->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BackgroundDrawingManager_obj,drawBackgroundColor,(void))

Void BackgroundDrawingManager_obj::drawBackgroundGradient( ::cocktail::core::unit::GradientValue gradient,Dynamic backgroundPositioningBox,Dynamic backgroundPaintingBox,Dynamic computedBackgroundSize,Dynamic computedBackgroundPosition,Dynamic backgroundRepeat){
{
		HX_SOURCE_PUSH("BackgroundDrawingManager_obj::drawBackgroundGradient")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",183)
		::cocktail::port::flash_player::DrawingManager gradientSurface = ::cocktail::port::flash_player::DrawingManager_obj::__new(::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::graphic_dyn()),computedBackgroundSize->__Field(HX_CSTRING("width")),computedBackgroundSize->__Field(HX_CSTRING("height")));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",185)
		::cocktail::core::dom::FillStyleValue fillStyle;
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",186)
		::cocktail::core::dom::LineStyleValue lineStyle = ::cocktail::core::dom::LineStyleValue_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",188)
		{
::cocktail::core::unit::GradientValue _switch_3 = (gradient);
			switch((_switch_3)->GetIndex()){
				case 0: {
					Dynamic value = _switch_3->__Param(0);
{
						struct _Function_2_1{
							inline static Dynamic Block( ::cocktail::core::background::BackgroundDrawingManager_obj *__this,Dynamic &value){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("gradientType") , ::cocktail::core::dom::GradientTypeValue_obj::linear_dyn(),false);
								__result->Add(HX_CSTRING("gradientStops") , __this->getGradientStops(value->__Field(HX_CSTRING("colorStops"))),false);
								__result->Add(HX_CSTRING("rotation") , __this->getRotation(value->__Field(HX_CSTRING("angle"))),false);
								return __result;
							}
						};
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",192)
						Dynamic gradientStyle = _Function_2_1::Block(this,value);
						HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",198)
						fillStyle = ::cocktail::core::dom::FillStyleValue_obj::gradient(gradientStyle);
					}
				}
				;break;
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",201)
		gradientSurface->beginFill(fillStyle,lineStyle);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",202)
		gradientSurface->drawRect((int)0,(int)0,computedBackgroundSize->__Field(HX_CSTRING("width")),computedBackgroundSize->__Field(HX_CSTRING("height")),null());
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",203)
		gradientSurface->endFill();
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",205)
		this->drawBackgroundImage(gradientSurface->getNativeElement(),backgroundPositioningBox,backgroundPaintingBox,computedBackgroundSize->__Field(HX_CSTRING("width")),computedBackgroundSize->__Field(HX_CSTRING("height")),(double(computedBackgroundSize->__Field(HX_CSTRING("width"))) / double(computedBackgroundSize->__Field(HX_CSTRING("height")))),computedBackgroundSize,computedBackgroundPosition,backgroundRepeat);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BackgroundDrawingManager_obj,drawBackgroundGradient,(void))

Dynamic BackgroundDrawingManager_obj::getGradientStops( Dynamic value){
	HX_SOURCE_PUSH("BackgroundDrawingManager_obj::getGradientStops")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",216)
	Dynamic gradientStopsData = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",218)
	{
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",218)
		int _g1 = (int)0;
		int _g = value->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",218)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",218)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",220)
			int ratio;
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",222)
			{
::cocktail::core::unit::GradientStopValue _switch_4 = (value->__GetItem(i)->__Field(HX_CSTRING("stop")));
				switch((_switch_4)->GetIndex()){
					case 0: {
						::cocktail::core::unit::Length value1 = _switch_4->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",224)
							ratio = (int)0;
						}
					}
					;break;
					case 1: {
						int value1 = _switch_4->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",228)
							ratio = value1;
						}
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",232)
			Dynamic color = ::cocktail::core::unit::UnitManager_obj::getColorDataFromCSSColor(value->__GetItem(i)->__Field(HX_CSTRING("color")));
			struct _Function_3_1{
				inline static Dynamic Block( Dynamic &color,int &ratio){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("colorStop") , color,false);
					__result->Add(HX_CSTRING("ratio") , ratio,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",233)
			gradientStopsData->__Field(HX_CSTRING("push"))(_Function_3_1::Block(color,ratio));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",236)
	return gradientStopsData;
}


HX_DEFINE_DYNAMIC_FUNC1(BackgroundDrawingManager_obj,getGradientStops,return )

int BackgroundDrawingManager_obj::getRotation( ::cocktail::core::unit::GradientAngle value){
	HX_SOURCE_PUSH("BackgroundDrawingManager_obj::getRotation")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",242)
	int rotation;
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",244)
	{
::cocktail::core::unit::GradientAngle _switch_5 = (value);
		switch((_switch_5)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Angle value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",246)
					rotation = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getDegreeFromAngle(value1));
				}
			}
			;break;
			case 1: {
				::cocktail::core::unit::GradientSideValue value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",249)
					{
::cocktail::core::unit::GradientSideValue _switch_6 = (value1);
						switch((_switch_6)->GetIndex()){
							case 0: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",253)
								rotation = (int)0;
							}
							;break;
							case 3: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",256)
								rotation = (int)90;
							}
							;break;
							case 2: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",259)
								rotation = (int)180;
							}
							;break;
							case 1: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",262)
								rotation = (int)270;
							}
							;break;
						}
					}
				}
			}
			;break;
			case 2: {
				::cocktail::core::unit::GradientCornerValue value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",267)
					{
::cocktail::core::unit::GradientCornerValue _switch_7 = (value1);
						switch((_switch_7)->GetIndex()){
							case 0: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",271)
								rotation = (int)45;
							}
							;break;
							case 1: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",274)
								rotation = (int)135;
							}
							;break;
							case 2: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",277)
								rotation = (int)225;
							}
							;break;
							case 3: {
								HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",280)
								rotation = (int)315;
							}
							;break;
						}
					}
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundDrawingManager.hx",286)
	return rotation;
}


HX_DEFINE_DYNAMIC_FUNC1(BackgroundDrawingManager_obj,getRotation,return )


BackgroundDrawingManager_obj::BackgroundDrawingManager_obj()
{
}

void BackgroundDrawingManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BackgroundDrawingManager);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BackgroundDrawingManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"getRotation") ) { return getRotation_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getGradientStops") ) { return getGradientStops_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"drawBackgroundImage") ) { return drawBackgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"drawBackgroundColor") ) { return drawBackgroundColor_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"drawBackgroundGradient") ) { return drawBackgroundGradient_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BackgroundDrawingManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BackgroundDrawingManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("drawBackgroundImage"),
	HX_CSTRING("drawBackgroundColor"),
	HX_CSTRING("drawBackgroundGradient"),
	HX_CSTRING("getGradientStops"),
	HX_CSTRING("getRotation"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BackgroundDrawingManager_obj::__mClass;

void BackgroundDrawingManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.background.BackgroundDrawingManager"), hx::TCanCast< BackgroundDrawingManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BackgroundDrawingManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace background
