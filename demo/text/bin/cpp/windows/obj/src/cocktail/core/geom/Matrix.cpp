#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void Matrix_obj::__construct(Dynamic data)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",36)
	this->setData(data);
}
;
	return null();
}

Matrix_obj::~Matrix_obj() { }

Dynamic Matrix_obj::__CreateEmpty() { return  new Matrix_obj; }
hx::ObjectPtr< Matrix_obj > Matrix_obj::__new(Dynamic data)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(data);
	return result;}

Dynamic Matrix_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Matrix_obj::identity( ){
{
		HX_SOURCE_PUSH("Matrix_obj::identity")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , 1.0,false);
				__result->Add(HX_CSTRING("b") , 0.0,false);
				__result->Add(HX_CSTRING("c") , 0.0,false);
				__result->Add(HX_CSTRING("d") , 1.0,false);
				__result->Add(HX_CSTRING("e") , 0.0,false);
				__result->Add(HX_CSTRING("f") , 0.0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",48)
		this->_data = _Function_1_1::Block();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,identity,(void))

Dynamic Matrix_obj::setData( Dynamic data){
	HX_SOURCE_PUSH("Matrix_obj::setData")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",67)
	this->_data = data;
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",70)
	if (((this->_data == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",71)
		this->identity();
	}
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",75)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,setData,return )

Dynamic Matrix_obj::getData( ){
	HX_SOURCE_PUSH("Matrix_obj::getData")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",83)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getData,return )

Void Matrix_obj::concatenate( ::cocktail::core::geom::Matrix matrix){
{
		HX_SOURCE_PUSH("Matrix_obj::concatenate")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",101)
		Dynamic currentMatrixData = this->_data;
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",102)
		Dynamic targetMatrixData = matrix->getData();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",105)
		double a = ((currentMatrixData->__Field(HX_CSTRING("a")) * targetMatrixData->__Field(HX_CSTRING("a"))) + (currentMatrixData->__Field(HX_CSTRING("c")) * targetMatrixData->__Field(HX_CSTRING("b"))));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",106)
		double b = ((currentMatrixData->__Field(HX_CSTRING("b")) * targetMatrixData->__Field(HX_CSTRING("a"))) + (currentMatrixData->__Field(HX_CSTRING("d")) * targetMatrixData->__Field(HX_CSTRING("b"))));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",107)
		double c = ((currentMatrixData->__Field(HX_CSTRING("a")) * targetMatrixData->__Field(HX_CSTRING("c"))) + (currentMatrixData->__Field(HX_CSTRING("c")) * targetMatrixData->__Field(HX_CSTRING("d"))));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",108)
		double d = ((currentMatrixData->__Field(HX_CSTRING("b")) * targetMatrixData->__Field(HX_CSTRING("c"))) + (currentMatrixData->__Field(HX_CSTRING("d")) * targetMatrixData->__Field(HX_CSTRING("d"))));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",109)
		double e = (((currentMatrixData->__Field(HX_CSTRING("a")) * targetMatrixData->__Field(HX_CSTRING("e"))) + (currentMatrixData->__Field(HX_CSTRING("c")) * targetMatrixData->__Field(HX_CSTRING("f")))) + currentMatrixData->__Field(HX_CSTRING("e")));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",110)
		double f = (((currentMatrixData->__Field(HX_CSTRING("b")) * targetMatrixData->__Field(HX_CSTRING("e"))) + (currentMatrixData->__Field(HX_CSTRING("d")) * targetMatrixData->__Field(HX_CSTRING("f")))) + currentMatrixData->__Field(HX_CSTRING("f")));
		struct _Function_1_1{
			inline static Dynamic Block( double &b,double &e,double &a,double &d,double &c,double &f){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , a,false);
				__result->Add(HX_CSTRING("b") , b,false);
				__result->Add(HX_CSTRING("c") , c,false);
				__result->Add(HX_CSTRING("d") , d,false);
				__result->Add(HX_CSTRING("e") , e,false);
				__result->Add(HX_CSTRING("f") , f,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",113)
		Dynamic concatenatedMatrixData = _Function_1_1::Block(b,e,a,d,c,f);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",123)
		this->setData(concatenatedMatrixData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,concatenate,(void))

Void Matrix_obj::translate( double x,double y){
{
		HX_SOURCE_PUSH("Matrix_obj::translate")
		struct _Function_1_1{
			inline static Dynamic Block( double &x,double &y){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , 1.0,false);
				__result->Add(HX_CSTRING("b") , 0.0,false);
				__result->Add(HX_CSTRING("c") , 0.0,false);
				__result->Add(HX_CSTRING("d") , 1.0,false);
				__result->Add(HX_CSTRING("e") , x,false);
				__result->Add(HX_CSTRING("f") , y,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",140)
		Dynamic translationMatrixData = _Function_1_1::Block(x,y);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",150)
		::cocktail::core::geom::Matrix translationMatrix = ::cocktail::core::geom::Matrix_obj::__new(translationMatrixData);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",154)
		this->concatenate(translationMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,translate,(void))

Void Matrix_obj::rotate( double angle,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::rotate")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",168)
		::cocktail::core::geom::Matrix rotatedMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",171)
		rotatedMatrix->translate(registrationPoint->__Field(HX_CSTRING("x")),registrationPoint->__Field(HX_CSTRING("y")));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",173)
		double a = 0.0;
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",174)
		double b = 0.0;
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",175)
		double c = 0.0;
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",176)
		double d = 0.0;
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",180)
		if (((angle == (double(::Math_obj::PI) / double((int)2))))){
			HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",182)
			a = d = 0.0;
			HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",183)
			c = b = 1.0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",186)
			if (((angle == ::Math_obj::PI))){
				HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",188)
				a = d = -1.0;
				HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",189)
				c = b = 0.0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",191)
				if (((angle == (double((::Math_obj::PI * (int)3)) / double((int)2))))){
					HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",193)
					a = d = 0.0;
					HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",194)
					c = b = -1.0;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",198)
					a = d = ::Math_obj::cos(angle);
					HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",199)
					c = b = ::Math_obj::sin(angle);
				}
			}
		}
		struct _Function_1_1{
			inline static Dynamic Block( double &b,double &a,double &d,double &c){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , a,false);
				__result->Add(HX_CSTRING("b") , b,false);
				__result->Add(HX_CSTRING("c") , (c * -1.0),false);
				__result->Add(HX_CSTRING("d") , d,false);
				__result->Add(HX_CSTRING("e") , 0.0,false);
				__result->Add(HX_CSTRING("f") , 0.0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",204)
		Dynamic rotationMatrixData = _Function_1_1::Block(b,a,d,c);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",214)
		::cocktail::core::geom::Matrix rotationMatrix = ::cocktail::core::geom::Matrix_obj::__new(rotationMatrixData);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",218)
		rotatedMatrix->concatenate(rotationMatrix);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",221)
		rotatedMatrix->translate((registrationPoint->__Field(HX_CSTRING("x")) * (int)-1),(registrationPoint->__Field(HX_CSTRING("y")) * (int)-1));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",225)
		this->concatenate(rotatedMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,rotate,(void))

Void Matrix_obj::scale( double scaleX,double scaleY,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::scale")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",240)
		::cocktail::core::geom::Matrix scaledMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",243)
		scaledMatrix->translate(registrationPoint->__Field(HX_CSTRING("x")),registrationPoint->__Field(HX_CSTRING("y")));
		struct _Function_1_1{
			inline static Dynamic Block( double &scaleX,double &scaleY){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , scaleX,false);
				__result->Add(HX_CSTRING("b") , 0.0,false);
				__result->Add(HX_CSTRING("c") , 0.0,false);
				__result->Add(HX_CSTRING("d") , scaleY,false);
				__result->Add(HX_CSTRING("e") , 0.0,false);
				__result->Add(HX_CSTRING("f") , 0.0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",247)
		Dynamic scalingMatrixData = _Function_1_1::Block(scaleX,scaleY);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",257)
		::cocktail::core::geom::Matrix scalingMatrix = ::cocktail::core::geom::Matrix_obj::__new(scalingMatrixData);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",261)
		scaledMatrix->concatenate(scalingMatrix);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",264)
		scaledMatrix->translate((registrationPoint->__Field(HX_CSTRING("x")) * (int)-1),(registrationPoint->__Field(HX_CSTRING("y")) * (int)-1));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",268)
		this->concatenate(scaledMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,scale,(void))

Void Matrix_obj::skew( double skewX,double skewY,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::skew")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",283)
		::cocktail::core::geom::Matrix skewedMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",286)
		skewedMatrix->translate(registrationPoint->__Field(HX_CSTRING("x")),registrationPoint->__Field(HX_CSTRING("y")));
		struct _Function_1_1{
			inline static Dynamic Block( double &skewY,double &skewX){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("a") , 1.0,false);
				__result->Add(HX_CSTRING("b") , ::Math_obj::tan(skewY),false);
				__result->Add(HX_CSTRING("c") , ::Math_obj::tan(skewX),false);
				__result->Add(HX_CSTRING("d") , 1.0,false);
				__result->Add(HX_CSTRING("e") , 0.0,false);
				__result->Add(HX_CSTRING("f") , 0.0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",290)
		Dynamic skewingMatrixData = _Function_1_1::Block(skewY,skewX);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",300)
		::cocktail::core::geom::Matrix skewingMatrix = ::cocktail::core::geom::Matrix_obj::__new(skewingMatrixData);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",304)
		skewedMatrix->concatenate(skewingMatrix);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",307)
		skewedMatrix->translate((registrationPoint->__Field(HX_CSTRING("x")) * (int)-1),(registrationPoint->__Field(HX_CSTRING("y")) * (int)-1));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",311)
		this->concatenate(skewedMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,skew,(void))

Void Matrix_obj::setRotation( double angle,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::setRotation")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",327)
		double currentRotation = this->getRotation();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",330)
		double resetAngle = ((::Math_obj::PI * (int)2) - currentRotation);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",333)
		this->rotate(resetAngle,registrationPoint);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",336)
		this->rotate(angle,registrationPoint);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,setRotation,(void))

double Matrix_obj::getRotation( ){
	HX_SOURCE_PUSH("Matrix_obj::getRotation")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",346)
	int flip = this->getFlip();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",349)
	double scaleX = this->getScaleX();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",350)
	double skewX = this->getSkewX();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",353)
	double actualScaleX = ::Math_obj::sqrt(((scaleX * scaleX) + (skewX * skewX)));
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",356)
	double scaleY = this->getScaleY();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",357)
	double skewY = (this->getSkewY() * flip);
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",359)
	double actualScaleY = ::Math_obj::sqrt(((scaleY * scaleY) + (skewY * skewY)));
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",362)
	double rotationInRad = ::Math_obj::atan2(((double(skewY) / double(actualScaleY)) - (double(skewX) / double(actualScaleX))),((double(scaleY) / double(actualScaleY)) + (double(scaleX) / double(actualScaleX))));
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",366)
	if (((rotationInRad < (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",367)
		rotationInRad = (::Math_obj::PI + rotationInRad);
	}
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",371)
	return rotationInRad;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getRotation,return )

int Matrix_obj::getFlip( ){
	HX_SOURCE_PUSH("Matrix_obj::getFlip")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",383)
	double scaleX = this->getScaleX();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",384)
	int scaleXSign = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",388)
	if (((scaleX >= (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",389)
		scaleXSign = (int)1;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",393)
		scaleXSign = (int)-1;
	}
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",398)
	double scaleY = this->getScaleY();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",399)
	int scaleYSign = (  (((scaleY >= (int)0))) ? int((int)1) : int((int)-1) );
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",401)
	double skewX = this->getSkewX();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",402)
	int skewXSign = (  (((skewX >= (int)0))) ? int((int)1) : int((int)-1) );
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",404)
	double skewY = this->getSkewY();
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",405)
	int skewYSign = (  (((skewY >= (int)0))) ? int((int)1) : int((int)-1) );
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",408)
	if (((bool((scaleXSign == scaleYSign)) && bool((skewXSign == (skewYSign * (int)-1)))))){
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",409)
		return (int)1;
	}
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",413)
	if (((bool((scaleXSign == (scaleYSign * (int)-1))) && bool((skewXSign == skewYSign))))){
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",414)
		return (int)-1;
	}
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",419)
	return (int)1;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getFlip,return )

Void Matrix_obj::setScaleX( double scaleXFactor,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::setScaleX")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",431)
		double currentScaleX = this->getScaleX();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",434)
		double resetScaleX = (double((int)1) / double(currentScaleX));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",437)
		this->scale(resetScaleX,(int)1,registrationPoint);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",440)
		this->scale(scaleXFactor,(int)1,registrationPoint);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,setScaleX,(void))

double Matrix_obj::getScaleX( ){
	HX_SOURCE_PUSH("Matrix_obj::getScaleX")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",447)
	return this->_data->__Field(HX_CSTRING("a"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getScaleX,return )

Void Matrix_obj::setScaleY( double scaleYFactor,Dynamic registrationPoint){
{
		HX_SOURCE_PUSH("Matrix_obj::setScaleY")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",459)
		double currentScaleY = this->getScaleY();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",462)
		double resetScaleY = (double((int)1) / double(currentScaleY));
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",465)
		this->scale((int)1,resetScaleY,registrationPoint);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",468)
		this->scale((int)1,scaleYFactor,registrationPoint);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,setScaleY,(void))

double Matrix_obj::getScaleY( ){
	HX_SOURCE_PUSH("Matrix_obj::getScaleY")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",475)
	return this->_data->__Field(HX_CSTRING("d"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getScaleY,return )

Void Matrix_obj::setTranslationX( double translationX){
{
		HX_SOURCE_PUSH("Matrix_obj::setTranslationX")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",486)
		double currentTranslationX = this->getTranslationX();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",489)
		double resetTranslationX = (currentTranslationX * (int)-1);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",491)
		this->translate(resetTranslationX,(int)0);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",494)
		this->translate(translationX,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,setTranslationX,(void))

double Matrix_obj::getTranslationX( ){
	HX_SOURCE_PUSH("Matrix_obj::getTranslationX")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",501)
	return this->_data->__Field(HX_CSTRING("e"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getTranslationX,return )

Void Matrix_obj::setTranslationY( double translationY){
{
		HX_SOURCE_PUSH("Matrix_obj::setTranslationY")
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",512)
		double currentTranslationY = this->getTranslationY();
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",515)
		double resetTranslationY = (currentTranslationY * (int)-1);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",517)
		this->translate((int)0,resetTranslationY);
		HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",520)
		this->translate((int)0,translationY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,setTranslationY,(void))

double Matrix_obj::getTranslationY( ){
	HX_SOURCE_PUSH("Matrix_obj::getTranslationY")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",527)
	return this->_data->__Field(HX_CSTRING("f"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getTranslationY,return )

double Matrix_obj::getSkewX( ){
	HX_SOURCE_PUSH("Matrix_obj::getSkewX")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",535)
	return this->_data->__Field(HX_CSTRING("c"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getSkewX,return )

double Matrix_obj::getSkewY( ){
	HX_SOURCE_PUSH("Matrix_obj::getSkewY")
	HX_SOURCE_POS("../../src/cocktail/core/geom/Matrix.hx",543)
	return this->_data->__Field(HX_CSTRING("b"));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,getSkewY,return )


Matrix_obj::Matrix_obj()
{
}

void Matrix_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Matrix);
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_END_CLASS();
}

Dynamic Matrix_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return getData(); }
		if (HX_FIELD_EQ(inName,"skew") ) { return skew_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setData") ) { return setData_dyn(); }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		if (HX_FIELD_EQ(inName,"getFlip") ) { return getFlip_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { return identity_dyn(); }
		if (HX_FIELD_EQ(inName,"getSkewX") ) { return getSkewX_dyn(); }
		if (HX_FIELD_EQ(inName,"getSkewY") ) { return getSkewY_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"translate") ) { return translate_dyn(); }
		if (HX_FIELD_EQ(inName,"setScaleX") ) { return setScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"getScaleX") ) { return getScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"setScaleY") ) { return setScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"getScaleY") ) { return getScaleY_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"concatenate") ) { return concatenate_dyn(); }
		if (HX_FIELD_EQ(inName,"setRotation") ) { return setRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"getRotation") ) { return getRotation_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setTranslationX") ) { return setTranslationX_dyn(); }
		if (HX_FIELD_EQ(inName,"getTranslationX") ) { return getTranslationX_dyn(); }
		if (HX_FIELD_EQ(inName,"setTranslationY") ) { return setTranslationY_dyn(); }
		if (HX_FIELD_EQ(inName,"getTranslationY") ) { return getTranslationY_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Matrix_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return setData(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Matrix_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_data"),
	HX_CSTRING("data"),
	HX_CSTRING("identity"),
	HX_CSTRING("setData"),
	HX_CSTRING("getData"),
	HX_CSTRING("concatenate"),
	HX_CSTRING("translate"),
	HX_CSTRING("rotate"),
	HX_CSTRING("scale"),
	HX_CSTRING("skew"),
	HX_CSTRING("setRotation"),
	HX_CSTRING("getRotation"),
	HX_CSTRING("getFlip"),
	HX_CSTRING("setScaleX"),
	HX_CSTRING("getScaleX"),
	HX_CSTRING("setScaleY"),
	HX_CSTRING("getScaleY"),
	HX_CSTRING("setTranslationX"),
	HX_CSTRING("getTranslationX"),
	HX_CSTRING("setTranslationY"),
	HX_CSTRING("getTranslationY"),
	HX_CSTRING("getSkewX"),
	HX_CSTRING("getSkewY"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Matrix_obj::__mClass;

void Matrix_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.Matrix"), hx::TCanCast< Matrix_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Matrix_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
