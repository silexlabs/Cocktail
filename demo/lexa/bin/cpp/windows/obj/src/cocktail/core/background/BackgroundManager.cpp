#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_background_BackgroundDrawingManager
#include <cocktail/core/background/BackgroundDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#include <cocktail/core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_drawing_AbstractDrawingManager
#include <cocktail/core/drawing/AbstractDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractImageLoader
#include <cocktail/core/resource/AbstractImageLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractMediaLoader
#include <cocktail/core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResourceLoader
#include <cocktail/core/resource/AbstractResourceLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundClip
#include <cocktail/core/style/BackgroundClip.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundImage
#include <cocktail/core/style/BackgroundImage.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundOrigin
#include <cocktail/core/style/BackgroundOrigin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer
#include <cocktail/core/style/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientValue
#include <cocktail/core/unit/GradientValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ImageValue
#include <cocktail/core/unit/ImageValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_DrawingManager
#include <cocktail/port/flash_player/DrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_MediaLoader
#include <cocktail/port/flash_player/MediaLoader.h>
#endif
namespace cocktail{
namespace core{
namespace background{

Void BackgroundManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",47)
	this->_backgroundDrawingManagers = Array_obj< ::cocktail::core::background::BackgroundDrawingManager >::__new();
}
;
	return null();
}

BackgroundManager_obj::~BackgroundManager_obj() { }

Dynamic BackgroundManager_obj::__CreateEmpty() { return  new BackgroundManager_obj; }
hx::ObjectPtr< BackgroundManager_obj > BackgroundManager_obj::__new()
{  hx::ObjectPtr< BackgroundManager_obj > result = new BackgroundManager_obj();
	result->__construct();
	return result;}

Dynamic BackgroundManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BackgroundManager_obj > result = new BackgroundManager_obj();
	result->__construct();
	return result;}

Void BackgroundManager_obj::dispose( ){
{
		HX_SOURCE_PUSH("BackgroundManager_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",56)
		this->_backgroundDrawingManagers = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BackgroundManager_obj,dispose,(void))

Dynamic BackgroundManager_obj::render( Dynamic backgroundBox,::cocktail::core::style::AbstractCoreStyle style){
	HX_SOURCE_PUSH("BackgroundManager_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",73)
	Dynamic nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",76)
	if (((bool((backgroundBox->__Field(HX_CSTRING("width")) <= (int)0)) || bool((backgroundBox->__Field(HX_CSTRING("height")) <= (int)0))))){
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",77)
		return nativeElements;
	}
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",84)
	{
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",84)
		int _g1 = (int)0;
		int _g = style->getBackgroundImage()->length;
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",84)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",84)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",86)
			{
::cocktail::core::style::BackgroundImage _switch_1 = (style->getBackgroundImage()->__get(i));
				switch((_switch_1)->GetIndex()){
					case 0: {
					}
					;break;
					case 1: {
						::cocktail::core::unit::ImageValue value = _switch_1->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",91)
							{
::cocktail::core::unit::ImageValue _switch_2 = (value);
								switch((_switch_2)->GetIndex()){
									case 0: {
										::String value1 = _switch_2->__Param(0);
{
											struct _Function_5_1{
												inline static Dynamic Block( ::String &value1){
													hx::Anon __result = hx::Anon_obj::Create();
													__result->Add(HX_CSTRING("urls") , Array_obj< ::String >::__new().Add(value1),false);
													__result->Add(HX_CSTRING("fallbackColor") , ::cocktail::core::unit::CSSColor_obj::transparent_dyn(),false);
													return __result;
												}
											};
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",100)
											Dynamic imageDeclaration = _Function_5_1::Block(value1);
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",106)
											Dynamic imageNativeElement = this->drawBackgroundImage(imageDeclaration,style,backgroundBox,style->getBackgroundPosition()->__GetItem(i),style->getBackgroundSize()->__get(i),style->getBackgroundOrigin()->__get(i),style->getBackgroundClip()->__get(i),style->getBackgroundRepeat()->__GetItem(i),style->getBackgroundImage()->__get(i));
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",110)
											nativeElements->__Field(HX_CSTRING("push"))(imageNativeElement);
										}
									}
									;break;
									case 1: {
										Dynamic value1 = _switch_2->__Param(0);
{
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",116)
											Dynamic imageNativeElement = this->drawBackgroundImage(value1,style,backgroundBox,style->getBackgroundPosition()->__GetItem(i),style->getBackgroundSize()->__get(i),style->getBackgroundOrigin()->__get(i),style->getBackgroundClip()->__get(i),style->getBackgroundRepeat()->__GetItem(i),style->getBackgroundImage()->__get(i));
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",120)
											nativeElements->__Field(HX_CSTRING("push"))(imageNativeElement);
										}
									}
									;break;
									case 2: {
										::cocktail::core::unit::GradientValue value1 = _switch_2->__Param(0);
{
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",125)
											Dynamic gradientNativeElement = this->drawBackgroundGradient(style,value1,backgroundBox,style->getBackgroundPosition()->__GetItem(i),style->getBackgroundSize()->__get(i),style->getBackgroundOrigin()->__get(i),style->getBackgroundClip()->__get(i),style->getBackgroundRepeat()->__GetItem(i),style->getBackgroundImage()->__get(i));
											HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",128)
											nativeElements->__Field(HX_CSTRING("push"))(gradientNativeElement);
										}
									}
									;break;
								}
							}
						}
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",134)
			if (((i == (style->getBackgroundImage()->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",136)
				Dynamic backgroundColorNativeElement = ::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::graphic_dyn());
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",137)
				this->drawBackgroundColor(style,style->getComputedStyle()->__Field(HX_CSTRING("backgroundColor")),backgroundColorNativeElement,backgroundBox,style->getBackgroundPosition()->__GetItem(i),style->getBackgroundSize()->__get(i),style->getBackgroundOrigin()->__get(i),style->getBackgroundClip()->__get(i),style->getBackgroundRepeat()->__GetItem(i),style->getBackgroundImage()->__get(i));
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",143)
				nativeElements->__Field(HX_CSTRING("reverse"))();
				HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",147)
				nativeElements->__Field(HX_CSTRING("unshift"))(backgroundColorNativeElement);
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",155)
	return nativeElements;
}


HX_DEFINE_DYNAMIC_FUNC2(BackgroundManager_obj,render,return )

Dynamic BackgroundManager_obj::drawBackgroundImage( Dynamic imageDeclaration,::cocktail::core::style::AbstractCoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
	HX_SOURCE_PUSH("BackgroundManager_obj::drawBackgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Array< ::cocktail::core::style::BackgroundImage > backgroundImage1 = Array_obj< ::cocktail::core::style::BackgroundImage >::__new().Add(backgroundImage);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Dynamic backgroundRepeat1 = Dynamic( Array_obj<Dynamic>::__new().Add(backgroundRepeat));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Array< ::cocktail::core::style::BackgroundClip > backgroundClip1 = Array_obj< ::cocktail::core::style::BackgroundClip >::__new().Add(backgroundClip);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Array< ::cocktail::core::style::BackgroundOrigin > backgroundOrigin1 = Array_obj< ::cocktail::core::style::BackgroundOrigin >::__new().Add(backgroundOrigin);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Array< ::cocktail::core::style::BackgroundSize > backgroundSize1 = Array_obj< ::cocktail::core::style::BackgroundSize >::__new().Add(backgroundSize);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Dynamic backgroundPosition1 = Dynamic( Array_obj<Dynamic>::__new().Add(backgroundPosition));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Dynamic backgroundBox1 = Dynamic( Array_obj<Dynamic>::__new().Add(backgroundBox));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Array< ::cocktail::core::style::AbstractCoreStyle > style1 = Array_obj< ::cocktail::core::style::AbstractCoreStyle >::__new().Add(style);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",181)
	Dynamic imageDeclaration1 = Dynamic( Array_obj<Dynamic>::__new().Add(imageDeclaration));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",185)
	Dynamic backgroundImageNativeElement = Dynamic( Array_obj<Dynamic>::__new().Add(::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::graphic_dyn())));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",187)
	Array< ::cocktail::core::resource::AbstractImageLoader > imageLoader = Array_obj< ::cocktail::core::resource::AbstractImageLoader >::__new().Add(::cocktail::core::resource::AbstractImageLoader_obj::__new());
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",190)
	Dynamic onBackgroundImageLoadedDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->onBackgroundImageLoaded_dyn()));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",194)
	Dynamic onBackgroundImageLoadErrorDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->onBackgroundImageLoadError_dyn()));

	HX_BEGIN_LOCAL_FUNC_S11(hx::LocalFunc,_Function_1_1,Array< ::cocktail::core::style::BackgroundSize >,backgroundSize1,Dynamic,backgroundPosition1,Dynamic,backgroundRepeat1,Array< ::cocktail::core::style::BackgroundImage >,backgroundImage1,Dynamic,backgroundBox1,Dynamic,backgroundImageNativeElement,Array< ::cocktail::core::resource::AbstractImageLoader >,imageLoader,Dynamic,onBackgroundImageLoadedDelegate,Array< ::cocktail::core::style::AbstractCoreStyle >,style1,Array< ::cocktail::core::style::BackgroundOrigin >,backgroundOrigin1,Array< ::cocktail::core::style::BackgroundClip >,backgroundClip1)
	Void run(Dynamic loadedImage){
{
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",200)
			onBackgroundImageLoadedDelegate->__GetItem((int)0)(backgroundImageNativeElement->__GetItem((int)0),loadedImage,imageLoader->__get((int)0),style1->__get((int)0),backgroundBox1->__GetItem((int)0),backgroundPosition1->__GetItem((int)0),backgroundSize1->__get((int)0),backgroundOrigin1->__get((int)0),backgroundClip1->__get((int)0),backgroundRepeat1->__GetItem((int)0),backgroundImage1->__get((int)0)).Cast< Void >();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))


	HX_BEGIN_LOCAL_FUNC_S11(hx::LocalFunc,_Function_1_2,Array< ::cocktail::core::style::BackgroundSize >,backgroundSize1,Dynamic,backgroundPosition1,Dynamic,backgroundRepeat1,Dynamic,imageDeclaration1,Array< ::cocktail::core::style::BackgroundImage >,backgroundImage1,Dynamic,onBackgroundImageLoadErrorDelegate,Dynamic,backgroundBox1,Dynamic,backgroundImageNativeElement,Array< ::cocktail::core::style::AbstractCoreStyle >,style1,Array< ::cocktail::core::style::BackgroundOrigin >,backgroundOrigin1,Array< ::cocktail::core::style::BackgroundClip >,backgroundClip1)
	Void run(::String error){
{
			HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",203)
			onBackgroundImageLoadErrorDelegate->__GetItem((int)0)(error,imageDeclaration1->__GetItem((int)0)->__Field(HX_CSTRING("fallbackColor")),backgroundImageNativeElement->__GetItem((int)0),style1->__get((int)0),backgroundBox1->__GetItem((int)0),backgroundPosition1->__GetItem((int)0),backgroundSize1->__get((int)0),backgroundOrigin1->__get((int)0),backgroundClip1->__get((int)0),backgroundRepeat1->__GetItem((int)0),backgroundImage1->__get((int)0)).Cast< Void >();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",199)
	imageLoader->__get((int)0)->load(imageDeclaration1->__GetItem((int)0)->__Field(HX_CSTRING("urls")), Dynamic(new _Function_1_1(backgroundSize1,backgroundPosition1,backgroundRepeat1,backgroundImage1,backgroundBox1,backgroundImageNativeElement,imageLoader,onBackgroundImageLoadedDelegate,style1,backgroundOrigin1,backgroundClip1)), Dynamic(new _Function_1_2(backgroundSize1,backgroundPosition1,backgroundRepeat1,imageDeclaration1,backgroundImage1,onBackgroundImageLoadErrorDelegate,backgroundBox1,backgroundImageNativeElement,style1,backgroundOrigin1,backgroundClip1)));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",208)
	return backgroundImageNativeElement->__GetItem((int)0);
}


HX_DEFINE_DYNAMIC_FUNC9(BackgroundManager_obj,drawBackgroundImage,return )

Void BackgroundManager_obj::onBackgroundImageLoaded( Dynamic backgroundImageNativeElement,Dynamic loadedBackgroundImage,::cocktail::core::resource::AbstractImageLoader imageLoader,::cocktail::core::style::AbstractCoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
{
		HX_SOURCE_PUSH("BackgroundManager_obj::onBackgroundImageLoaded")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",231)
		Dynamic computedGradientStyles = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::computeIndividualBackground(style,backgroundBox,imageLoader->getIntrinsicWidth(),imageLoader->getIntrinsicHeight(),imageLoader->getIntrinsicRatio(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",235)
		::cocktail::core::background::BackgroundDrawingManager backgroundImageDrawingManager = ::cocktail::core::background::BackgroundDrawingManager_obj::__new(backgroundImageNativeElement,backgroundBox);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",238)
		backgroundImageDrawingManager->drawBackgroundImage(loadedBackgroundImage,this->getBackgroundPositioningBox(computedGradientStyles->__Field(HX_CSTRING("backgroundOrigin"))),this->getBackgroundPaintingBox(computedGradientStyles->__Field(HX_CSTRING("backgroundClip"))),imageLoader->getIntrinsicWidth(),imageLoader->getIntrinsicHeight(),imageLoader->getIntrinsicRatio(),computedGradientStyles->__Field(HX_CSTRING("backgroundSize")),computedGradientStyles->__Field(HX_CSTRING("backgroundPosition")),computedGradientStyles->__Field(HX_CSTRING("backgroundRepeat")));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",249)
		this->_backgroundDrawingManagers->push(backgroundImageDrawingManager);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC11(BackgroundManager_obj,onBackgroundImageLoaded,(void))

Void BackgroundManager_obj::onBackgroundImageLoadError( ::String error,::cocktail::core::unit::CSSColor backgroundColor,Dynamic backgroundImageNativeElement,::cocktail::core::style::AbstractCoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
{
		HX_SOURCE_PUSH("BackgroundManager_obj::onBackgroundImageLoadError")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",271)
		this->drawBackgroundColor(style,::cocktail::core::unit::UnitManager_obj::getColorDataFromCSSColor(backgroundColor),backgroundImageNativeElement,backgroundBox,backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC11(BackgroundManager_obj,onBackgroundImageLoadError,(void))

Void BackgroundManager_obj::drawBackgroundColor( ::cocktail::core::style::AbstractCoreStyle style,Dynamic backgroundColor,Dynamic backgroundColorNativeElement,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
{
		HX_SOURCE_PUSH("BackgroundManager_obj::drawBackgroundColor")
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",294)
		Dynamic computedBackgroundStyles = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::computeIndividualBackground(style,backgroundBox,null(),null(),null(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",298)
		::cocktail::core::background::BackgroundDrawingManager backgroundColorDrawingManager = ::cocktail::core::background::BackgroundDrawingManager_obj::__new(backgroundColorNativeElement,backgroundBox);
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",300)
		backgroundColorDrawingManager->drawBackgroundColor(backgroundColor,this->getBackgroundPaintingBox(computedBackgroundStyles->__Field(HX_CSTRING("backgroundClip"))));
		HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",302)
		this->_backgroundDrawingManagers->push(backgroundColorDrawingManager);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC10(BackgroundManager_obj,drawBackgroundColor,(void))

Dynamic BackgroundManager_obj::drawBackgroundGradient( ::cocktail::core::style::AbstractCoreStyle style,::cocktail::core::unit::GradientValue gradientValue,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
	HX_SOURCE_PUSH("BackgroundManager_obj::drawBackgroundGradient")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",323)
	Dynamic computedGradientStyles = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::computeIndividualBackground(style,backgroundBox,null(),null(),null(),backgroundPosition,backgroundSize,backgroundOrigin,backgroundClip,backgroundRepeat,backgroundImage);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",328)
	Dynamic gradientNativeElement = ::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::graphic_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",330)
	::cocktail::core::background::BackgroundDrawingManager backgroundGradientDrawingManager = ::cocktail::core::background::BackgroundDrawingManager_obj::__new(gradientNativeElement,backgroundBox);
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",332)
	backgroundGradientDrawingManager->drawBackgroundGradient(gradientValue,this->getBackgroundPositioningBox(computedGradientStyles->__Field(HX_CSTRING("backgroundOrigin"))),this->getBackgroundPaintingBox(computedGradientStyles->__Field(HX_CSTRING("backgroundClip"))),computedGradientStyles->__Field(HX_CSTRING("backgroundSize")),computedGradientStyles->__Field(HX_CSTRING("backgroundPosition")),computedGradientStyles->__Field(HX_CSTRING("backgroundRepeat")));
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",340)
	return gradientNativeElement;
}


HX_DEFINE_DYNAMIC_FUNC9(BackgroundManager_obj,drawBackgroundGradient,return )

Dynamic BackgroundManager_obj::getBackgroundPaintingBox( Dynamic computedBackgroundBox){
	HX_SOURCE_PUSH("BackgroundManager_obj::getBackgroundPaintingBox")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",352)
	return computedBackgroundBox;
}


HX_DEFINE_DYNAMIC_FUNC1(BackgroundManager_obj,getBackgroundPaintingBox,return )

Dynamic BackgroundManager_obj::getBackgroundPositioningBox( Dynamic computedPositioningBox){
	HX_SOURCE_PUSH("BackgroundManager_obj::getBackgroundPositioningBox")
	HX_SOURCE_POS("../../src/cocktail/core/background/BackgroundManager.hx",361)
	return computedPositioningBox;
}


HX_DEFINE_DYNAMIC_FUNC1(BackgroundManager_obj,getBackgroundPositioningBox,return )


BackgroundManager_obj::BackgroundManager_obj()
{
}

void BackgroundManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BackgroundManager);
	HX_MARK_MEMBER_NAME(_backgroundDrawingManagers,"_backgroundDrawingManagers");
	HX_MARK_END_CLASS();
}

Dynamic BackgroundManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"drawBackgroundImage") ) { return drawBackgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"drawBackgroundColor") ) { return drawBackgroundColor_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"drawBackgroundGradient") ) { return drawBackgroundGradient_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"onBackgroundImageLoaded") ) { return onBackgroundImageLoaded_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getBackgroundPaintingBox") ) { return getBackgroundPaintingBox_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_backgroundDrawingManagers") ) { return _backgroundDrawingManagers; }
		if (HX_FIELD_EQ(inName,"onBackgroundImageLoadError") ) { return onBackgroundImageLoadError_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"getBackgroundPositioningBox") ) { return getBackgroundPositioningBox_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BackgroundManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 26:
		if (HX_FIELD_EQ(inName,"_backgroundDrawingManagers") ) { _backgroundDrawingManagers=inValue.Cast< Array< ::cocktail::core::background::BackgroundDrawingManager > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BackgroundManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_backgroundDrawingManagers"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_backgroundDrawingManagers"),
	HX_CSTRING("dispose"),
	HX_CSTRING("render"),
	HX_CSTRING("drawBackgroundImage"),
	HX_CSTRING("onBackgroundImageLoaded"),
	HX_CSTRING("onBackgroundImageLoadError"),
	HX_CSTRING("drawBackgroundColor"),
	HX_CSTRING("drawBackgroundGradient"),
	HX_CSTRING("getBackgroundPaintingBox"),
	HX_CSTRING("getBackgroundPositioningBox"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BackgroundManager_obj::__mClass;

void BackgroundManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.background.BackgroundManager"), hx::TCanCast< BackgroundManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BackgroundManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace background
