#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorKeyword
#include <cocktail/core/css/CSSColorKeyword.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSValueConverter
#include <cocktail/core/css/CSSValueConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSValueConverter_obj::__construct()
{
HX_STACK_PUSH("CSSValueConverter::new","cocktail/core/css/CSSValueConverter.hx",31);
{
}
;
	return null();
}

CSSValueConverter_obj::~CSSValueConverter_obj() { }

Dynamic CSSValueConverter_obj::__CreateEmpty() { return  new CSSValueConverter_obj; }
hx::ObjectPtr< CSSValueConverter_obj > CSSValueConverter_obj::__new()
{  hx::ObjectPtr< CSSValueConverter_obj > result = new CSSValueConverter_obj();
	result->__construct();
	return result;}

Dynamic CSSValueConverter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSValueConverter_obj > result = new CSSValueConverter_obj();
	result->__construct();
	return result;}

Float CSSValueConverter_obj::getPixelFromLength( ::cocktail::core::css::CSSLengthValue length,Float emReference,Float exReference){
	HX_STACK_PUSH("CSSValueConverter::getPixelFromLength","cocktail/core/css/CSSValueConverter.hx",56);
	HX_STACK_ARG(length,"length");
	HX_STACK_ARG(emReference,"emReference");
	HX_STACK_ARG(exReference,"exReference");
	HX_STACK_LINE(57)
	Float lengthValue;		HX_STACK_VAR(lengthValue,"lengthValue");
	HX_STACK_LINE(59)
	{
		::cocktail::core::css::CSSLengthValue _switch_1 = (length);
		switch((_switch_1)->GetIndex()){
			case 0: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(61)
					lengthValue = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(64)
					lengthValue = (Float((value * ((Float(((int)72 * ((Float((int)1) / Float(0.75))))) / Float(2.54))))) / Float((int)10));
				}
			}
			;break;
			case 1: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(67)
					lengthValue = (value * ((Float(((int)72 * ((Float((int)1) / Float(0.75))))) / Float(2.54))));
				}
			}
			;break;
			case 3: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(70)
					lengthValue = (Float(value) / Float(0.75));
				}
			}
			;break;
			case 5: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(73)
					lengthValue = (value * (((int)72 * ((Float((int)1) / Float(0.75))))));
				}
			}
			;break;
			case 4: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(76)
					lengthValue = (value * (((int)12 * ((Float((int)1) / Float(0.75))))));
				}
			}
			;break;
			case 6: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(79)
					lengthValue = (emReference * value);
				}
			}
			;break;
			case 7: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(82)
					lengthValue = (exReference * value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(86)
	return lengthValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSValueConverter_obj,getPixelFromLength,return )

Float CSSValueConverter_obj::getBorderWidthFromBorderWidthKeyword( ::cocktail::core::css::CSSKeywordValue value){
	HX_STACK_PUSH("CSSValueConverter::getBorderWidthFromBorderWidthKeyword","cocktail/core/css/CSSValueConverter.hx",90);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(90)
	{
		::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
		switch((_switch_2)->GetIndex()){
			case 73: {
				HX_STACK_LINE(93)
				return ::cocktail::core::config::Config_obj::getInstance()->thinBorderWidth;
			}
			;break;
			case 61: {
				HX_STACK_LINE(96)
				return ::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth;
			}
			;break;
			case 74: {
				HX_STACK_LINE(99)
				return ::cocktail::core::config::Config_obj::getInstance()->thickBorderWidth;
			}
			;break;
			default: {
				HX_STACK_LINE(102)
				hx::Throw (HX_CSTRING("not a valid border width keyword"));
			}
		}
	}
	HX_STACK_LINE(90)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getBorderWidthFromBorderWidthKeyword,return )

Array< ::String > CSSValueConverter_obj::getFontFamilyAsStringArray( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CSSValueConverter::getFontFamilyAsStringArray","cocktail/core/css/CSSValueConverter.hx",112);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(113)
	Array< ::String > fontNames = Array_obj< ::String >::__new();		HX_STACK_VAR(fontNames,"fontNames");
	HX_STACK_LINE(115)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (value);
		switch((_switch_3)->GetIndex()){
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value1 = _switch_3->__Param(0);
{
					HX_STACK_LINE(118)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = value1->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(118)
					while(((_g1 < _g))){
						HX_STACK_LINE(118)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(120)
						{
							::cocktail::core::css::CSSPropertyValue _switch_4 = (value1->__get(i));
							switch((_switch_4)->GetIndex()){
								case 6: {
									::String value2 = _switch_4->__Param(0);
{
										HX_STACK_LINE(122)
										fontNames->push(value2);
									}
								}
								;break;
								case 3: {
									::String value2 = _switch_4->__Param(0);
{
										HX_STACK_LINE(125)
										fontNames->push(value2);
									}
								}
								;break;
								default: {
									HX_STACK_LINE(128)
									hx::Throw (HX_CSTRING("Illegal value for font family style"));
								}
							}
						}
					}
				}
			}
			;break;
			case 3: {
				::String value1 = _switch_3->__Param(0);
{
					HX_STACK_LINE(134)
					fontNames = Array_obj< ::String >::__new().Add(value1);
				}
			}
			;break;
			default: {
				HX_STACK_LINE(137)
				hx::Throw (HX_CSTRING("Illegal value for font family style"));
			}
		}
	}
	HX_STACK_LINE(142)
	return fontNames;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getFontFamilyAsStringArray,return )

Float CSSValueConverter_obj::getFontSizeFromAbsoluteSizeValue( ::cocktail::core::css::CSSKeywordValue absoluteSize){
	HX_STACK_PUSH("CSSValueConverter::getFontSizeFromAbsoluteSizeValue","cocktail/core/css/CSSValueConverter.hx",150);
	HX_STACK_ARG(absoluteSize,"absoluteSize");
	HX_STACK_LINE(151)
	Float fontSize = 0.0;		HX_STACK_VAR(fontSize,"fontSize");
	HX_STACK_LINE(153)
	{
		::cocktail::core::css::CSSKeywordValue _switch_5 = (absoluteSize);
		switch((_switch_5)->GetIndex()){
			case 58: {
				HX_STACK_LINE(155)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->xxSmallFontSize;
			}
			;break;
			case 59: {
				HX_STACK_LINE(158)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->xSmallFontSize;
			}
			;break;
			case 60: {
				HX_STACK_LINE(161)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->smallFontSize;
			}
			;break;
			case 61: {
				HX_STACK_LINE(164)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->mediumFontSize;
			}
			;break;
			case 62: {
				HX_STACK_LINE(167)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->largeFontSize;
			}
			;break;
			case 63: {
				HX_STACK_LINE(170)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->xLargeFontSize;
			}
			;break;
			case 64: {
				HX_STACK_LINE(173)
				fontSize = ::cocktail::core::config::Config_obj::getInstance()->xxLargeFontSize;
			}
			;break;
			default: {
				HX_STACK_LINE(176)
				hx::Throw (HX_CSTRING("Illegal keyword value for font size"));
			}
		}
	}
	HX_STACK_LINE(180)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getFontSizeFromAbsoluteSizeValue,return )

Float CSSValueConverter_obj::getFontSizeFromRelativeSizeValue( ::cocktail::core::css::CSSKeywordValue relativeSize,Float parentFontSize){
	HX_STACK_PUSH("CSSValueConverter::getFontSizeFromRelativeSizeValue","cocktail/core/css/CSSValueConverter.hx",188);
	HX_STACK_ARG(relativeSize,"relativeSize");
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_LINE(189)
	Float fontSize = 0.0;		HX_STACK_VAR(fontSize,"fontSize");
	HX_STACK_LINE(191)
	{
		::cocktail::core::css::CSSKeywordValue _switch_6 = (relativeSize);
		switch((_switch_6)->GetIndex()){
			case 65: {
				HX_STACK_LINE(193)
				fontSize = ::cocktail::core::css::CSSValueConverter_obj::getLargerFontSize(parentFontSize);
			}
			;break;
			case 66: {
				HX_STACK_LINE(196)
				fontSize = ::cocktail::core::css::CSSValueConverter_obj::getSmallerFontSize(parentFontSize);
			}
			;break;
			default: {
				HX_STACK_LINE(199)
				hx::Throw (HX_CSTRING("Illegal keyword value for font size"));
			}
		}
	}
	HX_STACK_LINE(203)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSValueConverter_obj,getFontSizeFromRelativeSizeValue,return )

Float CSSValueConverter_obj::getPixelFromPercent( Float percent,Float reference){
	HX_STACK_PUSH("CSSValueConverter::getPixelFromPercent","cocktail/core/css/CSSValueConverter.hx",213);
	HX_STACK_ARG(percent,"percent");
	HX_STACK_ARG(reference,"reference");
	HX_STACK_LINE(213)
	return (reference * ((percent * 0.01)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSValueConverter_obj,getPixelFromPercent,return )

Float CSSValueConverter_obj::getPercentFromPixel( Float pixel,Float reference){
	HX_STACK_PUSH("CSSValueConverter::getPercentFromPixel","cocktail/core/css/CSSValueConverter.hx",224);
	HX_STACK_ARG(pixel,"pixel");
	HX_STACK_ARG(reference,"reference");
	HX_STACK_LINE(224)
	return ((Float(reference) / Float(pixel)) * (int)100);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSValueConverter_obj,getPercentFromPixel,return )

::cocktail::core::css::CSSColorValue CSSValueConverter_obj::getComputedCSSColorFromCSSColor( ::cocktail::core::css::CSSColorValue colorProperty,::cocktail::core::css::CSSColorValue currentColor){
	HX_STACK_PUSH("CSSValueConverter::getComputedCSSColorFromCSSColor","cocktail/core/css/CSSValueConverter.hx",238);
	HX_STACK_ARG(colorProperty,"colorProperty");
	HX_STACK_ARG(currentColor,"currentColor");
	HX_STACK_LINE(238)
	{
		::cocktail::core::css::CSSColorValue _switch_7 = (colorProperty);
		switch((_switch_7)->GetIndex()){
			case 7: {
				::cocktail::core::css::CSSColorKeyword value = _switch_7->__Param(0);
{
					HX_STACK_LINE(241)
					return ::cocktail::core::css::CSSValueConverter_obj::getRGBAColorFromColorKeyword(value);
				}
			}
			;break;
			case 8: {
				HX_STACK_LINE(244)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)0,0.0);
			}
			;break;
			case 0: {
				int blue = _switch_7->__Param(2);
				int green = _switch_7->__Param(1);
				int red = _switch_7->__Param(0);
{
					HX_STACK_LINE(250)
					red = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(red,(int)255,(int)0);
					HX_STACK_LINE(251)
					green = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(green,(int)255,(int)0);
					HX_STACK_LINE(252)
					blue = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(blue,(int)255,(int)0);
					HX_STACK_LINE(254)
					return ::cocktail::core::css::CSSColorValue_obj::RGBA(red,green,blue,1.0);
				}
			}
			;break;
			case 1: {
				Float blue = _switch_7->__Param(2);
				Float green = _switch_7->__Param(1);
				Float red = _switch_7->__Param(0);
{
					HX_STACK_LINE(259)
					red = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(red,(int)100,(int)0);
					HX_STACK_LINE(260)
					green = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(green,(int)100,(int)0);
					HX_STACK_LINE(261)
					blue = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(blue,(int)100,(int)0);
					HX_STACK_LINE(263)
					return ::cocktail::core::css::CSSColorValue_obj::RGBA(::Math_obj::round(((int)255 * ((red * 0.01)))),::Math_obj::round(((int)255 * ((green * 0.01)))),::Math_obj::round(((int)255 * ((blue * 0.01)))),1.0);
				}
			}
			;break;
			case 2: {
				Float alpha = _switch_7->__Param(3);
				int blue = _switch_7->__Param(2);
				int green = _switch_7->__Param(1);
				int red = _switch_7->__Param(0);
{
					HX_STACK_LINE(268)
					red = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(red,(int)255,(int)0);
					HX_STACK_LINE(269)
					green = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(green,(int)255,(int)0);
					HX_STACK_LINE(270)
					blue = ::cocktail::core::css::CSSValueConverter_obj::clampInteger(blue,(int)255,(int)0);
					HX_STACK_LINE(272)
					alpha = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(alpha,1.0,0.0);
					HX_STACK_LINE(274)
					return ::cocktail::core::css::CSSColorValue_obj::RGBA(red,green,blue,alpha);
				}
			}
			;break;
			case 3: {
				Float alpha = _switch_7->__Param(3);
				Float blue = _switch_7->__Param(2);
				Float green = _switch_7->__Param(1);
				Float red = _switch_7->__Param(0);
{
					HX_STACK_LINE(279)
					red = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(red,(int)100,(int)0);
					HX_STACK_LINE(280)
					green = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(green,(int)100,(int)0);
					HX_STACK_LINE(281)
					blue = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(blue,(int)100,(int)0);
					HX_STACK_LINE(283)
					alpha = ::cocktail::core::css::CSSValueConverter_obj::clampNumber(alpha,1.0,0.0);
					HX_STACK_LINE(285)
					return ::cocktail::core::css::CSSColorValue_obj::RGBA(::Math_obj::round(((int)255 * ((red * 0.01)))),::Math_obj::round(((int)255 * ((green * 0.01)))),::Math_obj::round(((int)255 * ((blue * 0.01)))),alpha);
				}
			}
			;break;
			case 5: {
				Float lightness = _switch_7->__Param(2);
				Float saturation = _switch_7->__Param(1);
				Float hue = _switch_7->__Param(0);
{
					HX_STACK_LINE(289)
					hue = (Float((int)360) / Float(hue));
					HX_STACK_LINE(290)
					saturation = (Float((int)100) / Float(saturation));
					HX_STACK_LINE(291)
					lightness = (Float((int)100) / Float(lightness));
					HX_STACK_LINE(293)
					return ::cocktail::core::css::CSSValueConverter_obj::HSLAToRGBA(hue,saturation,lightness,1.0);
				}
			}
			;break;
			case 6: {
				Float alpha = _switch_7->__Param(3);
				Float lightness = _switch_7->__Param(2);
				Float saturation = _switch_7->__Param(1);
				Float hue = _switch_7->__Param(0);
{
					HX_STACK_LINE(297)
					hue = (Float((int)360) / Float(hue));
					HX_STACK_LINE(298)
					saturation = (Float((int)100) / Float(saturation));
					HX_STACK_LINE(299)
					lightness = (Float((int)100) / Float(lightness));
					HX_STACK_LINE(301)
					return ::cocktail::core::css::CSSValueConverter_obj::HSLAToRGBA(hue,saturation,lightness,alpha);
				}
			}
			;break;
			case 4: {
				::String value = _switch_7->__Param(0);
{
					HX_STACK_LINE(307)
					::String paddedHex = HX_CSTRING("");		HX_STACK_VAR(paddedHex,"paddedHex");
					HX_STACK_LINE(308)
					if (((value.length == (int)3))){
						HX_STACK_LINE(310)
						hx::AddEq(paddedHex,value.charAt((int)0));
						HX_STACK_LINE(311)
						hx::AddEq(paddedHex,value.charAt((int)0));
						HX_STACK_LINE(312)
						hx::AddEq(paddedHex,value.charAt((int)1));
						HX_STACK_LINE(313)
						hx::AddEq(paddedHex,value.charAt((int)1));
						HX_STACK_LINE(314)
						hx::AddEq(paddedHex,value.charAt((int)2));
						HX_STACK_LINE(315)
						hx::AddEq(paddedHex,value.charAt((int)2));
					}
					else{
						HX_STACK_LINE(318)
						paddedHex = value;
					}
					HX_STACK_LINE(323)
					return ::cocktail::core::css::CSSValueConverter_obj::hexToRGBA(paddedHex);
				}
			}
			;break;
			case 9: {
				HX_STACK_LINE(325)
				return currentColor;
			}
			;break;
		}
	}
	HX_STACK_LINE(238)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSValueConverter_obj,getComputedCSSColorFromCSSColor,return )

Void CSSValueConverter_obj::getColorVOFromCSSColor( ::cocktail::core::css::CSSColorValue value,::cocktail::core::css::ColorVO colorVO){
{
		HX_STACK_PUSH("CSSValueConverter::getColorVOFromCSSColor","cocktail/core/css/CSSValueConverter.hx",334);
		HX_STACK_ARG(value,"value");
		HX_STACK_ARG(colorVO,"colorVO");
		HX_STACK_LINE(335)
		int colorValue = (int)0;		HX_STACK_VAR(colorValue,"colorValue");
		HX_STACK_LINE(336)
		Float alphaValue = (int)0;		HX_STACK_VAR(alphaValue,"alphaValue");
		HX_STACK_LINE(338)
		{
			::cocktail::core::css::CSSColorValue _switch_8 = (value);
			switch((_switch_8)->GetIndex()){
				case 2: {
					Float alpha = _switch_8->__Param(3);
					int blue = _switch_8->__Param(2);
					int green = _switch_8->__Param(1);
					int red = _switch_8->__Param(0);
{
						HX_STACK_LINE(341)
						colorValue = red;
						HX_STACK_LINE(342)
						colorValue = (((int(colorValue) << int((int)8))) + green);
						HX_STACK_LINE(343)
						colorValue = (((int(colorValue) << int((int)8))) + blue);
						HX_STACK_LINE(344)
						alphaValue = alpha;
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(351)
		colorVO->color = colorValue;
		HX_STACK_LINE(352)
		colorVO->alpha = alphaValue;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSValueConverter_obj,getColorVOFromCSSColor,(void))

::cocktail::core::css::CSSColorValue CSSValueConverter_obj::HSLAToRGBA( Float hue,Float saturation,Float lightness,Float alpha){
	HX_STACK_PUSH("CSSValueConverter::HSLAToRGBA","cocktail/core/css/CSSValueConverter.hx",361);
	HX_STACK_ARG(hue,"hue");
	HX_STACK_ARG(saturation,"saturation");
	HX_STACK_ARG(lightness,"lightness");
	HX_STACK_ARG(alpha,"alpha");
	HX_STACK_LINE(362)
	Float m2 = (int)0;		HX_STACK_VAR(m2,"m2");
	HX_STACK_LINE(363)
	if (((lightness < 0.5))){
		HX_STACK_LINE(364)
		m2 = (lightness * ((saturation + (int)1)));
	}
	else{
		HX_STACK_LINE(368)
		m2 = ((lightness + saturation) - (lightness * saturation));
	}
	HX_STACK_LINE(372)
	Float m1 = ((lightness * (int)2) - m2);		HX_STACK_VAR(m1,"m1");
	HX_STACK_LINE(374)
	int r = ::Math_obj::round(::cocktail::core::css::CSSValueConverter_obj::hueToRGB(m1,m2,(hue + (Float((int)1) / Float((int)3)))));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(375)
	int g = ::Math_obj::round(::cocktail::core::css::CSSValueConverter_obj::hueToRGB(m1,m2,hue));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(376)
	int b = ::Math_obj::round(::cocktail::core::css::CSSValueConverter_obj::hueToRGB(m1,m2,(hue - (Float((int)1) / Float((int)3)))));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(378)
	return ::cocktail::core::css::CSSColorValue_obj::RGBA(r,g,b,alpha);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSValueConverter_obj,HSLAToRGBA,return )

Float CSSValueConverter_obj::hueToRGB( Float m1,Float m2,Float h){
	HX_STACK_PUSH("CSSValueConverter::hueToRGB","cocktail/core/css/CSSValueConverter.hx",386);
	HX_STACK_ARG(m1,"m1");
	HX_STACK_ARG(m2,"m2");
	HX_STACK_ARG(h,"h");
	HX_STACK_LINE(387)
	if (((h < (int)0))){
		HX_STACK_LINE(388)
		h = (h + (int)1);
	}
	HX_STACK_LINE(392)
	if (((h > (int)1))){
		HX_STACK_LINE(393)
		h = (h - (int)1);
	}
	HX_STACK_LINE(397)
	if ((((h * (int)6) < (int)1))){
		HX_STACK_LINE(398)
		return (m1 + ((((m2 - m1)) * h) * (int)6));
	}
	HX_STACK_LINE(402)
	if ((((h * (int)2) < (int)1))){
		HX_STACK_LINE(403)
		return m2;
	}
	HX_STACK_LINE(407)
	if ((((h * (int)3) < (int)2))){
		HX_STACK_LINE(408)
		return (m1 + ((((m2 - m1)) * (((Float((int)2) / Float((int)3)) - h))) * (int)6));
	}
	HX_STACK_LINE(412)
	return m1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSValueConverter_obj,hueToRGB,return )

Float CSSValueConverter_obj::clampNumber( Float number,Float max,Float min){
	HX_STACK_PUSH("CSSValueConverter::clampNumber","cocktail/core/css/CSSValueConverter.hx",423);
	HX_STACK_ARG(number,"number");
	HX_STACK_ARG(max,"max");
	HX_STACK_ARG(min,"min");
	HX_STACK_LINE(424)
	if (((number > max))){
		HX_STACK_LINE(425)
		return max;
	}
	HX_STACK_LINE(428)
	if (((number < min))){
		HX_STACK_LINE(429)
		return min;
	}
	HX_STACK_LINE(432)
	return number;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSValueConverter_obj,clampNumber,return )

int CSSValueConverter_obj::clampInteger( int integer,int max,int min){
	HX_STACK_PUSH("CSSValueConverter::clampInteger","cocktail/core/css/CSSValueConverter.hx",439);
	HX_STACK_ARG(integer,"integer");
	HX_STACK_ARG(max,"max");
	HX_STACK_ARG(min,"min");
	HX_STACK_LINE(440)
	if (((integer > max))){
		HX_STACK_LINE(441)
		return max;
	}
	HX_STACK_LINE(444)
	if (((integer < min))){
		HX_STACK_LINE(445)
		return min;
	}
	HX_STACK_LINE(448)
	return integer;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSValueConverter_obj,clampInteger,return )

::cocktail::core::css::CSSColorValue CSSValueConverter_obj::hexToRGBA( ::String hex){
	HX_STACK_PUSH("CSSValueConverter::hexToRGBA","cocktail/core/css/CSSValueConverter.hx",457);
	HX_STACK_ARG(hex,"hex");
	HX_STACK_LINE(458)
	int red = ((::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)0)) * (int)16) + ::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)1)));		HX_STACK_VAR(red,"red");
	HX_STACK_LINE(459)
	int green = ((::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)2)) * (int)16) + ::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)3)));		HX_STACK_VAR(green,"green");
	HX_STACK_LINE(460)
	int blue = ((::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)4)) * (int)16) + ::cocktail::core::css::CSSValueConverter_obj::hexToInt(hex.charAt((int)5)));		HX_STACK_VAR(blue,"blue");
	HX_STACK_LINE(462)
	return ::cocktail::core::css::CSSColorValue_obj::RGBA(red,green,blue,1.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,hexToRGBA,return )

int CSSValueConverter_obj::hexToInt( ::String _char){
	HX_STACK_PUSH("CSSValueConverter::hexToInt","cocktail/core/css/CSSValueConverter.hx",469);
	HX_STACK_ARG(_char,"char");
	HX_STACK_LINE(470)
	::String _switch_9 = (_char.toUpperCase());
	if (  ( _switch_9==HX_CSTRING("0"))){
		HX_STACK_LINE(472)
		return (int)0;
	}
	else if (  ( _switch_9==HX_CSTRING("1"))){
		HX_STACK_LINE(475)
		return (int)1;
	}
	else if (  ( _switch_9==HX_CSTRING("2"))){
		HX_STACK_LINE(478)
		return (int)2;
	}
	else if (  ( _switch_9==HX_CSTRING("3"))){
		HX_STACK_LINE(481)
		return (int)3;
	}
	else if (  ( _switch_9==HX_CSTRING("4"))){
		HX_STACK_LINE(484)
		return (int)4;
	}
	else if (  ( _switch_9==HX_CSTRING("5"))){
		HX_STACK_LINE(487)
		return (int)5;
	}
	else if (  ( _switch_9==HX_CSTRING("6"))){
		HX_STACK_LINE(490)
		return (int)6;
	}
	else if (  ( _switch_9==HX_CSTRING("7"))){
		HX_STACK_LINE(493)
		return (int)7;
	}
	else if (  ( _switch_9==HX_CSTRING("8"))){
		HX_STACK_LINE(496)
		return (int)8;
	}
	else if (  ( _switch_9==HX_CSTRING("9"))){
		HX_STACK_LINE(499)
		return (int)9;
	}
	else if (  ( _switch_9==HX_CSTRING("A"))){
		HX_STACK_LINE(502)
		return (int)10;
	}
	else if (  ( _switch_9==HX_CSTRING("B"))){
		HX_STACK_LINE(505)
		return (int)11;
	}
	else if (  ( _switch_9==HX_CSTRING("C"))){
		HX_STACK_LINE(508)
		return (int)12;
	}
	else if (  ( _switch_9==HX_CSTRING("D"))){
		HX_STACK_LINE(511)
		return (int)13;
	}
	else if (  ( _switch_9==HX_CSTRING("E"))){
		HX_STACK_LINE(514)
		return (int)14;
	}
	else if (  ( _switch_9==HX_CSTRING("F"))){
		HX_STACK_LINE(517)
		return (int)15;
	}
	HX_STACK_LINE(521)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,hexToInt,return )

::cocktail::core::css::CSSColorValue CSSValueConverter_obj::getRGBAColorFromColorKeyword( ::cocktail::core::css::CSSColorKeyword value){
	HX_STACK_PUSH("CSSValueConverter::getRGBAColorFromColorKeyword","cocktail/core/css/CSSValueConverter.hx",529);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(529)
	{
		::cocktail::core::css::CSSColorKeyword _switch_10 = (value);
		switch((_switch_10)->GetIndex()){
			case 0: {
				HX_STACK_LINE(532)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)240,(int)248,(int)255,1.0);
			}
			;break;
			case 1: {
				HX_STACK_LINE(535)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)250,(int)235,(int)215,1.0);
			}
			;break;
			case 2: {
				HX_STACK_LINE(538)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)255,(int)255,1.0);
			}
			;break;
			case 3: {
				HX_STACK_LINE(541)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)127,(int)255,(int)212,1.0);
			}
			;break;
			case 4: {
				HX_STACK_LINE(544)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)240,(int)255,(int)255,1.0);
			}
			;break;
			case 5: {
				HX_STACK_LINE(547)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)245,(int)245,(int)220,1.0);
			}
			;break;
			case 6: {
				HX_STACK_LINE(550)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)228,(int)196,1.0);
			}
			;break;
			case 7: {
				HX_STACK_LINE(553)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)0,1.0);
			}
			;break;
			case 8: {
				HX_STACK_LINE(556)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)235,(int)205,1.0);
			}
			;break;
			case 9: {
				HX_STACK_LINE(559)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)255,1.0);
			}
			;break;
			case 10: {
				HX_STACK_LINE(562)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)138,(int)43,(int)226,1.0);
			}
			;break;
			case 11: {
				HX_STACK_LINE(565)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)165,(int)42,(int)42,1.0);
			}
			;break;
			case 12: {
				HX_STACK_LINE(568)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)222,(int)184,(int)135,1.0);
			}
			;break;
			case 13: {
				HX_STACK_LINE(571)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)95,(int)158,(int)160,1.0);
			}
			;break;
			case 14: {
				HX_STACK_LINE(574)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)127,(int)255,(int)0,1.0);
			}
			;break;
			case 15: {
				HX_STACK_LINE(577)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)210,(int)105,(int)30,1.0);
			}
			;break;
			case 16: {
				HX_STACK_LINE(580)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)127,(int)80,1.0);
			}
			;break;
			case 17: {
				HX_STACK_LINE(583)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)100,(int)149,(int)237,1.0);
			}
			;break;
			case 18: {
				HX_STACK_LINE(586)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)248,(int)220,1.0);
			}
			;break;
			case 19: {
				HX_STACK_LINE(589)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)220,(int)20,(int)60,1.0);
			}
			;break;
			case 20: {
				HX_STACK_LINE(592)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)255,(int)255,1.0);
			}
			;break;
			case 21: {
				HX_STACK_LINE(595)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)139,1.0);
			}
			;break;
			case 22: {
				HX_STACK_LINE(598)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)139,(int)139,1.0);
			}
			;break;
			case 23: {
				HX_STACK_LINE(601)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)184,(int)134,(int)11,1.0);
			}
			;break;
			case 24: {
				HX_STACK_LINE(604)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)169,(int)169,(int)169,1.0);
			}
			;break;
			case 25: {
				HX_STACK_LINE(607)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)100,(int)0,1.0);
			}
			;break;
			case 26: {
				HX_STACK_LINE(610)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)169,(int)169,(int)169,1.0);
			}
			;break;
			case 27: {
				HX_STACK_LINE(613)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)189,(int)183,(int)107,1.0);
			}
			;break;
			case 28: {
				HX_STACK_LINE(616)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)139,(int)0,(int)139,1.0);
			}
			;break;
			case 29: {
				HX_STACK_LINE(619)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)85,(int)107,(int)47,1.0);
			}
			;break;
			case 30: {
				HX_STACK_LINE(622)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)140,(int)0,1.0);
			}
			;break;
			case 31: {
				HX_STACK_LINE(625)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)153,(int)50,(int)204,1.0);
			}
			;break;
			case 32: {
				HX_STACK_LINE(628)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)139,(int)0,(int)0,1.0);
			}
			;break;
			case 33: {
				HX_STACK_LINE(631)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)233,(int)150,(int)122,1.0);
			}
			;break;
			case 34: {
				HX_STACK_LINE(634)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)143,(int)188,(int)143,1.0);
			}
			;break;
			case 35: {
				HX_STACK_LINE(637)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)72,(int)61,(int)139,1.0);
			}
			;break;
			case 36: {
				HX_STACK_LINE(640)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)47,(int)79,(int)79,1.0);
			}
			;break;
			case 37: {
				HX_STACK_LINE(643)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)47,(int)79,(int)79,1.0);
			}
			;break;
			case 38: {
				HX_STACK_LINE(646)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)206,(int)209,1.0);
			}
			;break;
			case 39: {
				HX_STACK_LINE(649)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)148,(int)0,(int)211,1.0);
			}
			;break;
			case 40: {
				HX_STACK_LINE(652)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)20,(int)147,1.0);
			}
			;break;
			case 41: {
				HX_STACK_LINE(655)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)191,(int)255,1.0);
			}
			;break;
			case 42: {
				HX_STACK_LINE(658)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)105,(int)105,(int)105,1.0);
			}
			;break;
			case 43: {
				HX_STACK_LINE(661)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)105,(int)105,(int)105,1.0);
			}
			;break;
			case 44: {
				HX_STACK_LINE(664)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)30,(int)144,(int)255,1.0);
			}
			;break;
			case 45: {
				HX_STACK_LINE(667)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)178,(int)34,(int)34,1.0);
			}
			;break;
			case 46: {
				HX_STACK_LINE(670)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)250,(int)240,1.0);
			}
			;break;
			case 47: {
				HX_STACK_LINE(673)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)34,(int)139,(int)34,1.0);
			}
			;break;
			case 48: {
				HX_STACK_LINE(676)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)0,(int)255,1.0);
			}
			;break;
			case 49: {
				HX_STACK_LINE(679)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)220,(int)220,(int)220,1.0);
			}
			;break;
			case 50: {
				HX_STACK_LINE(682)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)248,(int)248,(int)255,1.0);
			}
			;break;
			case 51: {
				HX_STACK_LINE(685)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)215,(int)0,1.0);
			}
			;break;
			case 52: {
				HX_STACK_LINE(688)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)218,(int)165,(int)32,1.0);
			}
			;break;
			case 53: {
				HX_STACK_LINE(691)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)128,(int)128,(int)128,1.0);
			}
			;break;
			case 54: {
				HX_STACK_LINE(694)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)128,(int)0,1.0);
			}
			;break;
			case 55: {
				HX_STACK_LINE(697)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)173,(int)255,(int)47,1.0);
			}
			;break;
			case 56: {
				HX_STACK_LINE(700)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)128,(int)128,(int)128,1.0);
			}
			;break;
			case 57: {
				HX_STACK_LINE(703)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)240,(int)255,(int)240,1.0);
			}
			;break;
			case 58: {
				HX_STACK_LINE(706)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)105,(int)180,1.0);
			}
			;break;
			case 59: {
				HX_STACK_LINE(709)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)205,(int)92,(int)92,1.0);
			}
			;break;
			case 60: {
				HX_STACK_LINE(712)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)75,(int)0,(int)130,1.0);
			}
			;break;
			case 61: {
				HX_STACK_LINE(715)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)255,(int)240,1.0);
			}
			;break;
			case 62: {
				HX_STACK_LINE(718)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)240,(int)230,(int)140,1.0);
			}
			;break;
			case 63: {
				HX_STACK_LINE(721)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)230,(int)230,(int)250,1.0);
			}
			;break;
			case 64: {
				HX_STACK_LINE(724)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)240,(int)245,1.0);
			}
			;break;
			case 65: {
				HX_STACK_LINE(727)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)124,(int)252,(int)0,1.0);
			}
			;break;
			case 66: {
				HX_STACK_LINE(730)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)250,(int)205,1.0);
			}
			;break;
			case 67: {
				HX_STACK_LINE(733)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)173,(int)216,(int)130,1.0);
			}
			;break;
			case 68: {
				HX_STACK_LINE(736)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)240,(int)128,(int)128,1.0);
			}
			;break;
			case 69: {
				HX_STACK_LINE(739)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)224,(int)255,(int)255,1.0);
			}
			;break;
			case 70: {
				HX_STACK_LINE(742)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)250,(int)250,(int)210,1.0);
			}
			;break;
			case 71: {
				HX_STACK_LINE(745)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)211,(int)211,(int)211,1.0);
			}
			;break;
			case 72: {
				HX_STACK_LINE(748)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)144,(int)238,(int)144,1.0);
			}
			;break;
			case 73: {
				HX_STACK_LINE(751)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)211,(int)211,(int)211,1.0);
			}
			;break;
			case 74: {
				HX_STACK_LINE(754)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)182,(int)193,1.0);
			}
			;break;
			case 75: {
				HX_STACK_LINE(757)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)160,(int)122,1.0);
			}
			;break;
			case 76: {
				HX_STACK_LINE(760)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)32,(int)178,(int)170,1.0);
			}
			;break;
			case 77: {
				HX_STACK_LINE(763)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)135,(int)206,(int)250,1.0);
			}
			;break;
			case 78: {
				HX_STACK_LINE(766)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)119,(int)136,(int)153,1.0);
			}
			;break;
			case 79: {
				HX_STACK_LINE(769)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)119,(int)136,(int)153,1.0);
			}
			;break;
			case 80: {
				HX_STACK_LINE(772)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)176,(int)196,(int)222,1.0);
			}
			;break;
			case 81: {
				HX_STACK_LINE(775)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)255,(int)224,1.0);
			}
			;break;
			case 82: {
				HX_STACK_LINE(778)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)255,(int)0,1.0);
			}
			;break;
			case 83: {
				HX_STACK_LINE(781)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)50,(int)205,(int)50,1.0);
			}
			;break;
			case 84: {
				HX_STACK_LINE(784)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)250,(int)240,(int)230,1.0);
			}
			;break;
			case 85: {
				HX_STACK_LINE(787)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)0,(int)255,1.0);
			}
			;break;
			case 86: {
				HX_STACK_LINE(790)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)128,(int)0,(int)0,1.0);
			}
			;break;
			case 87: {
				HX_STACK_LINE(793)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)102,(int)205,(int)170,1.0);
			}
			;break;
			case 88: {
				HX_STACK_LINE(796)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)205,1.0);
			}
			;break;
			case 89: {
				HX_STACK_LINE(799)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)186,(int)85,(int)211,1.0);
			}
			;break;
			case 90: {
				HX_STACK_LINE(802)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)147,(int)112,(int)219,1.0);
			}
			;break;
			case 91: {
				HX_STACK_LINE(805)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)60,(int)179,(int)113,1.0);
			}
			;break;
			case 92: {
				HX_STACK_LINE(808)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)123,(int)104,(int)238,1.0);
			}
			;break;
			case 93: {
				HX_STACK_LINE(811)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)250,(int)154,1.0);
			}
			;break;
			case 94: {
				HX_STACK_LINE(814)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)72,(int)209,(int)204,1.0);
			}
			;break;
			case 95: {
				HX_STACK_LINE(817)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)199,(int)21,(int)133,1.0);
			}
			;break;
			case 96: {
				HX_STACK_LINE(820)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)25,(int)25,(int)112,1.0);
			}
			;break;
			case 97: {
				HX_STACK_LINE(823)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)245,(int)255,(int)250,1.0);
			}
			;break;
			case 98: {
				HX_STACK_LINE(826)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)228,(int)225,1.0);
			}
			;break;
			case 99: {
				HX_STACK_LINE(829)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)228,(int)181,1.0);
			}
			;break;
			case 100: {
				HX_STACK_LINE(832)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)222,(int)173,1.0);
			}
			;break;
			case 101: {
				HX_STACK_LINE(835)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)0,(int)128,1.0);
			}
			;break;
			case 102: {
				HX_STACK_LINE(838)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)253,(int)245,(int)230,1.0);
			}
			;break;
			case 103: {
				HX_STACK_LINE(841)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)128,(int)128,(int)0,1.0);
			}
			;break;
			case 104: {
				HX_STACK_LINE(844)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)107,(int)142,(int)35,1.0);
			}
			;break;
			case 105: {
				HX_STACK_LINE(847)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)165,(int)0,1.0);
			}
			;break;
			case 106: {
				HX_STACK_LINE(850)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)69,(int)0,1.0);
			}
			;break;
			case 107: {
				HX_STACK_LINE(853)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)218,(int)112,(int)214,1.0);
			}
			;break;
			case 108: {
				HX_STACK_LINE(856)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)238,(int)232,(int)170,1.0);
			}
			;break;
			case 109: {
				HX_STACK_LINE(859)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)152,(int)251,(int)152,1.0);
			}
			;break;
			case 110: {
				HX_STACK_LINE(862)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)175,(int)238,(int)238,1.0);
			}
			;break;
			case 111: {
				HX_STACK_LINE(865)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)219,(int)112,(int)147,1.0);
			}
			;break;
			case 112: {
				HX_STACK_LINE(868)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)239,(int)213,1.0);
			}
			;break;
			case 113: {
				HX_STACK_LINE(871)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)218,(int)185,1.0);
			}
			;break;
			case 114: {
				HX_STACK_LINE(874)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)205,(int)133,(int)63,1.0);
			}
			;break;
			case 115: {
				HX_STACK_LINE(877)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)192,(int)203,1.0);
			}
			;break;
			case 116: {
				HX_STACK_LINE(880)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)221,(int)160,(int)221,1.0);
			}
			;break;
			case 117: {
				HX_STACK_LINE(883)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)176,(int)224,(int)230,1.0);
			}
			;break;
			case 118: {
				HX_STACK_LINE(886)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)128,(int)0,(int)128,1.0);
			}
			;break;
			case 119: {
				HX_STACK_LINE(889)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)0,(int)0,1.0);
			}
			;break;
			case 120: {
				HX_STACK_LINE(892)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)188,(int)143,(int)143,1.0);
			}
			;break;
			case 121: {
				HX_STACK_LINE(895)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)65,(int)105,(int)225,1.0);
			}
			;break;
			case 122: {
				HX_STACK_LINE(898)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)139,(int)69,(int)19,1.0);
			}
			;break;
			case 123: {
				HX_STACK_LINE(901)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)250,(int)128,(int)114,1.0);
			}
			;break;
			case 124: {
				HX_STACK_LINE(904)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)244,(int)164,(int)96,1.0);
			}
			;break;
			case 125: {
				HX_STACK_LINE(907)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)46,(int)139,(int)87,1.0);
			}
			;break;
			case 126: {
				HX_STACK_LINE(910)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)245,(int)238,1.0);
			}
			;break;
			case 127: {
				HX_STACK_LINE(913)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)160,(int)82,(int)45,1.0);
			}
			;break;
			case 128: {
				HX_STACK_LINE(916)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)192,(int)192,(int)192,1.0);
			}
			;break;
			case 129: {
				HX_STACK_LINE(919)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)135,(int)206,(int)235,1.0);
			}
			;break;
			case 130: {
				HX_STACK_LINE(922)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)106,(int)90,(int)205,1.0);
			}
			;break;
			case 131: {
				HX_STACK_LINE(925)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)112,(int)128,(int)144,1.0);
			}
			;break;
			case 132: {
				HX_STACK_LINE(928)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)112,(int)128,(int)144,1.0);
			}
			;break;
			case 133: {
				HX_STACK_LINE(931)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)250,(int)250,1.0);
			}
			;break;
			case 134: {
				HX_STACK_LINE(934)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)255,(int)127,1.0);
			}
			;break;
			case 135: {
				HX_STACK_LINE(937)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)70,(int)130,(int)180,1.0);
			}
			;break;
			case 136: {
				HX_STACK_LINE(940)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)210,(int)180,(int)140,1.0);
			}
			;break;
			case 137: {
				HX_STACK_LINE(943)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)0,(int)128,(int)128,1.0);
			}
			;break;
			case 138: {
				HX_STACK_LINE(946)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)216,(int)191,(int)216,1.0);
			}
			;break;
			case 139: {
				HX_STACK_LINE(949)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)99,(int)71,1.0);
			}
			;break;
			case 140: {
				HX_STACK_LINE(952)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)64,(int)224,(int)208,1.0);
			}
			;break;
			case 141: {
				HX_STACK_LINE(955)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)238,(int)130,(int)238,1.0);
			}
			;break;
			case 142: {
				HX_STACK_LINE(958)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)245,(int)222,(int)179,1.0);
			}
			;break;
			case 143: {
				HX_STACK_LINE(961)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)255,(int)255,1.0);
			}
			;break;
			case 144: {
				HX_STACK_LINE(964)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)245,(int)245,(int)245,1.0);
			}
			;break;
			case 145: {
				HX_STACK_LINE(967)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)255,(int)255,(int)0,1.0);
			}
			;break;
			case 146: {
				HX_STACK_LINE(970)
				return ::cocktail::core::css::CSSColorValue_obj::RGBA((int)154,(int)205,(int)50,1.0);
			}
			;break;
		}
	}
	HX_STACK_LINE(529)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getRGBAColorFromColorKeyword,return )

Float CSSValueConverter_obj::getLargerFontSize( Float parentFontSize){
	HX_STACK_PUSH("CSSValueConverter::getLargerFontSize","cocktail/core/css/CSSValueConverter.hx",981);
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_LINE(982)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add(::cocktail::core::config::Config_obj::getInstance()->xxSmallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xSmallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->smallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->mediumFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->largeFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xLargeFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xxLargeFontSize);		HX_STACK_VAR(fontSizeTable,"fontSizeTable");
	HX_STACK_LINE(991)
	Float fontSize = fontSizeTable->__get((fontSizeTable->length - (int)1));		HX_STACK_VAR(fontSize,"fontSize");
	HX_STACK_LINE(993)
	{
		HX_STACK_LINE(993)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = fontSizeTable->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(993)
		while(((_g1 < _g))){
			HX_STACK_LINE(993)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(995)
			if (((fontSizeTable->__get(i) > parentFontSize))){
				HX_STACK_LINE(997)
				fontSize = fontSizeTable->__get(i);
				HX_STACK_LINE(998)
				break;
			}
		}
	}
	HX_STACK_LINE(1002)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getLargerFontSize,return )

Float CSSValueConverter_obj::getSmallerFontSize( Float parentFontSize){
	HX_STACK_PUSH("CSSValueConverter::getSmallerFontSize","cocktail/core/css/CSSValueConverter.hx",1010);
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_LINE(1011)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add(::cocktail::core::config::Config_obj::getInstance()->xxSmallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xSmallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->smallFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->mediumFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->largeFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xLargeFontSize).Add(::cocktail::core::config::Config_obj::getInstance()->xxLargeFontSize);		HX_STACK_VAR(fontSizeTable,"fontSizeTable");
	HX_STACK_LINE(1020)
	Float fontSize = fontSizeTable->__get((int)0);		HX_STACK_VAR(fontSize,"fontSize");
	HX_STACK_LINE(1022)
	int i = (fontSizeTable->length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1024)
	while(((i > (int)0))){
		HX_STACK_LINE(1026)
		if (((fontSizeTable->__get(i) < parentFontSize))){
			HX_STACK_LINE(1029)
			fontSize = fontSizeTable->__get(i);
			HX_STACK_LINE(1031)
			break;
		}
		HX_STACK_LINE(1034)
		(i)--;
	}
	HX_STACK_LINE(1037)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSValueConverter_obj,getSmallerFontSize,return )


CSSValueConverter_obj::CSSValueConverter_obj()
{
}

void CSSValueConverter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSValueConverter);
	HX_MARK_END_CLASS();
}

void CSSValueConverter_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CSSValueConverter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"hueToRGB") ) { return hueToRGB_dyn(); }
		if (HX_FIELD_EQ(inName,"hexToInt") ) { return hexToInt_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hexToRGBA") ) { return hexToRGBA_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"HSLAToRGBA") ) { return HSLAToRGBA_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"clampNumber") ) { return clampNumber_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clampInteger") ) { return clampInteger_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getLargerFontSize") ) { return getLargerFontSize_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getPixelFromLength") ) { return getPixelFromLength_dyn(); }
		if (HX_FIELD_EQ(inName,"getSmallerFontSize") ) { return getSmallerFontSize_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getPixelFromPercent") ) { return getPixelFromPercent_dyn(); }
		if (HX_FIELD_EQ(inName,"getPercentFromPixel") ) { return getPercentFromPixel_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getColorVOFromCSSColor") ) { return getColorVOFromCSSColor_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getFontFamilyAsStringArray") ) { return getFontFamilyAsStringArray_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getRGBAColorFromColorKeyword") ) { return getRGBAColorFromColorKeyword_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"getComputedCSSColorFromCSSColor") ) { return getComputedCSSColorFromCSSColor_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"getFontSizeFromAbsoluteSizeValue") ) { return getFontSizeFromAbsoluteSizeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontSizeFromRelativeSizeValue") ) { return getFontSizeFromRelativeSizeValue_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"getBorderWidthFromBorderWidthKeyword") ) { return getBorderWidthFromBorderWidthKeyword_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSValueConverter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSValueConverter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getPixelFromLength"),
	HX_CSTRING("getBorderWidthFromBorderWidthKeyword"),
	HX_CSTRING("getFontFamilyAsStringArray"),
	HX_CSTRING("getFontSizeFromAbsoluteSizeValue"),
	HX_CSTRING("getFontSizeFromRelativeSizeValue"),
	HX_CSTRING("getPixelFromPercent"),
	HX_CSTRING("getPercentFromPixel"),
	HX_CSTRING("getComputedCSSColorFromCSSColor"),
	HX_CSTRING("getColorVOFromCSSColor"),
	HX_CSTRING("HSLAToRGBA"),
	HX_CSTRING("hueToRGB"),
	HX_CSTRING("clampNumber"),
	HX_CSTRING("clampInteger"),
	HX_CSTRING("hexToRGBA"),
	HX_CSTRING("hexToInt"),
	HX_CSTRING("getRGBAColorFromColorKeyword"),
	HX_CSTRING("getLargerFontSize"),
	HX_CSTRING("getSmallerFontSize"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSValueConverter_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSValueConverter_obj::__mClass,"__mClass");
};

Class CSSValueConverter_obj::__mClass;

void CSSValueConverter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSValueConverter"), hx::TCanCast< CSSValueConverter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSValueConverter_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
