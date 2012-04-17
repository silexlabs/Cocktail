#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CapsStyleValue
#include <cocktail/core/dom/CapsStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_FillStyleValue
#include <cocktail/core/dom/FillStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_GradientTypeValue
#include <cocktail/core/dom/GradientTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_JointStyleValue
#include <cocktail/core/dom/JointStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_LineStyleValue
#include <cocktail/core/dom/LineStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_drawing_AbstractDrawingManager
#include <cocktail/core/drawing/AbstractDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLImageElement
#include <cocktail/core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_DrawingManager
#include <cocktail/port/flash_player/DrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_nme_display_Bitmap
#include <nme/display/Bitmap.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_GradientType
#include <nme/display/GradientType.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_PixelSnapping
#include <nme/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void DrawingManager_obj::__construct(Dynamic nativeElement,int width,int height)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",55)
	super::__construct(nativeElement,width,height);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",57)
	this->_typedNativeElement = this->_nativeElement;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",60)
	this->_bitmapDrawing = ::nme::display::Bitmap_obj::__new(::nme::display::BitmapData_obj::__new(this->_width,this->_height,true,(int)0),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",61)
	this->_nativeElement->__Field(HX_CSTRING("addChild"))(this->_bitmapDrawing);
}
;
	return null();
}

DrawingManager_obj::~DrawingManager_obj() { }

Dynamic DrawingManager_obj::__CreateEmpty() { return  new DrawingManager_obj; }
hx::ObjectPtr< DrawingManager_obj > DrawingManager_obj::__new(Dynamic nativeElement,int width,int height)
{  hx::ObjectPtr< DrawingManager_obj > result = new DrawingManager_obj();
	result->__construct(nativeElement,width,height);
	return result;}

Dynamic DrawingManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DrawingManager_obj > result = new DrawingManager_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void DrawingManager_obj::endFill( ){
{
		HX_SOURCE_PUSH("DrawingManager_obj::endFill")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",74)
		this->_typedNativeElement->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",75)
		this->blit();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",76)
		this->_typedNativeElement->nmeGetGraphics()->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DrawingManager_obj,endFill,(void))

Void DrawingManager_obj::clear( ){
{
		HX_SOURCE_PUSH("DrawingManager_obj::clear")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",84)
		this->_typedNativeElement->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",85)
		this->_bitmapDrawing->bitmapData->fillRect(::nme::geom::Rectangle_obj::__new((int)0,(int)0,this->getWidth(),this->getHeight()),(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DrawingManager_obj,clear,(void))

Void DrawingManager_obj::blit( ){
{
		HX_SOURCE_PUSH("DrawingManager_obj::blit")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",100)
		::nme::display::BitmapData currentGraphicBitmapData = ::nme::display::BitmapData_obj::__new(::Math_obj::round(this->_typedNativeElement->nmeGetWidth()),::Math_obj::round(this->_typedNativeElement->nmeGetHeight()),true,(int)0);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",103)
		currentGraphicBitmapData->draw(this->_typedNativeElement,null(),null(),null(),null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",107)
		::nme::display::BitmapData bitmapData = this->_bitmapDrawing->bitmapData;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",111)
		bitmapData->copyPixels(currentGraphicBitmapData,::nme::geom::Rectangle_obj::__new((int)0,(int)0,this->getWidth(),this->getHeight()),::nme::geom::Point_obj::__new((int)0,(int)0),null(),null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",114)
		this->_bitmapDrawing->nmeSetBitmapData(bitmapData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DrawingManager_obj,blit,(void))

Void DrawingManager_obj::setFillStyle( ::cocktail::core::dom::FillStyleValue fillStyle){
{
		HX_SOURCE_PUSH("DrawingManager_obj::setFillStyle")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",127)
		{
::cocktail::core::dom::FillStyleValue _switch_1 = (fillStyle);
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",132)
					this->_typedNativeElement->nmeGetGraphics()->beginFill((int)0,(int)0);
				}
				;break;
				case 1: {
					Dynamic colorStop = _switch_1->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",136)
						this->_typedNativeElement->nmeGetGraphics()->beginFill(colorStop->__Field(HX_CSTRING("color")),this->toNativeAlpha(colorStop->__Field(HX_CSTRING("alpha"))));
					}
				}
				;break;
				case 2: {
					Dynamic gradientStyle = _switch_1->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",140)
						this->_typedNativeElement->nmeGetGraphics()->beginGradientFill(this->getGradientType(gradientStyle->__Field(HX_CSTRING("gradientType"))),this->getGradientColors(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientAlphas(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientRatios(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientBox(gradientStyle),null(),null(),null());
					}
				}
				;break;
				case 3: {
					bool repeat = _switch_1->__Param(1);
					::cocktail::core::html::AbstractHTMLImageElement imageHTMLElement = _switch_1->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",152)
						this->_typedNativeElement->nmeGetGraphics()->beginBitmapFill(this->getBitmapData(imageHTMLElement->get_nativeElement()),::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null()),repeat,null());
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,setFillStyle,(void))

Void DrawingManager_obj::setLineStyle( ::cocktail::core::dom::LineStyleValue lineStyle){
{
		HX_SOURCE_PUSH("DrawingManager_obj::setLineStyle")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",162)
		{
::cocktail::core::dom::LineStyleValue _switch_2 = (lineStyle);
			switch((_switch_2)->GetIndex()){
				case 0: {
				}
				;break;
				case 1: {
					Dynamic lineStyleData = _switch_2->__Param(1);
					Dynamic color = _switch_2->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",169)
						this->_typedNativeElement->nmeGetGraphics()->lineStyle(lineStyleData->__Field(HX_CSTRING("thickness")),color->__Field(HX_CSTRING("color")),this->toNativeAlpha(color->__Field(HX_CSTRING("alpha"))),true,::nme::display::LineScaleMode_obj::NORMAL_dyn(),this->toNativeCapStyle(lineStyleData->__Field(HX_CSTRING("capStyle"))),this->toNativeJointStyle(lineStyleData->__Field(HX_CSTRING("jointStyle"))),lineStyleData->__Field(HX_CSTRING("miterLimit")));
					}
				}
				;break;
				case 2: {
					Dynamic lineStyleData = _switch_2->__Param(1);
					Dynamic gradientStyle = _switch_2->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",185)
						this->_typedNativeElement->nmeGetGraphics()->lineStyle(lineStyleData->__Field(HX_CSTRING("thickness")),(int)0,(int)1,true,::nme::display::LineScaleMode_obj::NONE_dyn(),this->toNativeCapStyle(lineStyleData->__Field(HX_CSTRING("capStyle"))),this->toNativeJointStyle(lineStyleData->__Field(HX_CSTRING("jointStyle"))),lineStyleData->__Field(HX_CSTRING("miterLimit")));
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",195)
						this->_typedNativeElement->nmeGetGraphics()->lineGradientStyle(this->getGradientType(gradientStyle->__Field(HX_CSTRING("gradientType"))),this->getGradientColors(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientAlphas(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientRatios(gradientStyle->__Field(HX_CSTRING("gradientStops"))),this->getGradientBox(gradientStyle),null(),null(),null());
					}
				}
				;break;
				case 3: {
					bool repeat = _switch_2->__Param(2);
					Dynamic lineStyleData = _switch_2->__Param(1);
					::cocktail::core::html::AbstractHTMLImageElement imageHTMLElement = _switch_2->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",208)
						this->_typedNativeElement->nmeGetGraphics()->lineStyle(lineStyleData->__Field(HX_CSTRING("thickness")),(int)0,(int)1,true,::nme::display::LineScaleMode_obj::NONE_dyn(),this->toNativeCapStyle(lineStyleData->__Field(HX_CSTRING("capStyle"))),this->toNativeJointStyle(lineStyleData->__Field(HX_CSTRING("jointStyle"))),lineStyleData->__Field(HX_CSTRING("miterLimit")));
						HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",219)
						this->_typedNativeElement->nmeGetGraphics()->lineBitmapStyle(this->getBitmapData(imageHTMLElement->get_nativeElement()),::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null()),repeat,null());
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,setLineStyle,(void))

Void DrawingManager_obj::drawImage( Dynamic source,::cocktail::core::geom::Matrix matrix,Dynamic sourceRect){
{
		HX_SOURCE_PUSH("DrawingManager_obj::drawImage")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",234)
		if (((matrix == null()))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",235)
			matrix = ::cocktail::core::geom::Matrix_obj::__new(null());
		}
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",239)
		if (((sourceRect == null()))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",241)
			double width = source->__Field(HX_CSTRING("width"));
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",242)
			double height = source->__Field(HX_CSTRING("height"));
			struct _Function_2_1{
				inline static Dynamic Block( double &width,double &height){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , 0.0,false);
					__result->Add(HX_CSTRING("y") , 0.0,false);
					__result->Add(HX_CSTRING("width") , width,false);
					__result->Add(HX_CSTRING("height") , height,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",243)
			sourceRect = _Function_2_1::Block(width,height);
		}
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",252)
		::nme::display::BitmapData sourceBitmapData = this->getBitmapData(source);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",253)
		::nme::display::BitmapData currentBitmapData = this->_bitmapDrawing->bitmapData;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",256)
		::nme::geom::Rectangle nativeSourceRect = ::nme::geom::Rectangle_obj::__new(sourceRect->__Field(HX_CSTRING("x")),sourceRect->__Field(HX_CSTRING("y")),sourceRect->__Field(HX_CSTRING("width")),sourceRect->__Field(HX_CSTRING("height")));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",258)
		Dynamic matrixData = matrix->getData();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",259)
		::nme::geom::Matrix nativeMatrix = ::nme::geom::Matrix_obj::__new(matrixData->__Field(HX_CSTRING("a")),matrixData->__Field(HX_CSTRING("b")),matrixData->__Field(HX_CSTRING("c")),matrixData->__Field(HX_CSTRING("d")),matrixData->__Field(HX_CSTRING("e")),matrixData->__Field(HX_CSTRING("f")));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",262)
		currentBitmapData->draw(sourceBitmapData,nativeMatrix,null(),null(),nativeSourceRect,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DrawingManager_obj,drawImage,(void))

Void DrawingManager_obj::lineTo( double x,double y){
{
		HX_SOURCE_PUSH("DrawingManager_obj::lineTo")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",273)
		this->_typedNativeElement->nmeGetGraphics()->lineTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DrawingManager_obj,lineTo,(void))

Void DrawingManager_obj::moveTo( double x,double y){
{
		HX_SOURCE_PUSH("DrawingManager_obj::moveTo")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",281)
		this->_typedNativeElement->nmeGetGraphics()->moveTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DrawingManager_obj,moveTo,(void))

Void DrawingManager_obj::curveTo( double controlX,double controlY,double x,double y){
{
		HX_SOURCE_PUSH("DrawingManager_obj::curveTo")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",289)
		this->_typedNativeElement->nmeGetGraphics()->curveTo(controlX,controlY,x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(DrawingManager_obj,curveTo,(void))

Dynamic DrawingManager_obj::toNativeAlpha( double genericAlpha){
	HX_SOURCE_PUSH("DrawingManager_obj::toNativeAlpha")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",301)
	return genericAlpha;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,toNativeAlpha,return )

Dynamic DrawingManager_obj::toNativeRatio( int genericRatio){
	HX_SOURCE_PUSH("DrawingManager_obj::toNativeRatio")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",310)
	if (((genericRatio == (int)0))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",311)
		return (int)0;
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",314)
	return ::Math_obj::round(((double((int)255) / double(genericRatio)) * (int)100));
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,toNativeRatio,return )

Dynamic DrawingManager_obj::toNativeCapStyle( ::cocktail::core::dom::CapsStyleValue genericCapStyle){
	HX_SOURCE_PUSH("DrawingManager_obj::toNativeCapStyle")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",323)
	::nme::display::CapsStyle capStyle = ::nme::display::CapsStyle_obj::ROUND_dyn();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",325)
	{
::cocktail::core::dom::CapsStyleValue _switch_3 = (genericCapStyle);
		switch((_switch_3)->GetIndex()){
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",327)
				capStyle = ::nme::display::CapsStyle_obj::ROUND_dyn();
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",330)
				capStyle = ::nme::display::CapsStyle_obj::SQUARE_dyn();
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",333)
				capStyle = ::nme::display::CapsStyle_obj::NONE_dyn();
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",337)
	return capStyle;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,toNativeCapStyle,return )

Dynamic DrawingManager_obj::toNativeJointStyle( ::cocktail::core::dom::JointStyleValue genericJointStyle){
	HX_SOURCE_PUSH("DrawingManager_obj::toNativeJointStyle")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",346)
	::nme::display::JointStyle jointStyle = ::nme::display::JointStyle_obj::BEVEL_dyn();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",348)
	{
::cocktail::core::dom::JointStyleValue _switch_4 = (genericJointStyle);
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",350)
				jointStyle = ::nme::display::JointStyle_obj::MITER_dyn();
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",353)
				jointStyle = ::nme::display::JointStyle_obj::ROUND_dyn();
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",356)
				jointStyle = ::nme::display::JointStyle_obj::BEVEL_dyn();
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",360)
	return jointStyle;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,toNativeJointStyle,return )

::nme::display::GradientType DrawingManager_obj::getGradientType( ::cocktail::core::dom::GradientTypeValue genericGradientType){
	HX_SOURCE_PUSH("DrawingManager_obj::getGradientType")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",374)
	::nme::display::GradientType gradientType = ::nme::display::GradientType_obj::LINEAR_dyn();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",376)
	{
::cocktail::core::dom::GradientTypeValue _switch_5 = (genericGradientType);
		switch((_switch_5)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",378)
				gradientType = ::nme::display::GradientType_obj::LINEAR_dyn();
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",381)
				gradientType = ::nme::display::GradientType_obj::RADIAL_dyn();
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",385)
	return gradientType;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getGradientType,return )

::nme::display::BitmapData DrawingManager_obj::getBitmapData( Dynamic nativeElement){
	HX_SOURCE_PUSH("DrawingManager_obj::getBitmapData")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",394)
	int nativeElementWidth = ::Math_obj::round(nativeElement->__Field(HX_CSTRING("width")));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",395)
	int nativeElementHeight = ::Math_obj::round(nativeElement->__Field(HX_CSTRING("height")));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",397)
	::nme::display::BitmapData bitmapData = ::nme::display::BitmapData_obj::__new(nativeElementWidth,nativeElementHeight,true,(int)0);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",398)
	bitmapData->draw(nativeElement,null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",400)
	return bitmapData;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getBitmapData,return )

Array< int > DrawingManager_obj::getGradientColors( Dynamic gradientStops){
	HX_SOURCE_PUSH("DrawingManager_obj::getGradientColors")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",410)
	Array< int > ret = Array_obj< int >::__new();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",412)
	{
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",412)
		int _g1 = (int)0;
		int _g = gradientStops->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",412)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",412)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",414)
			ret[i] = gradientStops->__GetItem(i)->__Field(HX_CSTRING("colorStop"))->__Field(HX_CSTRING("color"));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",417)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getGradientColors,return )

Array< double > DrawingManager_obj::getGradientAlphas( Dynamic gradientStops){
	HX_SOURCE_PUSH("DrawingManager_obj::getGradientAlphas")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",427)
	Array< double > ret = Array_obj< double >::__new();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",429)
	{
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",429)
		int _g1 = (int)0;
		int _g = gradientStops->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",429)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",429)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",431)
			ret[i] = this->toNativeAlpha(gradientStops->__GetItem(i)->__Field(HX_CSTRING("colorStop"))->__Field(HX_CSTRING("alpha")));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",434)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getGradientAlphas,return )

Array< int > DrawingManager_obj::getGradientRatios( Dynamic gradientStops){
	HX_SOURCE_PUSH("DrawingManager_obj::getGradientRatios")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",444)
	Array< int > ret = Array_obj< int >::__new();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",446)
	{
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",446)
		int _g1 = (int)0;
		int _g = gradientStops->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",446)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",446)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",448)
			ret[i] = this->toNativeRatio(gradientStops->__GetItem(i)->__Field(HX_CSTRING("ratio")));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",450)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getGradientRatios,return )

::nme::geom::Matrix DrawingManager_obj::getGradientBox( Dynamic gradientStyle){
	HX_SOURCE_PUSH("DrawingManager_obj::getGradientBox")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",460)
	::nme::geom::Matrix gradientBox = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",461)
	gradientBox->createGradientBox(this->getWidth(),this->getHeight(),((double(gradientStyle->__Field(HX_CSTRING("rotation"))) / double((int)180)) * ::Math_obj::PI),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",462)
	return gradientBox;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,getGradientBox,return )

int DrawingManager_obj::setWidth( int value){
	HX_SOURCE_PUSH("DrawingManager_obj::setWidth")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",472)
	this->super::setWidth(value);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",473)
	this->_bitmapDrawing = ::nme::display::Bitmap_obj::__new(::nme::display::BitmapData_obj::__new(value,this->getHeight(),true,(int)0),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",474)
	this->_nativeElement->__Field(HX_CSTRING("addChild"))(this->_bitmapDrawing);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",475)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,setWidth,return )

int DrawingManager_obj::setHeight( int value){
	HX_SOURCE_PUSH("DrawingManager_obj::setHeight")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",481)
	this->super::setHeight(value);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",482)
	this->_bitmapDrawing = ::nme::display::Bitmap_obj::__new(::nme::display::BitmapData_obj::__new(this->getWidth(),value,true,(int)0),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",483)
	this->_nativeElement->__Field(HX_CSTRING("addChild"))(this->_bitmapDrawing);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/DrawingManager.hx",484)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(DrawingManager_obj,setHeight,return )


DrawingManager_obj::DrawingManager_obj()
{
}

void DrawingManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DrawingManager);
	HX_MARK_MEMBER_NAME(_bitmapDrawing,"_bitmapDrawing");
	HX_MARK_MEMBER_NAME(_typedNativeElement,"_typedNativeElement");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic DrawingManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"blit") ) { return blit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setWidth") ) { return setWidth_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawImage") ) { return drawImage_dyn(); }
		if (HX_FIELD_EQ(inName,"setHeight") ) { return setHeight_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setFillStyle") ) { return setFillStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"setLineStyle") ) { return setLineStyle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"toNativeAlpha") ) { return toNativeAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"toNativeRatio") ) { return toNativeRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_bitmapDrawing") ) { return _bitmapDrawing; }
		if (HX_FIELD_EQ(inName,"getGradientBox") ) { return getGradientBox_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getGradientType") ) { return getGradientType_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"toNativeCapStyle") ) { return toNativeCapStyle_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getGradientColors") ) { return getGradientColors_dyn(); }
		if (HX_FIELD_EQ(inName,"getGradientAlphas") ) { return getGradientAlphas_dyn(); }
		if (HX_FIELD_EQ(inName,"getGradientRatios") ) { return getGradientRatios_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"toNativeJointStyle") ) { return toNativeJointStyle_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_typedNativeElement") ) { return _typedNativeElement; }
	}
	return super::__Field(inName);
}

Dynamic DrawingManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"_bitmapDrawing") ) { _bitmapDrawing=inValue.Cast< ::nme::display::Bitmap >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_typedNativeElement") ) { _typedNativeElement=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void DrawingManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bitmapDrawing"));
	outFields->push(HX_CSTRING("_typedNativeElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_bitmapDrawing"),
	HX_CSTRING("_typedNativeElement"),
	HX_CSTRING("endFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("blit"),
	HX_CSTRING("setFillStyle"),
	HX_CSTRING("setLineStyle"),
	HX_CSTRING("drawImage"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("toNativeAlpha"),
	HX_CSTRING("toNativeRatio"),
	HX_CSTRING("toNativeCapStyle"),
	HX_CSTRING("toNativeJointStyle"),
	HX_CSTRING("getGradientType"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getGradientColors"),
	HX_CSTRING("getGradientAlphas"),
	HX_CSTRING("getGradientRatios"),
	HX_CSTRING("getGradientBox"),
	HX_CSTRING("setWidth"),
	HX_CSTRING("setHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class DrawingManager_obj::__mClass;

void DrawingManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.DrawingManager"), hx::TCanCast< DrawingManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DrawingManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
