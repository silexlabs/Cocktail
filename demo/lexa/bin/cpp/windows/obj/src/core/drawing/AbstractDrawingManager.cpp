#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_core_dom_CapsStyleValue
#include <core/dom/CapsStyleValue.h>
#endif
#ifndef INCLUDED_core_dom_FillStyleValue
#include <core/dom/FillStyleValue.h>
#endif
#ifndef INCLUDED_core_dom_JointStyleValue
#include <core/dom/JointStyleValue.h>
#endif
#ifndef INCLUDED_core_dom_LineStyleValue
#include <core/dom/LineStyleValue.h>
#endif
#ifndef INCLUDED_core_drawing_AbstractDrawingManager
#include <core/drawing/AbstractDrawingManager.h>
#endif
#ifndef INCLUDED_core_geom_Matrix
#include <core/geom/Matrix.h>
#endif
namespace core{
namespace drawing{

Void AbstractDrawingManager_obj::__construct(Dynamic nativeElement,int width,int height)
{
{
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",48)
	this->_nativeElement = nativeElement;
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",49)
	this->_width = width;
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",50)
	this->_height = height;
}
;
	return null();
}

AbstractDrawingManager_obj::~AbstractDrawingManager_obj() { }

Dynamic AbstractDrawingManager_obj::__CreateEmpty() { return  new AbstractDrawingManager_obj; }
hx::ObjectPtr< AbstractDrawingManager_obj > AbstractDrawingManager_obj::__new(Dynamic nativeElement,int width,int height)
{  hx::ObjectPtr< AbstractDrawingManager_obj > result = new AbstractDrawingManager_obj();
	result->__construct(nativeElement,width,height);
	return result;}

Dynamic AbstractDrawingManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractDrawingManager_obj > result = new AbstractDrawingManager_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void AbstractDrawingManager_obj::beginFill( ::core::dom::FillStyleValue fillStyle,::core::dom::LineStyleValue lineStyle){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::beginFill")
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",72)
		if (((fillStyle == null()))){
			HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",73)
			fillStyle = ::core::dom::FillStyleValue_obj::none_dyn();
		}
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",77)
		if (((lineStyle == null()))){
			HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",78)
			lineStyle = ::core::dom::LineStyleValue_obj::none_dyn();
		}
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",83)
		this->setFillStyle(fillStyle);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",86)
		this->setLineStyle(lineStyle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractDrawingManager_obj,beginFill,(void))

Void AbstractDrawingManager_obj::endFill( ){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::endFill")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractDrawingManager_obj,endFill,(void))

Void AbstractDrawingManager_obj::clear( ){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::clear")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractDrawingManager_obj,clear,(void))

Void AbstractDrawingManager_obj::setLineStyle( ::core::dom::LineStyleValue lineStyle){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::setLineStyle")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,setLineStyle,(void))

Void AbstractDrawingManager_obj::setFillStyle( ::core::dom::FillStyleValue fillStyle){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::setFillStyle")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,setFillStyle,(void))

Void AbstractDrawingManager_obj::drawRect( int x,int y,int width,int height,Dynamic cornerRadiuses){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::drawRect")
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",145)
		if (((cornerRadiuses == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("tlCornerRadius") , (int)0,false);
					__result->Add(HX_CSTRING("trCornerRadius") , (int)0,false);
					__result->Add(HX_CSTRING("blCornerRadius") , (int)0,false);
					__result->Add(HX_CSTRING("brCornerRadius") , (int)0,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",146)
			cornerRadiuses = _Function_2_1::Block();
		}
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",155)
		this->moveTo((cornerRadiuses->__Field(HX_CSTRING("tlCornerRadius")) + x),y);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",156)
		this->lineTo(((width - cornerRadiuses->__Field(HX_CSTRING("trCornerRadius"))) + x),y);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",159)
		this->curveTo((width + x),y,(width + x),(cornerRadiuses->__Field(HX_CSTRING("trCornerRadius")) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",161)
		this->lineTo((width + x),(cornerRadiuses->__Field(HX_CSTRING("trCornerRadius")) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",162)
		this->lineTo((width + x),((height - cornerRadiuses->__Field(HX_CSTRING("brCornerRadius"))) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",163)
		this->curveTo((width + x),(height + y),((width - cornerRadiuses->__Field(HX_CSTRING("brCornerRadius"))) + x),(height + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",164)
		this->lineTo(((width - cornerRadiuses->__Field(HX_CSTRING("brCornerRadius"))) + x),(height + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",165)
		this->lineTo((cornerRadiuses->__Field(HX_CSTRING("blCornerRadius")) + x),(height + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",166)
		this->curveTo(x,(height + y),x,((height - cornerRadiuses->__Field(HX_CSTRING("blCornerRadius"))) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",167)
		this->lineTo(x,((height - cornerRadiuses->__Field(HX_CSTRING("blCornerRadius"))) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",168)
		this->lineTo(x,(cornerRadiuses->__Field(HX_CSTRING("tlCornerRadius")) + y));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",169)
		this->curveTo(x,y,(cornerRadiuses->__Field(HX_CSTRING("tlCornerRadius")) + x),y);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",170)
		this->lineTo((cornerRadiuses->__Field(HX_CSTRING("tlCornerRadius")) + x),y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractDrawingManager_obj,drawRect,(void))

Void AbstractDrawingManager_obj::drawEllipse( int x,int y,int width,int height){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::drawEllipse")
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",184)
		double xRadius = (double(width) / double((int)2));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",185)
		double yRadius = (double(height) / double((int)2));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",187)
		double xCenter = ((double(width) / double((int)2)) + x);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",188)
		double yCenter = ((double(height) / double((int)2)) + y);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",190)
		double angleDelta = (double(::Math_obj::PI) / double((int)4));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",191)
		double xCtrlDist = (double(xRadius) / double(::Math_obj::cos((double(angleDelta) / double((int)2)))));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",192)
		double yCtrlDist = (double(yRadius) / double(::Math_obj::cos((double(angleDelta) / double((int)2)))));
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",195)
		this->moveTo((xCenter + xRadius),yCenter);
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",196)
		double angle = (int)0;
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",198)
		double rx;
		double ry;
		double ax;
		double ay;
		HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",200)
		{
			HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",200)
			int _g = (int)0;
			HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",200)
			while(((_g < (int)8))){
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",200)
				int i = (_g)++;
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",201)
				hx::AddEq(angle,angleDelta);
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",202)
				rx = (xCenter + (::Math_obj::cos((angle - (double(angleDelta) / double((int)2)))) * xCtrlDist));
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",203)
				ry = (yCenter + (::Math_obj::sin((angle - (double(angleDelta) / double((int)2)))) * yCtrlDist));
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",204)
				ax = (xCenter + (::Math_obj::cos(angle) * xRadius));
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",205)
				ay = (yCenter + (::Math_obj::sin(angle) * yRadius));
				HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",206)
				this->curveTo(rx,ry,ax,ay);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractDrawingManager_obj,drawEllipse,(void))

Void AbstractDrawingManager_obj::drawImage( Dynamic source,::core::geom::Matrix matrix,Dynamic sourceRect){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::drawImage")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractDrawingManager_obj,drawImage,(void))

Void AbstractDrawingManager_obj::lineTo( double x,double y){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::lineTo")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractDrawingManager_obj,lineTo,(void))

Void AbstractDrawingManager_obj::moveTo( double x,double y){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::moveTo")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractDrawingManager_obj,moveTo,(void))

Void AbstractDrawingManager_obj::curveTo( double controlX,double controlY,double x,double y){
{
		HX_SOURCE_PUSH("AbstractDrawingManager_obj::curveTo")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractDrawingManager_obj,curveTo,(void))

Dynamic AbstractDrawingManager_obj::toNativeAlpha( double genericAlpa){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::toNativeAlpha")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",279)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,toNativeAlpha,return )

Dynamic AbstractDrawingManager_obj::toNativeColor( int genericColor){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::toNativeColor")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",289)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,toNativeColor,return )

Dynamic AbstractDrawingManager_obj::toNativeRatio( int genericRatio){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::toNativeRatio")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",299)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,toNativeRatio,return )

Dynamic AbstractDrawingManager_obj::toNativeCapStyle( ::core::dom::CapsStyleValue genericCapStyle){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::toNativeCapStyle")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",309)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,toNativeCapStyle,return )

Dynamic AbstractDrawingManager_obj::toNativeJointStyle( ::core::dom::JointStyleValue genericJointStyle){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::toNativeJointStyle")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",319)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,toNativeJointStyle,return )

Dynamic AbstractDrawingManager_obj::getNativeElement( ){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::getNativeElement")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",328)
	return this->_nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractDrawingManager_obj,getNativeElement,return )

int AbstractDrawingManager_obj::setWidth( int value){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::setWidth")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",333)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,setWidth,return )

int AbstractDrawingManager_obj::getWidth( ){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::getWidth")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",338)
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractDrawingManager_obj,getWidth,return )

int AbstractDrawingManager_obj::setHeight( int value){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::setHeight")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",343)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractDrawingManager_obj,setHeight,return )

int AbstractDrawingManager_obj::getHeight( ){
	HX_SOURCE_PUSH("AbstractDrawingManager_obj::getHeight")
	HX_SOURCE_POS("../../src/core/drawing/AbstractDrawingManager.hx",348)
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractDrawingManager_obj,getHeight,return )


AbstractDrawingManager_obj::AbstractDrawingManager_obj()
{
}

void AbstractDrawingManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractDrawingManager);
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_MARK_MEMBER_NAME(nativeElement,"nativeElement");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

Dynamic AbstractDrawingManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return getWidth(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		if (HX_FIELD_EQ(inName,"height") ) { return getHeight(); }
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		if (HX_FIELD_EQ(inName,"setWidth") ) { return setWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getWidth") ) { return getWidth_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawImage") ) { return drawImage_dyn(); }
		if (HX_FIELD_EQ(inName,"setHeight") ) { return setHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getHeight") ) { return getHeight_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setLineStyle") ) { return setLineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"setFillStyle") ) { return setFillStyle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { return getNativeElement(); }
		if (HX_FIELD_EQ(inName,"toNativeAlpha") ) { return toNativeAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"toNativeColor") ) { return toNativeColor_dyn(); }
		if (HX_FIELD_EQ(inName,"toNativeRatio") ) { return toNativeRatio_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"toNativeCapStyle") ) { return toNativeCapStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"getNativeElement") ) { return getNativeElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"toNativeJointStyle") ) { return toNativeJointStyle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractDrawingManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return setWidth(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { return setHeight(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractDrawingManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeElement"));
	outFields->push(HX_CSTRING("nativeElement"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("nativeElement"),
	HX_CSTRING("_width"),
	HX_CSTRING("width"),
	HX_CSTRING("_height"),
	HX_CSTRING("height"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("endFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("setLineStyle"),
	HX_CSTRING("setFillStyle"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawImage"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("toNativeAlpha"),
	HX_CSTRING("toNativeColor"),
	HX_CSTRING("toNativeRatio"),
	HX_CSTRING("toNativeCapStyle"),
	HX_CSTRING("toNativeJointStyle"),
	HX_CSTRING("getNativeElement"),
	HX_CSTRING("setWidth"),
	HX_CSTRING("getWidth"),
	HX_CSTRING("setHeight"),
	HX_CSTRING("getHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractDrawingManager_obj::__mClass;

void AbstractDrawingManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.drawing.AbstractDrawingManager"), hx::TCanCast< AbstractDrawingManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractDrawingManager_obj::__boot()
{
}

} // end namespace core
} // end namespace drawing
