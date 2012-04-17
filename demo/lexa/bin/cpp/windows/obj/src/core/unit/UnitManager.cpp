#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_core_unit_Angle
#include <core/unit/Angle.h>
#endif
#ifndef INCLUDED_core_unit_CSSColor
#include <core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_core_unit_ColorKeyword
#include <core/unit/ColorKeyword.h>
#endif
#ifndef INCLUDED_core_unit_FontSizeAbsoluteSize
#include <core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_core_unit_FontSizeRelativeSize
#include <core/unit/FontSizeRelativeSize.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
#ifndef INCLUDED_core_unit_UnitManager
#include <core/unit/UnitManager.h>
#endif
namespace core{
namespace unit{

Void UnitManager_obj::__construct()
{
{
}
;
	return null();
}

UnitManager_obj::~UnitManager_obj() { }

Dynamic UnitManager_obj::__CreateEmpty() { return  new UnitManager_obj; }
hx::ObjectPtr< UnitManager_obj > UnitManager_obj::__new()
{  hx::ObjectPtr< UnitManager_obj > result = new UnitManager_obj();
	result->__construct();
	return result;}

Dynamic UnitManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UnitManager_obj > result = new UnitManager_obj();
	result->__construct();
	return result;}

int UnitManager_obj::getPixelFromLength( ::core::unit::Length length,double emReference,double exReference){
	HX_SOURCE_PUSH("UnitManager_obj::getPixelFromLength")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",52)
	double lengthValue;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",54)
	{
::core::unit::Length _switch_1 = (length);
		switch((_switch_1)->GetIndex()){
			case 0: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",56)
					lengthValue = value;
				}
			}
			;break;
			case 2: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",59)
					lengthValue = (double((value * ((double(((int)72 * ((double((int)1) / double(0.75))))) / double(2.54))))) / double((int)10));
				}
			}
			;break;
			case 1: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",62)
					lengthValue = (value * ((double(((int)72 * ((double((int)1) / double(0.75))))) / double(2.54))));
				}
			}
			;break;
			case 3: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",65)
					lengthValue = (double(value) / double(0.75));
				}
			}
			;break;
			case 5: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",68)
					lengthValue = (value * (((int)72 * ((double((int)1) / double(0.75))))));
				}
			}
			;break;
			case 4: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",71)
					lengthValue = (value * (((int)12 * ((double((int)1) / double(0.75))))));
				}
			}
			;break;
			case 6: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",74)
					lengthValue = (emReference * value);
				}
			}
			;break;
			case 7: {
				double value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",77)
					lengthValue = (exReference * value);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",81)
	return ::Math_obj::round(lengthValue);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(UnitManager_obj,getPixelFromLength,return )

double UnitManager_obj::getFontSizeFromAbsoluteSizeValue( ::core::unit::FontSizeAbsoluteSize absoluteSize){
	HX_SOURCE_PUSH("UnitManager_obj::getFontSizeFromAbsoluteSizeValue")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",90)
	double fontSize;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",92)
	int mediumFontSize = (int)16;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",94)
	{
::core::unit::FontSizeAbsoluteSize _switch_2 = (absoluteSize);
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",96)
				fontSize = (int)9;
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",99)
				fontSize = (int)10;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",102)
				fontSize = (int)13;
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",105)
				fontSize = (int)16;
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",108)
				fontSize = (int)18;
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",111)
				fontSize = (int)24;
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",114)
				fontSize = (int)32;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",118)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getFontSizeFromAbsoluteSizeValue,return )

double UnitManager_obj::getFontSizeFromRelativeSizeValue( ::core::unit::FontSizeRelativeSize relativeSize,double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getFontSizeFromRelativeSizeValue")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",127)
	double fontSize;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",129)
	{
::core::unit::FontSizeRelativeSize _switch_3 = (relativeSize);
		switch((_switch_3)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",131)
				fontSize = ::core::unit::UnitManager_obj::getLargerFontSize(parentFontSize);
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",134)
				fontSize = ::core::unit::UnitManager_obj::getSmallerFontSize(parentFontSize);
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",138)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getFontSizeFromRelativeSizeValue,return )

double UnitManager_obj::getPixelFromPercent( int percent,int reference){
	HX_SOURCE_PUSH("UnitManager_obj::getPixelFromPercent")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",148)
	return (reference * ((percent * 0.01)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getPixelFromPercent,return )

double UnitManager_obj::getPercentFromPixel( int pixel,int reference){
	HX_SOURCE_PUSH("UnitManager_obj::getPercentFromPixel")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",159)
	return ((double(reference) / double(pixel)) * (int)100);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getPercentFromPixel,return )

Dynamic UnitManager_obj::getColorDataFromCSSColor( ::core::unit::CSSColor value){
	HX_SOURCE_PUSH("UnitManager_obj::getColorDataFromCSSColor")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",168)
	int colorValue;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",169)
	double alphaValue;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",171)
	{
::core::unit::CSSColor _switch_4 = (value);
		switch((_switch_4)->GetIndex()){
			case 0: {
				int blue = _switch_4->__Param(2);
				int green = _switch_4->__Param(1);
				int red = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",174)
					colorValue = red;
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",175)
					colorValue = (((int(colorValue) << int((int)8))) + green);
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",176)
					colorValue = (((int(colorValue) << int((int)8))) + blue);
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",177)
					alphaValue = 1.0;
				}
			}
			;break;
			case 1: {
				double alpha = _switch_4->__Param(3);
				int blue = _switch_4->__Param(2);
				int green = _switch_4->__Param(1);
				int red = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",180)
					colorValue = red;
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",181)
					colorValue = (((int(colorValue) << int((int)8))) + green);
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",182)
					colorValue = (((int(colorValue) << int((int)8))) + blue);
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",183)
					alphaValue = alpha;
				}
			}
			;break;
			case 2: {
				::String value1 = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",186)
					colorValue = ::Std_obj::parseInt(::StringTools_obj::replace(value1,HX_CSTRING("#"),HX_CSTRING("0x")));
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",187)
					alphaValue = 1.0;
				}
			}
			;break;
			case 3: {
				::core::unit::ColorKeyword value1 = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",190)
					colorValue = ::core::unit::UnitManager_obj::getColorDataFromColorKeyword(value1)->__Field(HX_CSTRING("color"));
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",191)
					alphaValue = 1.0;
				}
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",194)
				colorValue = (int)16777215;
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",195)
				alphaValue = 0.0;
			}
			;break;
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( int &colorValue,double &alphaValue){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("color") , colorValue,false);
			__result->Add(HX_CSTRING("alpha") , alphaValue,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",198)
	Dynamic colorData = _Function_1_1::Block(colorValue,alphaValue);
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",203)
	return colorData;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getColorDataFromCSSColor,return )

double UnitManager_obj::getRadFromAngle( ::core::unit::Angle value){
	HX_SOURCE_PUSH("UnitManager_obj::getRadFromAngle")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",211)
	double angle;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",213)
	{
::core::unit::Angle _switch_5 = (value);
		switch((_switch_5)->GetIndex()){
			case 0: {
				double value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",215)
					angle = (value1 * ((double(::Math_obj::PI) / double((int)180))));
				}
			}
			;break;
			case 2: {
				double value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",218)
					angle = value1;
				}
			}
			;break;
			case 3: {
				double value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",221)
					angle = ((value1 * (int)360) * ((double(::Math_obj::PI) / double((int)180))));
				}
			}
			;break;
			case 1: {
				double value1 = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",224)
					angle = (value1 * ((double(::Math_obj::PI) / double((int)200))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",228)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getRadFromAngle,return )

double UnitManager_obj::getDegreeFromAngle( ::core::unit::Angle value){
	HX_SOURCE_PUSH("UnitManager_obj::getDegreeFromAngle")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",236)
	double angle;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",238)
	{
::core::unit::Angle _switch_6 = (value);
		switch((_switch_6)->GetIndex()){
			case 0: {
				double value1 = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",240)
					angle = value1;
				}
			}
			;break;
			case 2: {
				double value1 = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",243)
					angle = (value1 * ((double((int)180) / double(::Math_obj::PI))));
				}
			}
			;break;
			case 3: {
				double value1 = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",246)
					angle = (value1 * (int)360);
				}
			}
			;break;
			case 1: {
				double value1 = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",249)
					angle = (value1 * 0.9);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",253)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getDegreeFromAngle,return )

Dynamic UnitManager_obj::getColorDataFromColorKeyword( ::core::unit::ColorKeyword value){
	HX_SOURCE_PUSH("UnitManager_obj::getColorDataFromColorKeyword")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",265)
	::String hexColor;
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",267)
	{
::core::unit::ColorKeyword _switch_7 = (value);
		switch((_switch_7)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",269)
				hexColor = HX_CSTRING("#00FFFF");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",272)
				hexColor = HX_CSTRING("#000000");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",275)
				hexColor = HX_CSTRING("#0000FF");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",278)
				hexColor = HX_CSTRING("#FF00FF");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",281)
				hexColor = HX_CSTRING("#808080");
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",284)
				hexColor = HX_CSTRING("#008000");
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",287)
				hexColor = HX_CSTRING("#00FF00");
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",290)
				hexColor = HX_CSTRING("#800000");
			}
			;break;
			case 8: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",293)
				hexColor = HX_CSTRING("#000080");
			}
			;break;
			case 9: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",296)
				hexColor = HX_CSTRING("#808000");
			}
			;break;
			case 10: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",299)
				hexColor = HX_CSTRING("#FFA500");
			}
			;break;
			case 11: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",302)
				hexColor = HX_CSTRING("#800080");
			}
			;break;
			case 12: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",305)
				hexColor = HX_CSTRING("#FF0000");
			}
			;break;
			case 13: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",308)
				hexColor = HX_CSTRING("#C0C0C0");
			}
			;break;
			case 14: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",311)
				hexColor = HX_CSTRING("#008080");
			}
			;break;
			case 15: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",314)
				hexColor = HX_CSTRING("#FFFFFF");
			}
			;break;
			case 16: {
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",317)
				hexColor = HX_CSTRING("#FFFF00");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",322)
	return ::core::unit::UnitManager_obj::getColorDataFromCSSColor(::core::unit::CSSColor_obj::hex(hexColor));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getColorDataFromColorKeyword,return )

double UnitManager_obj::getLargerFontSize( double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getLargerFontSize")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",331)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)13).Add((int)16).Add((int)18).Add((int)24).Add((int)32);
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",332)
	double fontSize = fontSizeTable->__get((fontSizeTable->length - (int)1));
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",334)
	{
		HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",334)
		int _g1 = (int)0;
		int _g = fontSizeTable->length;
		HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",334)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",334)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",336)
			if (((fontSizeTable->__get(i) > parentFontSize))){
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",338)
				fontSize = fontSizeTable->__get(i);
				HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",339)
				break;
			}
		}
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",343)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getLargerFontSize,return )

double UnitManager_obj::getSmallerFontSize( double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getSmallerFontSize")
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",353)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)13).Add((int)16).Add((int)18).Add((int)24).Add((int)32);
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",354)
	double fontSize = fontSizeTable->__get((int)0);
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",356)
	int i = (fontSizeTable->length - (int)1);
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",358)
	while(((i > (int)0))){
		HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",360)
		if (((fontSizeTable->__get(i) < parentFontSize))){
			HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",363)
			fontSize = fontSizeTable->__get(i);
			HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",365)
			break;
		}
		HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",368)
		(i)--;
	}
	HX_SOURCE_POS("../../src/core/unit/UnitManager.hx",371)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getSmallerFontSize,return )


UnitManager_obj::UnitManager_obj()
{
}

void UnitManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UnitManager);
	HX_MARK_END_CLASS();
}

Dynamic UnitManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"getRadFromAngle") ) { return getRadFromAngle_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getLargerFontSize") ) { return getLargerFontSize_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getPixelFromLength") ) { return getPixelFromLength_dyn(); }
		if (HX_FIELD_EQ(inName,"getDegreeFromAngle") ) { return getDegreeFromAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"getSmallerFontSize") ) { return getSmallerFontSize_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getPixelFromPercent") ) { return getPixelFromPercent_dyn(); }
		if (HX_FIELD_EQ(inName,"getPercentFromPixel") ) { return getPercentFromPixel_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getColorDataFromCSSColor") ) { return getColorDataFromCSSColor_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getColorDataFromColorKeyword") ) { return getColorDataFromColorKeyword_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"getFontSizeFromAbsoluteSizeValue") ) { return getFontSizeFromAbsoluteSizeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontSizeFromRelativeSizeValue") ) { return getFontSizeFromRelativeSizeValue_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic UnitManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void UnitManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getPixelFromLength"),
	HX_CSTRING("getFontSizeFromAbsoluteSizeValue"),
	HX_CSTRING("getFontSizeFromRelativeSizeValue"),
	HX_CSTRING("getPixelFromPercent"),
	HX_CSTRING("getPercentFromPixel"),
	HX_CSTRING("getColorDataFromCSSColor"),
	HX_CSTRING("getRadFromAngle"),
	HX_CSTRING("getDegreeFromAngle"),
	HX_CSTRING("getColorDataFromColorKeyword"),
	HX_CSTRING("getLargerFontSize"),
	HX_CSTRING("getSmallerFontSize"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class UnitManager_obj::__mClass;

void UnitManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.unit.UnitManager"), hx::TCanCast< UnitManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UnitManager_obj::__boot()
{
}

} // end namespace core
} // end namespace unit
