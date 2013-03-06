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

Void Matrix_obj::__construct(hx::Null< Float >  __o_a,hx::Null< Float >  __o_b,hx::Null< Float >  __o_c,hx::Null< Float >  __o_d,hx::Null< Float >  __o_e,hx::Null< Float >  __o_f)
{
HX_STACK_PUSH("Matrix::new","cocktail/core/geom/Matrix.hx",56);
Float a = __o_a.Default(1.0);
Float b = __o_b.Default(0.0);
Float c = __o_c.Default(0.0);
Float d = __o_d.Default(1.0);
Float e = __o_e.Default(0.0);
Float f = __o_f.Default(0.0);
{
	HX_STACK_LINE(57)
	this->a = a;
	HX_STACK_LINE(58)
	this->b = b;
	HX_STACK_LINE(59)
	this->c = c;
	HX_STACK_LINE(60)
	this->d = d;
	HX_STACK_LINE(61)
	this->e = e;
	HX_STACK_LINE(62)
	this->f = f;
}
;
	return null();
}

Matrix_obj::~Matrix_obj() { }

Dynamic Matrix_obj::__CreateEmpty() { return  new Matrix_obj; }
hx::ObjectPtr< Matrix_obj > Matrix_obj::__new(hx::Null< Float >  __o_a,hx::Null< Float >  __o_b,hx::Null< Float >  __o_c,hx::Null< Float >  __o_d,hx::Null< Float >  __o_e,hx::Null< Float >  __o_f)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(__o_a,__o_b,__o_c,__o_d,__o_e,__o_f);
	return result;}

Dynamic Matrix_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Matrix_obj::skew( Float skewX,Float skewY){
{
		HX_STACK_PUSH("Matrix::skew","cocktail/core/geom/Matrix.hx",198);
		HX_STACK_THIS(this);
		HX_STACK_ARG(skewX,"skewX");
		HX_STACK_ARG(skewY,"skewY");
		HX_STACK_LINE(198)
		this->concatenate(::cocktail::core::geom::Matrix_obj::getConcatenationMatrix(1.0,::Math_obj::tan(skewY),::Math_obj::tan(skewY),1.0,0.0,0.0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,skew,(void))

Void Matrix_obj::scale( Float scaleX,Float scaleY){
{
		HX_STACK_PUSH("Matrix::scale","cocktail/core/geom/Matrix.hx",182);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scaleX,"scaleX");
		HX_STACK_ARG(scaleY,"scaleY");
		HX_STACK_LINE(182)
		this->concatenate(::cocktail::core::geom::Matrix_obj::getConcatenationMatrix(scaleX,0.0,0.0,scaleY,0.0,0.0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,scale,(void))

Void Matrix_obj::rotate( Float angle){
{
		HX_STACK_PUSH("Matrix::rotate","cocktail/core/geom/Matrix.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_ARG(angle,"angle");
		HX_STACK_LINE(139)
		Float a = 0.0;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(140)
		Float b = 0.0;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(141)
		Float c = 0.0;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(142)
		Float d = 0.0;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(146)
		if (((angle == (Float(::Math_obj::PI) / Float((int)2))))){
			HX_STACK_LINE(148)
			a = d = 0.0;
			HX_STACK_LINE(149)
			c = b = 1.0;
		}
		else{
			HX_STACK_LINE(152)
			if (((angle == ::Math_obj::PI))){
				HX_STACK_LINE(154)
				a = d = -1.0;
				HX_STACK_LINE(155)
				c = b = 0.0;
			}
			else{
				HX_STACK_LINE(157)
				if (((angle == (Float((::Math_obj::PI * (int)3)) / Float((int)2))))){
					HX_STACK_LINE(159)
					a = d = 0.0;
					HX_STACK_LINE(160)
					c = b = -1.0;
				}
				else{
					HX_STACK_LINE(164)
					a = d = ::Math_obj::cos(angle);
					HX_STACK_LINE(165)
					c = b = ::Math_obj::sin(angle);
				}
			}
		}
		HX_STACK_LINE(172)
		this->concatenate(::cocktail::core::geom::Matrix_obj::getConcatenationMatrix(a,b,(c * -1.0),d,0.0,0.0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,rotate,(void))

Void Matrix_obj::translate( Float x,Float y){
{
		HX_STACK_PUSH("Matrix::translate","cocktail/core/geom/Matrix.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_LINE(124)
		this->concatenate(::cocktail::core::geom::Matrix_obj::getConcatenationMatrix(1.0,0.0,0.0,1.0,x,y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,translate,(void))

bool Matrix_obj::isIdentity( ){
	HX_STACK_PUSH("Matrix::isIdentity","cocktail/core/geom/Matrix.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(109)
	return (bool((bool((bool((bool((bool((this->a == 1.0)) && bool((this->b == 0.0)))) && bool((this->c == 0.0)))) && bool((this->d == 1.0)))) && bool((this->e == 0.0)))) && bool((this->f == 0.0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,isIdentity,return )

Void Matrix_obj::concatenate( ::cocktail::core::geom::Matrix matrix){
{
		HX_STACK_PUSH("Matrix::concatenate","cocktail/core/geom/Matrix.hx",94);
		HX_STACK_THIS(this);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_LINE(96)
		this->a = ((this->a * matrix->a) + (this->c * matrix->b));
		HX_STACK_LINE(97)
		this->b = ((this->b * matrix->a) + (this->d * matrix->b));
		HX_STACK_LINE(98)
		this->c = ((this->a * matrix->c) + (this->c * matrix->d));
		HX_STACK_LINE(99)
		this->d = ((this->b * matrix->c) + (this->d * matrix->d));
		HX_STACK_LINE(100)
		this->e = (((this->a * matrix->e) + (this->c * matrix->f)) + this->e);
		HX_STACK_LINE(101)
		this->f = (((this->b * matrix->e) + (this->d * matrix->f)) + this->f);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,concatenate,(void))

Void Matrix_obj::identity( ){
{
		HX_STACK_PUSH("Matrix::identity","cocktail/core/geom/Matrix.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_LINE(74)
		this->a = 1.0;
		HX_STACK_LINE(75)
		this->b = 0.0;
		HX_STACK_LINE(76)
		this->c = 0.0;
		HX_STACK_LINE(77)
		this->d = 1.0;
		HX_STACK_LINE(78)
		this->e = 0.0;
		HX_STACK_LINE(79)
		this->f = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,identity,(void))

::cocktail::core::geom::Matrix Matrix_obj::_concatenationMatrix;

::cocktail::core::geom::Matrix Matrix_obj::getConcatenationMatrix( Float a,Float b,Float c,Float d,Float e,Float f){
	HX_STACK_PUSH("Matrix::getConcatenationMatrix","cocktail/core/geom/Matrix.hx",218);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	HX_STACK_ARG(e,"e");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(219)
	if (((::cocktail::core::geom::Matrix_obj::_concatenationMatrix == null()))){
		HX_STACK_LINE(220)
		::cocktail::core::geom::Matrix_obj::_concatenationMatrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	}
	HX_STACK_LINE(224)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->a = a;
	HX_STACK_LINE(225)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->b = b;
	HX_STACK_LINE(226)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->c = c;
	HX_STACK_LINE(227)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->d = d;
	HX_STACK_LINE(228)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->e = e;
	HX_STACK_LINE(229)
	::cocktail::core::geom::Matrix_obj::_concatenationMatrix->f = f;
	HX_STACK_LINE(231)
	return ::cocktail::core::geom::Matrix_obj::_concatenationMatrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Matrix_obj,getConcatenationMatrix,return )


Matrix_obj::Matrix_obj()
{
}

void Matrix_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Matrix);
	HX_MARK_MEMBER_NAME(f,"f");
	HX_MARK_MEMBER_NAME(d,"d");
	HX_MARK_MEMBER_NAME(e,"e");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

void Matrix_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(f,"f");
	HX_VISIT_MEMBER_NAME(d,"d");
	HX_VISIT_MEMBER_NAME(e,"e");
	HX_VISIT_MEMBER_NAME(c,"c");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
}

Dynamic Matrix_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"f") ) { return f; }
		if (HX_FIELD_EQ(inName,"d") ) { return d; }
		if (HX_FIELD_EQ(inName,"e") ) { return e; }
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"skew") ) { return skew_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { return identity_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"translate") ) { return translate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isIdentity") ) { return isIdentity_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"concatenate") ) { return concatenate_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_concatenationMatrix") ) { return _concatenationMatrix; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getConcatenationMatrix") ) { return getConcatenationMatrix_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Matrix_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"f") ) { f=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d") ) { d=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e") ) { e=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_concatenationMatrix") ) { _concatenationMatrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Matrix_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("f"));
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("e"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_concatenationMatrix"),
	HX_CSTRING("getConcatenationMatrix"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("skew"),
	HX_CSTRING("scale"),
	HX_CSTRING("rotate"),
	HX_CSTRING("translate"),
	HX_CSTRING("isIdentity"),
	HX_CSTRING("concatenate"),
	HX_CSTRING("identity"),
	HX_CSTRING("f"),
	HX_CSTRING("d"),
	HX_CSTRING("e"),
	HX_CSTRING("c"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Matrix_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Matrix_obj::_concatenationMatrix,"_concatenationMatrix");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Matrix_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Matrix_obj::_concatenationMatrix,"_concatenationMatrix");
};

Class Matrix_obj::__mClass;

void Matrix_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.Matrix"), hx::TCanCast< Matrix_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Matrix_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
