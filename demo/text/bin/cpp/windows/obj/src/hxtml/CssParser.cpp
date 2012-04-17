#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_hxtml_CssParser
#include <hxtml/CssParser.h>
#endif
#ifndef INCLUDED_hxtml_IStyleProxy
#include <hxtml/IStyleProxy.h>
#endif
#ifndef INCLUDED_hxtml_Token
#include <hxtml/Token.h>
#endif
#ifndef INCLUDED_hxtml_Value
#include <hxtml/Value.h>
#endif
namespace hxtml{

Void CssParser_obj::__construct()
{
{
}
;
	return null();
}

CssParser_obj::~CssParser_obj() { }

Dynamic CssParser_obj::__CreateEmpty() { return  new CssParser_obj; }
hx::ObjectPtr< CssParser_obj > CssParser_obj::__new()
{  hx::ObjectPtr< CssParser_obj > result = new CssParser_obj();
	result->__construct();
	return result;}

Dynamic CssParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CssParser_obj > result = new CssParser_obj();
	result->__construct();
	return result;}

Void CssParser_obj::notImplemented( Dynamic pos){
{
		HX_SOURCE_PUSH("CssParser_obj::notImplemented")
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",62)
		::haxe::Log_obj::trace(HX_CSTRING("Not implemented"),pos);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,notImplemented,(void))

bool CssParser_obj::applyStyle( ::String r,::hxtml::Value v,::hxtml::IStyleProxy s){
	HX_SOURCE_PUSH("CssParser_obj::applyStyle")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",71)
	::String _switch_1 = (r);
	if (  ( _switch_1==HX_CSTRING("margin"))){
		struct _Function_2_1{
			inline static Array< ::hxtml::Value > Block( ::hxtml::Value &v){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",74)
				{
::hxtml::Value _switch_2 = (v);
					switch((_switch_2)->GetIndex()){
						case 8: {
							Array< ::hxtml::Value > l = _switch_2->__Param(0);
{
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",75)
								return l;
							}
						}
						;break;
						default: {
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",76)
							return Array_obj< ::hxtml::Value >::__new().Add(v);
						}
					}
				}
			}
		};
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",74)
		Array< ::hxtml::Value > vl = _Function_2_1::Block(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",79)
		Dynamic vUnits = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",80)
		{
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",80)
			int _g = (int)0;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",80)
			while(((_g < vl->length))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",80)
				::hxtml::Value i = vl->__get(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",80)
				++(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",81)
				Dynamic vo = this->getValueObject(i);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",82)
				if (((vo != null()))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",83)
					vUnits->__Field(HX_CSTRING("push"))(vo);
				}
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",86)
		switch( (int)(vUnits->__Field(HX_CSTRING("length")))){
			case (int)1: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",88)
				s->setMarginTopNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",89)
				s->setMarginRightNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",90)
				s->setMarginBottomNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",91)
				s->setMarginLeftNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",92)
				return true;
			}
			;break;
			case (int)2: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",94)
				s->setMarginTopNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",95)
				s->setMarginRightNum(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",96)
				s->setMarginBottomNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",97)
				s->setMarginLeftNum(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",98)
				return true;
			}
			;break;
			case (int)3: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",100)
				s->setMarginTopNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",101)
				s->setMarginRightNum(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",102)
				s->setMarginBottomNum(this->d,vUnits->__GetItem((int)2)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)2)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",103)
				s->setMarginLeftNum(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",104)
				return true;
			}
			;break;
			case (int)4: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",106)
				s->setMarginTopNum(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",107)
				s->setMarginRightNum(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",108)
				s->setMarginBottomNum(this->d,vUnits->__GetItem((int)2)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)2)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",109)
				s->setMarginLeftNum(this->d,vUnits->__GetItem((int)3)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)3)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",110)
				return true;
			}
			;break;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("margin-left"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",114)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",115)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",116)
			s->setMarginLeftKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",117)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",120)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",121)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",122)
			s->setMarginLeftNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",123)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("margin-right"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",127)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",128)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",129)
			s->setMarginRightKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",130)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",133)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",134)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",135)
			s->setMarginRightNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",136)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("margin-top"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",140)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",141)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",142)
			s->setMarginTopKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",143)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",146)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",147)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",148)
			s->setMarginTopNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",149)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("margin-bottom"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",153)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",154)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",155)
			s->setMarginBottomKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",156)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",159)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",160)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",161)
			s->setMarginBottomNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",162)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("padding"))){
		struct _Function_2_1{
			inline static Array< ::hxtml::Value > Block( ::hxtml::Value &v){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",166)
				{
::hxtml::Value _switch_3 = (v);
					switch((_switch_3)->GetIndex()){
						case 8: {
							Array< ::hxtml::Value > l = _switch_3->__Param(0);
{
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",167)
								return l;
							}
						}
						;break;
						default: {
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",168)
							return Array_obj< ::hxtml::Value >::__new().Add(v);
						}
					}
				}
			}
		};
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",166)
		Array< ::hxtml::Value > vl = _Function_2_1::Block(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",171)
		Dynamic vUnits = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",172)
		{
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",172)
			int _g = (int)0;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",172)
			while(((_g < vl->length))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",172)
				::hxtml::Value i = vl->__get(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",172)
				++(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",173)
				Dynamic vo = this->getValueObject(i);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",174)
				if (((vo != null()))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",175)
					vUnits->__Field(HX_CSTRING("push"))(vo);
				}
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",178)
		switch( (int)(vUnits->__Field(HX_CSTRING("length")))){
			case (int)1: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",180)
				s->setPaddingTop(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",181)
				s->setPaddingRight(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",182)
				s->setPaddingBottom(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",183)
				s->setPaddingLeft(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",184)
				return true;
			}
			;break;
			case (int)2: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",186)
				s->setPaddingTop(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",187)
				s->setPaddingRight(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",188)
				s->setPaddingBottom(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",189)
				s->setPaddingLeft(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",190)
				return true;
			}
			;break;
			case (int)3: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",192)
				s->setPaddingTop(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",193)
				s->setPaddingRight(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",194)
				s->setPaddingBottom(this->d,vUnits->__GetItem((int)2)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)2)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",195)
				s->setPaddingLeft(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",196)
				return true;
			}
			;break;
			case (int)4: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",198)
				s->setPaddingTop(this->d,vUnits->__GetItem((int)0)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)0)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",199)
				s->setPaddingRight(this->d,vUnits->__GetItem((int)1)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)1)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",200)
				s->setPaddingBottom(this->d,vUnits->__GetItem((int)2)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)2)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",201)
				s->setPaddingLeft(this->d,vUnits->__GetItem((int)3)->__Field(HX_CSTRING("value")),vUnits->__GetItem((int)3)->__Field(HX_CSTRING("unit")));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",202)
				return true;
			}
			;break;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("padding-left"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",205)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",206)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",206)
			s->setPaddingLeft(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",206)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("padding-right"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",208)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",209)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",209)
			s->setPaddingRight(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",209)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("padding-top"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",211)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",212)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",212)
			s->setPaddingTop(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",212)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("padding-bottom"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",214)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",215)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",215)
			s->setPaddingBottom(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",215)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("width"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",217)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",218)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",219)
			s->setWidth(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",220)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("height"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",223)
		Dynamic i = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",224)
		if (((i != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",225)
			s->setHeight(this->d,i->__Field(HX_CSTRING("value")),i->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",226)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("background-color"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",229)
		{
::hxtml::Value _switch_4 = (v);
			switch((_switch_4)->GetIndex()){
				case 6: {
					::String v1 = _switch_4->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",232)
						Dynamic val = (  (((v1.length == (int)6))) ? Dynamic(::Std_obj::parseInt((HX_CSTRING("0x") + v1))) : Dynamic((  (((v1.length == (int)3))) ? Dynamic(::Std_obj::parseInt(((((((HX_CSTRING("0x") + v1.charAt((int)0)) + v1.charAt((int)0)) + v1.charAt((int)1)) + v1.charAt((int)1)) + v1.charAt((int)2)) + v1.charAt((int)2)))) : Dynamic(null()) )) );
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",233)
						s->setBgColorNum(this->d,val);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",234)
						return true;
					}
				}
				;break;
				case 3: {
					::String v1 = _switch_4->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",236)
						s->setBgColorRGBA(this->d,v1);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",237)
						return true;
					}
				}
				;break;
				case 0: {
					::String i = _switch_4->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",239)
						s->setBgColorKey(this->d,i);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",240)
						return true;
					}
				}
				;break;
				default: {
				}
			}
		}
	}
	else if (  ( _switch_1==HX_CSTRING("background-repeat"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",245)
		s->setBgRepeat(this->d,Array_obj< ::String >::__new().Add(this->getIdent(v)));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",246)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("background-image"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",247)
		{
::hxtml::Value _switch_5 = (v);
			switch((_switch_5)->GetIndex()){
				case 9: {
					::String url = _switch_5->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",250)
						s->setBgImage(this->d,Array_obj< ::String >::__new().Add(url));
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",251)
						return true;
					}
				}
				;break;
				case 0: {
					::String i = _switch_5->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",253)
						s->setBgImage(this->d,Array_obj< ::String >::__new().Add(i));
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",254)
						return true;
					}
				}
				;break;
				default: {
				}
			}
		}
	}
	else if (  ( _switch_1==HX_CSTRING("background-attachment"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",258)
		s->setBgAttachment(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",259)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("background-position"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",262)
		s->setBgPosXNum(this->d,(int)50,HX_CSTRING("%"));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",263)
		s->setBgPosYNum(this->d,(int)50,HX_CSTRING("%"));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",265)
		return this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("-inner-bgpos-left")).Add(HX_CSTRING("-inner-bgpos-top")),v,s);
	}
	else if (  ( _switch_1==HX_CSTRING("-inner-bgpos-top"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",268)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",269)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",270)
			s->setBgPosYNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",271)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",274)
		s->setBgPosYKey(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",275)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("-inner-bgpos-left"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",278)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",279)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",280)
			s->setBgPosXNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",281)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",284)
		s->setBgPosXKey(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",285)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("background"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",286)
		return this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("background-color")).Add(HX_CSTRING("background-image")).Add(HX_CSTRING("background-repeat")).Add(HX_CSTRING("background-attachment")).Add(HX_CSTRING("background-position")),v,s);
	}
	else if (  ( _switch_1==HX_CSTRING("font-family"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",290)
		Array< ::String > l = this->getList(v,this->getFontName_dyn());
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",291)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",292)
			s->setFontFamily(this->d,l);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",293)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("font-style"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",296)
		s->setFontStyle(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",297)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("font-variant"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",299)
		s->setFontVariant(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",300)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("font-weight"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",303)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",304)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",305)
			s->setFontWeightKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",306)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",309)
		{
::hxtml::Value _switch_6 = (v);
			switch((_switch_6)->GetIndex()){
				case 5: {
					int i = _switch_6->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",311)
						s->setFontWeightNum(this->d,i);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",312)
						return true;
					}
				}
				;break;
				default: {
				}
			}
		}
	}
	else if (  ( _switch_1==HX_CSTRING("font-size"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",317)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",318)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",319)
			s->setFontSizeKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",320)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",323)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",324)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",325)
			s->setFontSizeNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",326)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("font"))){
		struct _Function_2_1{
			inline static Array< ::hxtml::Value > Block( ::hxtml::Value &v){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",329)
				{
::hxtml::Value _switch_7 = (v);
					switch((_switch_7)->GetIndex()){
						case 8: {
							Array< ::hxtml::Value > l = _switch_7->__Param(0);
{
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",330)
								return l;
							}
						}
						;break;
						default: {
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",331)
							return Array_obj< ::hxtml::Value >::__new().Add(v);
						}
					}
				}
			}
		};
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",329)
		Array< ::hxtml::Value > vl = _Function_2_1::Block(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",333)
		::hxtml::Value v1 = ::hxtml::Value_obj::VGroup(vl);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",334)
		this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("font-style")).Add(HX_CSTRING("font-variant")).Add(HX_CSTRING("font-weight")),v1,s);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",335)
		this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("font-size")),v1,s);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",336)
		if (((vl->length > (int)0))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",337)
			{
::hxtml::Value _switch_8 = (vl->__get((int)0));
				switch((_switch_8)->GetIndex()){
					case 11: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",338)
						vl->shift();
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",341)
		this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("line-height")),v1,s);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",342)
		this->applyComposite(Array_obj< ::String >::__new().Add(HX_CSTRING("font-family")),v1,s);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",343)
		if (((vl->length == (int)0))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",344)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("color"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",345)
		{
::hxtml::Value _switch_9 = (v);
			switch((_switch_9)->GetIndex()){
				case 6: {
					::String v1 = _switch_9->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",348)
						Dynamic val = (  (((v1.length == (int)6))) ? Dynamic(::Std_obj::parseInt((HX_CSTRING("0x") + v1))) : Dynamic((  (((v1.length == (int)3))) ? Dynamic(::Std_obj::parseInt(((((((HX_CSTRING("0x") + v1.charAt((int)0)) + v1.charAt((int)0)) + v1.charAt((int)1)) + v1.charAt((int)1)) + v1.charAt((int)2)) + v1.charAt((int)2)))) : Dynamic(null()) )) );
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",349)
						s->setTextColorNum(this->d,val);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",350)
						return true;
					}
				}
				;break;
				case 0: {
					::String i = _switch_9->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",352)
						s->setTextColorKey(this->d,i);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",353)
						return true;
					}
				}
				;break;
				default: {
				}
			}
		}
	}
	else if (  ( _switch_1==HX_CSTRING("text-decoration"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",357)
		Array< ::String > idents = this->getGroup(v,this->getIdent_dyn());
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",358)
		{
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",358)
			int _g = (int)0;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",358)
			while(((_g < idents->length))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",358)
				::String i = idents->__get(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",358)
				++(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",359)
				s->setTextDecoration(this->d,i);
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",360)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("text-transform"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",362)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",363)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",364)
			s->setTextTransform(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",365)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("line-height"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",369)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",370)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",371)
			s->setLineHeightKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",372)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",375)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",376)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",377)
			s->setLineHeightNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",378)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("word-spacing"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",383)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",384)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",385)
			s->setWordSpacingKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",386)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",389)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",390)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",391)
			s->setWordSpacingNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",392)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("letter-spacing"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",397)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",398)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",399)
			s->setLetterSpacingKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",400)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",403)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",404)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",405)
			s->setLetterSpacingNum(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",406)
			return true;
		}
	}
	else if (  ( _switch_1==HX_CSTRING("top"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",411)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",412)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",413)
			s->setTopKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",414)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",417)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",418)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",419)
			s->setTop(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",420)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",422)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("left"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",425)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",426)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",427)
			s->setLeftKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",428)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",431)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",432)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",433)
			s->setLeft(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",434)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",436)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("right"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",439)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",440)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",441)
			s->setRightKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",442)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",445)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",446)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",447)
			s->setRight(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",448)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",450)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("bottom"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",453)
		::String val = this->getIdent(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",454)
		if (((val != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",455)
			s->setBottomKey(this->d,val);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",456)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",459)
		Dynamic l = this->getValueObject(v);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",460)
		if (((l != null()))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",461)
			s->setBottom(this->d,l->__Field(HX_CSTRING("value")),l->__Field(HX_CSTRING("unit")));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",462)
			return true;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",464)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("display"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",467)
		s->setDisplay(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",468)
		return true;
	}
	else if (  ( _switch_1==HX_CSTRING("position"))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",470)
		s->setPosition(this->d,this->getIdent(v));
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",471)
		return true;
	}
	else  {
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",473)
		hx::Throw ((((HX_CSTRING("Not implemented '") + r) + HX_CSTRING("' = ")) + ::Std_obj::string(v)));
	}
;
;
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",476)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(CssParser_obj,applyStyle,return )

bool CssParser_obj::applyComposite( Array< ::String > names,::hxtml::Value v,::hxtml::IStyleProxy s){
	HX_SOURCE_PUSH("CssParser_obj::applyComposite")
	struct _Function_1_1{
		inline static Array< ::hxtml::Value > Block( ::hxtml::Value &v){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",480)
			{
::hxtml::Value _switch_10 = (v);
				switch((_switch_10)->GetIndex()){
					case 8: {
						Array< ::hxtml::Value > l = _switch_10->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",481)
							return l;
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",482)
						return Array_obj< ::hxtml::Value >::__new().Add(v);
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",480)
	Array< ::hxtml::Value > vl = _Function_1_1::Block(v);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",484)
	while(((vl->length > (int)0))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",485)
		bool found = false;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",486)
		{
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",486)
			int _g = (int)0;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",486)
			while(((_g < names->length))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",486)
				::String n = names->__get(_g);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",486)
				++(_g);
				struct _Function_4_1{
					inline static int Block( ::String &n){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",487)
						::String _switch_11 = (n);
						if (  ( _switch_11==HX_CSTRING("background-position"))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",488)
							return (int)2;
						}
						else  {
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",489)
							return (int)1;
						}
;
;
					}
				};
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",487)
				int count = _Function_4_1::Block(n);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",491)
				if (((count > vl->length))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",491)
					count = vl->length;
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",492)
				while(((count > (int)0))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",493)
					::hxtml::Value v1 = (  (((count == (int)1))) ? ::hxtml::Value(vl->__get((int)0)) : ::hxtml::Value(::hxtml::Value_obj::VGroup(vl->slice((int)0,count))) );
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",494)
					if ((this->applyStyle(n,v1,s))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",495)
						found = true;
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",496)
						names->remove(n);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",497)
						{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",497)
							int _g1 = (int)0;
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",497)
							while(((_g1 < count))){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",497)
								int i = (_g1)++;
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",498)
								vl->shift();
							}
						}
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",499)
						break;
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",501)
					(count)--;
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",503)
				if ((found)){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",503)
					break;
				}
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",505)
		if ((!(found))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",506)
			return false;
		}
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",508)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(CssParser_obj,applyComposite,return )

Dynamic CssParser_obj::getValueObject( ::hxtml::Value i){
	HX_SOURCE_PUSH("CssParser_obj::getValueObject")
	struct _Function_1_1{
		inline static Dynamic Block( ::hxtml::Value &i){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",512)
			{
::hxtml::Value _switch_12 = (i);
				switch((_switch_12)->GetIndex()){
					case 2: {
						::String u = _switch_12->__Param(1);
						double v = _switch_12->__Param(0);
{
							struct _Function_3_1{
								inline static Dynamic Block( double &v,::String &u){
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_CSTRING("value") , v,false);
									__result->Add(HX_CSTRING("unit") , u,false);
									return __result;
								}
							};
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",513)
							return _Function_3_1::Block(v,u);
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",514)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",511)
	return _Function_1_1::Block(i);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,getValueObject,return )

Dynamic CssParser_obj::getGroup( ::hxtml::Value v,Dynamic f){
	HX_SOURCE_PUSH("CssParser_obj::getGroup")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",517)
	{
::hxtml::Value _switch_13 = (v);
		switch((_switch_13)->GetIndex()){
			case 8: {
				Array< ::hxtml::Value > l = _switch_13->__Param(0);
{
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",520)
					Dynamic a = Dynamic( Array_obj<Dynamic>::__new());
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",521)
					{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",521)
						int _g = (int)0;
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",521)
						while(((_g < l->length))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",521)
							::hxtml::Value v1 = l->__get(_g);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",521)
							++(_g);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",522)
							Dynamic v2 = f(v1);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",523)
							if (((v2 == null()))){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",523)
								return null();
							}
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",524)
							a->__Field(HX_CSTRING("push"))(v2);
						}
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",526)
					return a;
				}
			}
			;break;
			default: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",528)
				Dynamic v1 = f(v);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",529)
				return (  (((v1 == null()))) ? Dynamic(null()) : Dynamic(Dynamic( Array_obj<Dynamic>::__new().Add(v1))) );
			}
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC2(CssParser_obj,getGroup,return )

Dynamic CssParser_obj::getList( ::hxtml::Value v,Dynamic f){
	HX_SOURCE_PUSH("CssParser_obj::getList")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",533)
	{
::hxtml::Value _switch_14 = (v);
		switch((_switch_14)->GetIndex()){
			case 7: {
				Array< ::hxtml::Value > l = _switch_14->__Param(0);
{
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",536)
					Dynamic a = Dynamic( Array_obj<Dynamic>::__new());
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",537)
					{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",537)
						int _g = (int)0;
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",537)
						while(((_g < l->length))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",537)
							::hxtml::Value v1 = l->__get(_g);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",537)
							++(_g);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",538)
							Dynamic v2 = f(v1);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",539)
							if (((v2 == null()))){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",539)
								return null();
							}
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",540)
							a->__Field(HX_CSTRING("push"))(v2);
						}
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",542)
					return a;
				}
			}
			;break;
			default: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",544)
				Dynamic v1 = f(v);
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",545)
				return (  (((v1 == null()))) ? Dynamic(null()) : Dynamic(Dynamic( Array_obj<Dynamic>::__new().Add(v1))) );
			}
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC2(CssParser_obj,getList,return )

Dynamic CssParser_obj::getPix( ::hxtml::Value v){
	HX_SOURCE_PUSH("CssParser_obj::getPix")
	struct _Function_1_1{
		inline static Dynamic Block( ::hxtml::Value &v){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",550)
			{
::hxtml::Value _switch_15 = (v);
				switch((_switch_15)->GetIndex()){
					case 2: {
						::String u = _switch_15->__Param(1);
						double f = _switch_15->__Param(0);
{
							struct _Function_3_1{
								inline static Dynamic Block( ::String &u,double &f){
									HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",551)
									::String _switch_16 = (u);
									if (  ( _switch_16==HX_CSTRING("px"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",553)
										return ::Std_obj::_int(f);
									}
									else if (  ( _switch_16==HX_CSTRING("pt"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",554)
										return ::Std_obj::_int((double((f * (int)4)) / double((int)3)));
									}
									else  {
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",555)
										return null();
									}
;
;
								}
							};
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",551)
							return _Function_3_1::Block(u,f);
						}
					}
					;break;
					case 5: {
						int v1 = _switch_15->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",557)
							return v1;
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",559)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",549)
	return _Function_1_1::Block(v);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,getPix,return )

::String CssParser_obj::getIdent( ::hxtml::Value v){
	HX_SOURCE_PUSH("CssParser_obj::getIdent")
	struct _Function_1_1{
		inline static ::String Block( ::hxtml::Value &v){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",582)
			{
::hxtml::Value _switch_17 = (v);
				switch((_switch_17)->GetIndex()){
					case 0: {
						::String v1 = _switch_17->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",583)
							return v1;
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",584)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",581)
	return _Function_1_1::Block(v);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,getIdent,return )

Dynamic CssParser_obj::getCol( ::hxtml::Value v){
	HX_SOURCE_PUSH("CssParser_obj::getCol")
	struct _Function_1_1{
		inline static Dynamic Block( ::hxtml::Value &v){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",589)
			{
::hxtml::Value _switch_18 = (v);
				switch((_switch_18)->GetIndex()){
					case 6: {
						::String v1 = _switch_18->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",590)
							return (  (((v1.length == (int)6))) ? Dynamic(::Std_obj::parseInt((HX_CSTRING("0x") + v1))) : Dynamic((  (((v1.length == (int)3))) ? Dynamic(::Std_obj::parseInt(((((((HX_CSTRING("0x") + v1.charAt((int)0)) + v1.charAt((int)0)) + v1.charAt((int)1)) + v1.charAt((int)1)) + v1.charAt((int)2)) + v1.charAt((int)2)))) : Dynamic(null()) )) );
						}
					}
					;break;
					case 0: {
						::String i = _switch_18->__Param(0);
{
							struct _Function_3_1{
								inline static Dynamic Block( ::String &i){
									HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",592)
									::String _switch_19 = (i);
									if (  ( _switch_19==HX_CSTRING("black"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",594)
										return (int)0;
									}
									else if (  ( _switch_19==HX_CSTRING("red"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",595)
										return (int)16711680;
									}
									else if (  ( _switch_19==HX_CSTRING("lime"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",596)
										return (int)65280;
									}
									else if (  ( _switch_19==HX_CSTRING("blue"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",597)
										return (int)255;
									}
									else if (  ( _switch_19==HX_CSTRING("white"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",598)
										return (int)16777215;
									}
									else if (  ( _switch_19==HX_CSTRING("aqua"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",599)
										return (int)65535;
									}
									else if (  ( _switch_19==HX_CSTRING("fuchsia"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",600)
										return (int)16711935;
									}
									else if (  ( _switch_19==HX_CSTRING("yellow"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",601)
										return (int)16776960;
									}
									else if (  ( _switch_19==HX_CSTRING("maroon"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",602)
										return (int)8388608;
									}
									else if (  ( _switch_19==HX_CSTRING("green"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",603)
										return (int)32768;
									}
									else if (  ( _switch_19==HX_CSTRING("navy"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",604)
										return (int)128;
									}
									else if (  ( _switch_19==HX_CSTRING("olive"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",605)
										return (int)8421376;
									}
									else if (  ( _switch_19==HX_CSTRING("purple"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",606)
										return (int)8388736;
									}
									else if (  ( _switch_19==HX_CSTRING("teal"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",607)
										return (int)32896;
									}
									else if (  ( _switch_19==HX_CSTRING("silver"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",608)
										return (int)12632256;
									}
									else if (  ( _switch_19==HX_CSTRING("gray")) ||  ( _switch_19==HX_CSTRING("grey"))){
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",609)
										return (int)8421504;
									}
									else  {
										HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",610)
										return null();
									}
;
;
								}
							};
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",592)
							return _Function_3_1::Block(i);
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",612)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",588)
	return _Function_1_1::Block(v);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,getCol,return )

::String CssParser_obj::getFontName( ::hxtml::Value v){
	HX_SOURCE_PUSH("CssParser_obj::getFontName")
	struct _Function_1_1{
		inline static ::String Block( ::hxtml::Value &v,::hxtml::CssParser_obj *__this){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",618)
			{
::hxtml::Value _switch_20 = (v);
				switch((_switch_20)->GetIndex()){
					case 1: {
						::String s = _switch_20->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",619)
							return s;
						}
					}
					;break;
					case 8: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",621)
						Array< ::String > g = __this->getGroup(v,__this->getIdent_dyn());
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",622)
						return (  (((g == null()))) ? ::String(null()) : ::String(g->join(HX_CSTRING(" "))) );
					}
					;break;
					case 0: {
						::String i = _switch_20->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",623)
							return i;
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",624)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",617)
	return _Function_1_1::Block(v,this);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,getFontName,return )

Dynamic CssParser_obj::unexpected( ::hxtml::Token t){
	HX_SOURCE_PUSH("CssParser_obj::unexpected")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",631)
	hx::Throw ((HX_CSTRING("Unexpected ") + ::Std_obj::string(t)));
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",632)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,unexpected,return )

Void CssParser_obj::expect( ::hxtml::Token t){
{
		HX_SOURCE_PUSH("CssParser_obj::expect")
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",636)
		::hxtml::Token tk = this->readToken();
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",637)
		if (((tk != t))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",637)
			this->unexpected(tk);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,expect,(void))

Void CssParser_obj::push( ::hxtml::Token t){
{
		HX_SOURCE_PUSH("CssParser_obj::push")
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",640)
		this->tokens->push(t);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,push,(void))

bool CssParser_obj::isToken( ::hxtml::Token t){
	HX_SOURCE_PUSH("CssParser_obj::isToken")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",645)
	::hxtml::Token tk = this->readToken();
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",646)
	if (((tk == t))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",646)
		return true;
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",647)
	this->tokens->push(tk);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",648)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,isToken,return )

Void CssParser_obj::parse( ::String css,Dynamic d,::hxtml::IStyleProxy s){
{
		HX_SOURCE_PUSH("CssParser_obj::parse")
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",652)
		this->css = css;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",653)
		this->s = s;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",654)
		this->d = d;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",655)
		this->pos = (int)0;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",656)
		this->tokens = Array_obj< ::hxtml::Token >::__new();
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",657)
		this->parseStyle(::hxtml::Token_obj::TEof_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CssParser_obj,parse,(void))

Void CssParser_obj::parseStyle( ::hxtml::Token eof){
{
		HX_SOURCE_PUSH("CssParser_obj::parseStyle")
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",660)
		while((true)){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",662)
			if ((this->isToken(eof))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",663)
				break;
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",664)
			::String r = this->readIdent();
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",665)
			this->expect(::hxtml::Token_obj::TDblDot_dyn());
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",666)
			::hxtml::Value v = this->readValue(null());
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",667)
			::hxtml::IStyleProxy s = this->s;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",668)
			{
::hxtml::Value _switch_21 = (v);
				switch((_switch_21)->GetIndex()){
					case 10: {
						::hxtml::Value val = _switch_21->__Param(1);
						::String label = _switch_21->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",669)
							if (((label == HX_CSTRING("important")))){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",670)
								v = val;
							}
						}
					}
					;break;
					default: {
					}
				}
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",678)
			if ((!(this->applyStyle(r,v,s)))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",679)
				hx::Throw ((((HX_CSTRING("Invalid value ") + ::Std_obj::string(v)) + HX_CSTRING(" for css ")) + r));
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",680)
			if ((this->isToken(eof))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",681)
				break;
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",682)
			this->expect(::hxtml::Token_obj::TSemicolon_dyn());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,parseStyle,(void))

::String CssParser_obj::readIdent( ){
	HX_SOURCE_PUSH("CssParser_obj::readIdent")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",768)
	::hxtml::Token t = this->readToken();
	struct _Function_1_1{
		inline static ::String Block( ::hxtml::Token &t,::hxtml::CssParser_obj *__this){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",769)
			{
::hxtml::Token _switch_22 = (t);
				switch((_switch_22)->GetIndex()){
					case 0: {
						::String i = _switch_22->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",770)
							return i;
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",771)
						return __this->unexpected(t);
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",769)
	return _Function_1_1::Block(t,this);
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,readIdent,return )

::hxtml::Value CssParser_obj::readValue( Dynamic opt){
	HX_SOURCE_PUSH("CssParser_obj::readValue")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",776)
	::hxtml::Token t = this->readToken();
	struct _Function_1_1{
		inline static ::hxtml::Value Block( ::hxtml::Token &t,::hxtml::CssParser_obj *__this,Dynamic &opt){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",777)
			{
::hxtml::Token _switch_23 = (t);
				switch((_switch_23)->GetIndex()){
					case 5: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",778)
						return ::hxtml::Value_obj::VHex(__this->readHex());
					}
					;break;
					case 0: {
						::String i = _switch_23->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",780)
							return ::hxtml::Value_obj::VIdent(i);
						}
					}
					;break;
					case 1: {
						::String s = _switch_23->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",782)
							return ::hxtml::Value_obj::VString(s);
						}
					}
					;break;
					case 2: {
						int i = _switch_23->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",784)
							return __this->readValueUnit(i,i);
						}
					}
					;break;
					case 3: {
						double f = _switch_23->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",786)
							return __this->readValueUnit(f,null());
						}
					}
					;break;
					case 17: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",788)
						return ::hxtml::Value_obj::VSlash_dyn();
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",791)
						if ((!(opt))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",791)
							__this->unexpected(t);
						}
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",792)
						__this->tokens->push(t);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",793)
						return null();
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",777)
	::hxtml::Value v = _Function_1_1::Block(t,this,opt);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",795)
	if (((v != null()))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",795)
		v = this->readValueNext(v);
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",796)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,readValue,return )

::String CssParser_obj::readHex( ){
	HX_SOURCE_PUSH("CssParser_obj::readHex")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",800)
	int start = this->pos;
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",801)
	while((true)){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",802)
		int c = this->css.cca((this->pos)++);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",803)
		if (((bool((bool((bool((c >= (int)65)) && bool((c <= (int)70)))) || bool((bool((c >= (int)97)) && bool((c <= (int)102)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57))))))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",804)
			continue;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",805)
		(this->pos)--;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",806)
		break;
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",808)
	return this->css.substr(start,(this->pos - start));
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,readHex,return )

::hxtml::Value CssParser_obj::readValueUnit( double f,Dynamic i){
	HX_SOURCE_PUSH("CssParser_obj::readValueUnit")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",812)
	::hxtml::Token t = this->readToken();
	struct _Function_1_1{
		inline static ::hxtml::Value Block( ::hxtml::Token &t,::hxtml::CssParser_obj *__this,double &f,Dynamic &i){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",813)
			{
::hxtml::Token _switch_24 = (t);
				switch((_switch_24)->GetIndex()){
					case 0: {
						::String i1 = _switch_24->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",814)
							return ::hxtml::Value_obj::VUnit(f,i1);
						}
					}
					;break;
					case 11: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",816)
						return ::hxtml::Value_obj::VUnit(f,HX_CSTRING("%"));
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",819)
						__this->tokens->push(t);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",820)
						return (  (((i != null()))) ? ::hxtml::Value(::hxtml::Value_obj::VInt(i)) : ::hxtml::Value(::hxtml::Value_obj::VFloat(f)) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",813)
	return _Function_1_1::Block(t,this,f,i);
}


HX_DEFINE_DYNAMIC_FUNC2(CssParser_obj,readValueUnit,return )

::hxtml::Value CssParser_obj::readValueNext( ::hxtml::Value v){
	HX_SOURCE_PUSH("CssParser_obj::readValueNext")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",828)
	::hxtml::Token t = this->readToken();
	struct _Function_1_1{
		inline static ::hxtml::Value Block( ::hxtml::Token &t,::hxtml::CssParser_obj *__this,::hxtml::Value &v){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",829)
			{
::hxtml::Token _switch_25 = (t);
				switch((_switch_25)->GetIndex()){
					case 6: {
						struct _Function_3_1{
							inline static ::hxtml::Value Block( ::hxtml::CssParser_obj *__this,::hxtml::Token &t,::hxtml::Value &v){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",830)
								{
::hxtml::Value _switch_26 = (v);
									switch((_switch_26)->GetIndex()){
										case 0: {
											::String i = _switch_26->__Param(0);
{
												struct _Function_5_1{
													inline static ::hxtml::Value Block( ::hxtml::CssParser_obj *__this,::hxtml::Token &t,::hxtml::Value &v,::String &i){
														HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",832)
														::String _switch_27 = (i);
														if (  ( _switch_27==HX_CSTRING("url"))){
															HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",834)
															return __this->readValueNext(::hxtml::Value_obj::VUrl(__this->readUrl()));
														}
														else if (  ( _switch_27==HX_CSTRING("rgba"))){
															HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",837)
															return __this->readValueNext(::hxtml::Value_obj::VRGBA(__this->readRGBA()));
														}
														else  {
															HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",840)
															__this->tokens->push(t);
															HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",841)
															return v;
														}
;
;
													}
												};
												HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",832)
												return _Function_5_1::Block(__this,t,v,i);
											}
										}
										;break;
										default: {
											HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",844)
											__this->tokens->push(t);
											HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",845)
											return v;
										}
									}
								}
							}
						};
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",830)
						return _Function_3_1::Block(__this,t,v);
					}
					;break;
					case 8: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",848)
						::hxtml::Token t1 = __this->readToken();
						struct _Function_3_1{
							inline static ::hxtml::Value Block( ::hxtml::CssParser_obj *__this,::hxtml::Value &v,::hxtml::Token &t1){
								HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",849)
								{
::hxtml::Token _switch_28 = (t1);
									switch((_switch_28)->GetIndex()){
										case 0: {
											::String i = _switch_28->__Param(0);
{
												HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",850)
												return ::hxtml::Value_obj::VLabel(i,v);
											}
										}
										;break;
										default: {
											HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",852)
											return __this->unexpected(t1);
										}
									}
								}
							}
						};
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",849)
						return _Function_3_1::Block(__this,v,t1);
					}
					;break;
					case 9: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",855)
						return __this->loopComma(v,__this->readValue(null()));
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",858)
						__this->tokens->push(t);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",859)
						::hxtml::Value v2 = __this->readValue(true);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",860)
						return (  (((v2 == null()))) ? ::hxtml::Value(v) : ::hxtml::Value(__this->loopNext(v,v2)) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",829)
	return _Function_1_1::Block(t,this,v);
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,readValueNext,return )

::hxtml::Value CssParser_obj::loopNext( ::hxtml::Value v,::hxtml::Value v2){
	HX_SOURCE_PUSH("CssParser_obj::loopNext")
	struct _Function_1_1{
		inline static ::hxtml::Value Block( ::hxtml::CssParser_obj *__this,::hxtml::Value &v,::hxtml::Value &v2){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",868)
			{
::hxtml::Value _switch_29 = (v2);
				switch((_switch_29)->GetIndex()){
					case 8: {
						Array< ::hxtml::Value > l = _switch_29->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",870)
							l->unshift(v);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",871)
							return v2;
						}
					}
					;break;
					case 7: {
						Array< ::hxtml::Value > l = _switch_29->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",873)
							l[(int)0] = __this->loopNext(v,l->__get((int)0));
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",874)
							return v2;
						}
					}
					;break;
					case 10: {
						::hxtml::Value v21 = _switch_29->__Param(1);
						::String lab = _switch_29->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",875)
							return ::hxtml::Value_obj::VLabel(lab,__this->loopNext(v,v21));
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",877)
						return ::hxtml::Value_obj::VGroup(Array_obj< ::hxtml::Value >::__new().Add(v).Add(v2));
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",867)
	return _Function_1_1::Block(this,v,v2);
}


HX_DEFINE_DYNAMIC_FUNC2(CssParser_obj,loopNext,return )

::hxtml::Value CssParser_obj::loopComma( ::hxtml::Value v,::hxtml::Value v2){
	HX_SOURCE_PUSH("CssParser_obj::loopComma")
	struct _Function_1_1{
		inline static ::hxtml::Value Block( ::hxtml::CssParser_obj *__this,::hxtml::Value &v,::hxtml::Value &v2){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",883)
			{
::hxtml::Value _switch_30 = (v2);
				switch((_switch_30)->GetIndex()){
					case 7: {
						Array< ::hxtml::Value > l = _switch_30->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",885)
							l->unshift(v);
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",886)
							return v2;
						}
					}
					;break;
					case 10: {
						::hxtml::Value v21 = _switch_30->__Param(1);
						::String lab = _switch_30->__Param(0);
{
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",887)
							return ::hxtml::Value_obj::VLabel(lab,__this->loopComma(v,v21));
						}
					}
					;break;
					default: {
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",889)
						return ::hxtml::Value_obj::VList(Array_obj< ::hxtml::Value >::__new().Add(v).Add(v2));
					}
				}
			}
		}
	};
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",882)
	return _Function_1_1::Block(this,v,v2);
}


HX_DEFINE_DYNAMIC_FUNC2(CssParser_obj,loopComma,return )

bool CssParser_obj::isSpace( int c){
	HX_SOURCE_PUSH("CssParser_obj::isSpace")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",896)
	return (bool((bool((bool((c == (int)32)) || bool((c == (int)10)))) || bool((c == (int)13)))) || bool((c == (int)9)));
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,isSpace,return )

bool CssParser_obj::isIdentChar( int c){
	HX_SOURCE_PUSH("CssParser_obj::isIdentChar")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",900)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45)));
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,isIdentChar,return )

bool CssParser_obj::isNum( int c){
	HX_SOURCE_PUSH("CssParser_obj::isNum")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",904)
	return (bool((c >= (int)48)) && bool((c <= (int)57)));
}


HX_DEFINE_DYNAMIC_FUNC1(CssParser_obj,isNum,return )

int CssParser_obj::next( ){
	HX_SOURCE_PUSH("CssParser_obj::next")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",908)
	return this->css.cca((this->pos)++);
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,next,return )

::String CssParser_obj::readUrl( ){
	HX_SOURCE_PUSH("CssParser_obj::readUrl")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",913)
	int c0 = this->css.cca((this->pos)++);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",914)
	while(((bool((bool((bool((c0 == (int)32)) || bool((c0 == (int)10)))) || bool((c0 == (int)13)))) || bool((c0 == (int)9))))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",915)
		c0 = this->css.cca((this->pos)++);
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",916)
	int quote = c0;
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",917)
	if (((bool((quote == (int)39)) || bool((quote == (int)34))))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",918)
		(this->pos)--;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",919)
		{
::hxtml::Token _switch_31 = (this->readToken());
			switch((_switch_31)->GetIndex()){
				case 1: {
					::String s = _switch_31->__Param(0);
{
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",921)
						int c01 = this->css.cca((this->pos)++);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",922)
						while(((bool((bool((bool((c01 == (int)32)) || bool((c01 == (int)10)))) || bool((c01 == (int)13)))) || bool((c01 == (int)9))))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",923)
							c01 = this->css.cca((this->pos)++);
						}
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",924)
						if (((c01 != (int)41))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",925)
							hx::Throw ((HX_CSTRING("Invalid char ") + ::String::fromCharCode(c01)));
						}
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",926)
						return s;
					}
				}
				;break;
				default: {
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",927)
					hx::Throw (HX_CSTRING("assert"));
				}
			}
		}
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",931)
	int start = (this->pos - (int)1);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",932)
	while((true)){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",933)
		if (((c0 == (int)0))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",934)
			break;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",935)
		c0 = this->css.cca((this->pos)++);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",936)
		if (((c0 == (int)41))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",936)
			break;
		}
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",938)
	return ::StringTools_obj::trim(this->css.substr(start,((this->pos - start) - (int)1)));
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,readUrl,return )

::String CssParser_obj::readRGBA( ){
	HX_SOURCE_PUSH("CssParser_obj::readRGBA")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",943)
	int c = this->css.cca((this->pos)++);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",944)
	while(((bool((bool((bool((c == (int)32)) || bool((c == (int)10)))) || bool((c == (int)13)))) || bool((c == (int)9))))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",945)
		c = this->css.cca((this->pos)++);
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",947)
	int start = (this->pos - (int)1);
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",948)
	while((true)){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",949)
		if (((c == (int)0))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",950)
			break;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",951)
		c = this->css.cca((this->pos)++);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",952)
		if (((c == (int)41))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",952)
			break;
		}
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",954)
	return ::StringTools_obj::trim(this->css.substr(start,((this->pos - start) - (int)1)));
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,readRGBA,return )

::hxtml::Token CssParser_obj::readToken( ){
	HX_SOURCE_PUSH("CssParser_obj::readToken")
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",968)
	::hxtml::Token t = this->tokens->pop();
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",969)
	if (((t != null()))){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",970)
		return t;
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",971)
	while((true)){
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",972)
		int c = this->css.cca((this->pos)++);
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",973)
		if (((c == (int)0))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",974)
			return ::hxtml::Token_obj::TEof_dyn();
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",975)
		if (((bool((bool((bool((c == (int)32)) || bool((c == (int)10)))) || bool((c == (int)13)))) || bool((c == (int)9))))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",976)
			if ((this->spacesTokens)){
				struct _Function_4_1{
					inline static bool Block( ::hxtml::CssParser_obj *__this){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",977)
						int c1 = __this->css.cca((__this->pos)++);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",977)
						return (bool((bool((bool((c1 == (int)32)) || bool((c1 == (int)10)))) || bool((c1 == (int)13)))) || bool((c1 == (int)9)));
					}
				};
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",977)
				while((_Function_4_1::Block(this))){
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",979)
				(this->pos)--;
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",980)
				return ::hxtml::Token_obj::TSpaces_dyn();
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",983)
			continue;
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",985)
		if (((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",986)
			int pos = (this->pos - (int)1);
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",987)
			do{
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",987)
				c = this->css.cca((this->pos)++);
			}
while(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45)))));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",988)
			(this->pos)--;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",989)
			return ::hxtml::Token_obj::TIdent(this->css.substr(pos,(this->pos - pos)).toLowerCase());
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",991)
		if (((bool((c >= (int)48)) && bool((c <= (int)57))))){
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",992)
			int i = (int)0;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",993)
			do{
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",994)
				i = ((i * (int)10) + ((c - (int)48)));
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",995)
				c = this->css.cca((this->pos)++);
			}
while(((bool((c >= (int)48)) && bool((c <= (int)57)))));
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",997)
			if (((c == (int)46))){
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",998)
				double f = i;
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",999)
				double k = 0.1;
				struct _Function_4_1{
					inline static bool Block( int &c,::hxtml::CssParser_obj *__this){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1000)
						int c1 = c = __this->css.cca((__this->pos)++);
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1000)
						return (bool((c1 >= (int)48)) && bool((c1 <= (int)57)));
					}
				};
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1000)
				while((_Function_4_1::Block(c,this))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1001)
					hx::AddEq(f,(((c - (int)48)) * k));
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1002)
					hx::MultEq(k,0.1);
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1004)
				(this->pos)--;
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1005)
				return ::hxtml::Token_obj::TFloat(f);
			}
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1007)
			(this->pos)--;
			HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1008)
			return ::hxtml::Token_obj::TInt(i);
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1010)
		switch( (int)(c)){
			case (int)58: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1011)
				return ::hxtml::Token_obj::TDblDot_dyn();
			}
			;break;
			case (int)35: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1012)
				return ::hxtml::Token_obj::TSharp_dyn();
			}
			;break;
			case (int)40: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1013)
				return ::hxtml::Token_obj::TPOpen_dyn();
			}
			;break;
			case (int)41: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1014)
				return ::hxtml::Token_obj::TPClose_dyn();
			}
			;break;
			case (int)33: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1015)
				return ::hxtml::Token_obj::TExclam_dyn();
			}
			;break;
			case (int)37: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1016)
				return ::hxtml::Token_obj::TPercent_dyn();
			}
			;break;
			case (int)59: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1017)
				return ::hxtml::Token_obj::TSemicolon_dyn();
			}
			;break;
			case (int)46: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1018)
				return ::hxtml::Token_obj::TDot_dyn();
			}
			;break;
			case (int)123: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1019)
				return ::hxtml::Token_obj::TBrOpen_dyn();
			}
			;break;
			case (int)125: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1020)
				return ::hxtml::Token_obj::TBrClose_dyn();
			}
			;break;
			case (int)44: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1021)
				return ::hxtml::Token_obj::TComma_dyn();
			}
			;break;
			case (int)47: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1023)
				if ((((c = this->css.cca((this->pos)++)) != (int)42))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1024)
					(this->pos)--;
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1025)
					return ::hxtml::Token_obj::TSlash_dyn();
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1027)
				while((true)){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1028)
					while((((c = this->css.cca((this->pos)++)) != (int)42))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1028)
						if (((c == (int)0))){
							HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1030)
							hx::Throw (HX_CSTRING("Unclosed comment"));
						}
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1032)
					c = this->css.cca((this->pos)++);
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1033)
					if (((c == (int)47))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1033)
						break;
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1034)
					if (((c == (int)0))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1035)
						hx::Throw (HX_CSTRING("Unclosed comment"));
					}
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1037)
				return this->readToken();
			}
			;break;
			case (int)39: case (int)34: {
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1039)
				int pos = this->pos;
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1040)
				int k;
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1041)
				while((((k = this->css.cca((this->pos)++)) != c))){
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1042)
					if (((k == (int)0))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1043)
						hx::Throw (HX_CSTRING("Unclosed string constant"));
					}
					HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1044)
					if (((k == (int)92))){
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1045)
						hx::Throw (HX_CSTRING("todo"));
						HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1046)
						continue;
					}
				}
				HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1049)
				return ::hxtml::Token_obj::TString(this->css.substr(pos,((this->pos - pos) - (int)1)));
			}
			;break;
			default: {
			}
		}
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1052)
		(this->pos)--;
		HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1053)
		hx::Throw ((HX_CSTRING("Invalid char ") + this->css.charAt(this->pos)));
	}
	HX_SOURCE_POS("../../lib/hxtml/CssParser.hx",1055)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CssParser_obj,readToken,return )


CssParser_obj::CssParser_obj()
{
}

void CssParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CssParser);
	HX_MARK_MEMBER_NAME(css,"css");
	HX_MARK_MEMBER_NAME(s,"s");
	HX_MARK_MEMBER_NAME(d,"d");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(spacesTokens,"spacesTokens");
	HX_MARK_MEMBER_NAME(tokens,"tokens");
	HX_MARK_END_CLASS();
}

Dynamic CssParser_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"s") ) { return s; }
		if (HX_FIELD_EQ(inName,"d") ) { return d; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"css") ) { return css; }
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		if (HX_FIELD_EQ(inName,"isNum") ) { return isNum_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tokens") ) { return tokens; }
		if (HX_FIELD_EQ(inName,"getPix") ) { return getPix_dyn(); }
		if (HX_FIELD_EQ(inName,"getCol") ) { return getCol_dyn(); }
		if (HX_FIELD_EQ(inName,"expect") ) { return expect_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getList") ) { return getList_dyn(); }
		if (HX_FIELD_EQ(inName,"isToken") ) { return isToken_dyn(); }
		if (HX_FIELD_EQ(inName,"readHex") ) { return readHex_dyn(); }
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"readUrl") ) { return readUrl_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getGroup") ) { return getGroup_dyn(); }
		if (HX_FIELD_EQ(inName,"getIdent") ) { return getIdent_dyn(); }
		if (HX_FIELD_EQ(inName,"loopNext") ) { return loopNext_dyn(); }
		if (HX_FIELD_EQ(inName,"readRGBA") ) { return readRGBA_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readIdent") ) { return readIdent_dyn(); }
		if (HX_FIELD_EQ(inName,"readValue") ) { return readValue_dyn(); }
		if (HX_FIELD_EQ(inName,"loopComma") ) { return loopComma_dyn(); }
		if (HX_FIELD_EQ(inName,"readToken") ) { return readToken_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"applyStyle") ) { return applyStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"unexpected") ) { return unexpected_dyn(); }
		if (HX_FIELD_EQ(inName,"parseStyle") ) { return parseStyle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getFontName") ) { return getFontName_dyn(); }
		if (HX_FIELD_EQ(inName,"isIdentChar") ) { return isIdentChar_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"spacesTokens") ) { return spacesTokens; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readValueUnit") ) { return readValueUnit_dyn(); }
		if (HX_FIELD_EQ(inName,"readValueNext") ) { return readValueNext_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"notImplemented") ) { return notImplemented_dyn(); }
		if (HX_FIELD_EQ(inName,"applyComposite") ) { return applyComposite_dyn(); }
		if (HX_FIELD_EQ(inName,"getValueObject") ) { return getValueObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic CssParser_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"s") ) { s=inValue.Cast< ::hxtml::IStyleProxy >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d") ) { d=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"css") ) { css=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tokens") ) { tokens=inValue.Cast< Array< ::hxtml::Token > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"spacesTokens") ) { spacesTokens=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CssParser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("css"));
	outFields->push(HX_CSTRING("s"));
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("spacesTokens"));
	outFields->push(HX_CSTRING("tokens"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("css"),
	HX_CSTRING("s"),
	HX_CSTRING("d"),
	HX_CSTRING("pos"),
	HX_CSTRING("spacesTokens"),
	HX_CSTRING("tokens"),
	HX_CSTRING("notImplemented"),
	HX_CSTRING("applyStyle"),
	HX_CSTRING("applyComposite"),
	HX_CSTRING("getValueObject"),
	HX_CSTRING("getGroup"),
	HX_CSTRING("getList"),
	HX_CSTRING("getPix"),
	HX_CSTRING("getIdent"),
	HX_CSTRING("getCol"),
	HX_CSTRING("getFontName"),
	HX_CSTRING("unexpected"),
	HX_CSTRING("expect"),
	HX_CSTRING("push"),
	HX_CSTRING("isToken"),
	HX_CSTRING("parse"),
	HX_CSTRING("parseStyle"),
	HX_CSTRING("readIdent"),
	HX_CSTRING("readValue"),
	HX_CSTRING("readHex"),
	HX_CSTRING("readValueUnit"),
	HX_CSTRING("readValueNext"),
	HX_CSTRING("loopNext"),
	HX_CSTRING("loopComma"),
	HX_CSTRING("isSpace"),
	HX_CSTRING("isIdentChar"),
	HX_CSTRING("isNum"),
	HX_CSTRING("next"),
	HX_CSTRING("readUrl"),
	HX_CSTRING("readRGBA"),
	HX_CSTRING("readToken"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class CssParser_obj::__mClass;

void CssParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxtml.CssParser"), hx::TCanCast< CssParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CssParser_obj::__boot()
{
}

} // end namespace hxtml
