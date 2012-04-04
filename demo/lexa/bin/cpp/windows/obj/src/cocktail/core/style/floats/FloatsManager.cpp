#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CSSFloat
#include <cocktail/core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
#ifndef INCLUDED_cocktail_core_style_floats_FloatsManager
#include <cocktail/core/style/floats/FloatsManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace floats{

Void FloatsManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",40)
	Dynamic floatsLeft = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",41)
	Dynamic floatsRight = Dynamic( Array_obj<Dynamic>::__new() );
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &floatsLeft,Dynamic &floatsRight){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("left") , floatsLeft,false);
			__result->Add(HX_CSTRING("right") , floatsRight,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",43)
	this->_floats = _Function_1_1::Block(floatsLeft,floatsRight);
}
;
	return null();
}

FloatsManager_obj::~FloatsManager_obj() { }

Dynamic FloatsManager_obj::__CreateEmpty() { return  new FloatsManager_obj; }
hx::ObjectPtr< FloatsManager_obj > FloatsManager_obj::__new()
{  hx::ObjectPtr< FloatsManager_obj > result = new FloatsManager_obj();
	result->__construct();
	return result;}

Dynamic FloatsManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatsManager_obj > result = new FloatsManager_obj();
	result->__construct();
	return result;}

Void FloatsManager_obj::dispose( ){
{
		HX_SOURCE_PUSH("FloatsManager_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",51)
		this->_floats->__FieldRef(HX_CSTRING("left")) = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",52)
		this->_floats->__FieldRef(HX_CSTRING("right")) = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",53)
		this->_floats = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FloatsManager_obj,dispose,(void))

int FloatsManager_obj::clearFloat( ::cocktail::core::style::Clear clear,Dynamic formattingContextData){
	HX_SOURCE_PUSH("FloatsManager_obj::clearFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",73)
	int ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",75)
	{
::cocktail::core::style::Clear _switch_1 = (clear);
		switch((_switch_1)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",78)
				ret = this->clearLeft(formattingContextData);
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",79)
				this->_floats->__FieldRef(HX_CSTRING("left")) = Dynamic( Array_obj<Dynamic>::__new() );
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",82)
				ret = this->clearRight(formattingContextData);
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",83)
				this->_floats->__FieldRef(HX_CSTRING("right")) = Dynamic( Array_obj<Dynamic>::__new() );
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",86)
				ret = this->clearBoth(formattingContextData);
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",87)
				this->_floats->__FieldRef(HX_CSTRING("right")) = Dynamic( Array_obj<Dynamic>::__new() );
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",88)
				this->_floats->__FieldRef(HX_CSTRING("left")) = Dynamic( Array_obj<Dynamic>::__new() );
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",90)
				ret = formattingContextData->__Field(HX_CSTRING("y"));
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",94)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,clearFloat,return )

int FloatsManager_obj::clearLeft( Dynamic formattingContextData){
	HX_SOURCE_PUSH("FloatsManager_obj::clearLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",101)
	return this->doClearFloat(formattingContextData,this->_floats->__Field(HX_CSTRING("left")));
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,clearLeft,return )

int FloatsManager_obj::clearRight( Dynamic formattingContextData){
	HX_SOURCE_PUSH("FloatsManager_obj::clearRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",109)
	return this->doClearFloat(formattingContextData,this->_floats->__Field(HX_CSTRING("right")));
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,clearRight,return )

int FloatsManager_obj::clearBoth( Dynamic formattingContextData){
	HX_SOURCE_PUSH("FloatsManager_obj::clearBoth")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",118)
	int leftY = this->doClearFloat(formattingContextData,this->_floats->__Field(HX_CSTRING("left")));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",119)
	int rightY = this->doClearFloat(formattingContextData,this->_floats->__Field(HX_CSTRING("right")));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",121)
	if (((leftY > rightY))){
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",122)
		return leftY;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",126)
		return rightY;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,clearBoth,return )

int FloatsManager_obj::doClearFloat( Dynamic formattingContextData,Dynamic floats){
	HX_SOURCE_PUSH("FloatsManager_obj::doClearFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",141)
	if (((floats->__Field(HX_CSTRING("length")) > (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",146)
		Dynamic highestFloat = floats->__GetItem((int)0);
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",148)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",148)
			int _g1 = (int)0;
			int _g = floats->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",148)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",148)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",150)
				if ((((floats->__GetItem(i)->__Field(HX_CSTRING("y")) + floats->__GetItem(i)->__Field(HX_CSTRING("height"))) > (highestFloat->__Field(HX_CSTRING("y")) + highestFloat->__Field(HX_CSTRING("height")))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",151)
					highestFloat = floats->__GetItem(i);
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",156)
		return (highestFloat->__Field(HX_CSTRING("y")) + highestFloat->__Field(HX_CSTRING("height")));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",162)
		return formattingContextData->__Field(HX_CSTRING("y"));
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,doClearFloat,return )

Dynamic FloatsManager_obj::computeFloatData( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::computeFloatData")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",183)
	Dynamic ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",185)
	{
::cocktail::core::style::CSSFloat _switch_2 = (elementRenderer->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("cssFloat")));
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",188)
				ret = this->getLeftFloatData(elementRenderer,formattingContextData,containingBlockWidth);
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",189)
				this->_floats->__Field(HX_CSTRING("left"))->__Field(HX_CSTRING("push"))(ret);
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",192)
				ret = this->getRightFloatData(elementRenderer,formattingContextData,containingBlockWidth);
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",193)
				this->_floats->__Field(HX_CSTRING("right"))->__Field(HX_CSTRING("push"))(ret);
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",195)
				ret = null();
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",199)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,computeFloatData,return )

Dynamic FloatsManager_obj::getLeftFloatData( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::getLeftFloatData")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",210)
	Dynamic floatData = this->getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",214)
	floatData->__FieldRef(HX_CSTRING("x")) = this->getLeftFloatOffset(floatData->__Field(HX_CSTRING("y")));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",216)
	return floatData;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,getLeftFloatData,return )

Dynamic FloatsManager_obj::getRightFloatData( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::getRightFloatData")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",225)
	Dynamic floatData = this->getFloatData(elementRenderer,formattingContextData,containingBlockWidth);
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",229)
	floatData->__FieldRef(HX_CSTRING("x")) = ((containingBlockWidth - floatData->__Field(HX_CSTRING("width"))) - this->getRightFloatOffset(floatData->__Field(HX_CSTRING("y")),containingBlockWidth));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",231)
	return floatData;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,getRightFloatData,return )

Dynamic FloatsManager_obj::getFloatData( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::getFloatData")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",243)
	Dynamic computedStyle = elementRenderer->getCoreStyle()->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",244)
	int floatWidth = ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",245)
	int floatHeight = ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",248)
	int floatY = this->getFirstAvailableY(formattingContextData,floatWidth,containingBlockWidth);
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",251)
	int floatX = (int)0;
	struct _Function_1_1{
		inline static Dynamic Block( int &floatY,int &floatHeight,int &floatX,int &floatWidth){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , floatX,false);
			__result->Add(HX_CSTRING("y") , floatY,false);
			__result->Add(HX_CSTRING("width") , floatWidth,false);
			__result->Add(HX_CSTRING("height") , floatHeight,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",253)
	return _Function_1_1::Block(floatY,floatHeight,floatX,floatWidth);
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,getFloatData,return )

int FloatsManager_obj::getFirstAvailableY( Dynamic formattingContextData,int elementWidth,int containingBlockWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::getFirstAvailableY")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",275)
	int retY = formattingContextData->__Field(HX_CSTRING("y"));
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",279)
	while(((((this->getLeftFloatOffset(retY) + this->getRightFloatOffset(retY,containingBlockWidth)) + elementWidth) > containingBlockWidth))){
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",283)
		Dynamic afterFloats = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",286)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",286)
			int _g1 = (int)0;
			int _g = this->_floats->__Field(HX_CSTRING("left"))->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",286)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",286)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",288)
				if (((bool((this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("y")) <= retY)) && bool(((this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("height")) + this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("y"))) > retY))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",289)
					afterFloats->__Field(HX_CSTRING("push"))(this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i));
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",295)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",295)
			int _g1 = (int)0;
			int _g = this->_floats->__Field(HX_CSTRING("right"))->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",295)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",295)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",297)
				if (((bool((this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("y")) <= retY)) && bool(((this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("height")) + this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("y"))) > retY))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",298)
					afterFloats->__Field(HX_CSTRING("push"))(this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i));
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",306)
		if (((afterFloats->__Field(HX_CSTRING("length")) == (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",307)
			break;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",319)
			int nextY = (int)1000000;
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",322)
			{
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",322)
				int _g1 = (int)0;
				int _g = afterFloats->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",322)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",322)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",324)
					if (((((afterFloats->__GetItem(i)->__Field(HX_CSTRING("y")) + afterFloats->__GetItem(i)->__Field(HX_CSTRING("height"))) - retY) < nextY))){
						HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",325)
						nextY = ((afterFloats->__GetItem(i)->__Field(HX_CSTRING("y")) + afterFloats->__GetItem(i)->__Field(HX_CSTRING("height"))) - retY);
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",334)
			hx::AddEq(retY,nextY);
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",340)
	return retY;
}


HX_DEFINE_DYNAMIC_FUNC3(FloatsManager_obj,getFirstAvailableY,return )

Void FloatsManager_obj::removeFloats( int flowY){
{
		HX_SOURCE_PUSH("FloatsManager_obj::removeFloats")
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",355)
		this->_floats->__FieldRef(HX_CSTRING("left")) = this->doRemoveFloat(this->_floats->__Field(HX_CSTRING("left")),flowY);
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",356)
		this->_floats->__FieldRef(HX_CSTRING("right")) = this->doRemoveFloat(this->_floats->__Field(HX_CSTRING("right")),flowY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,removeFloats,(void))

Dynamic FloatsManager_obj::doRemoveFloat( Dynamic floats,int flowY){
	HX_SOURCE_PUSH("FloatsManager_obj::doRemoveFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",365)
	Dynamic newFloats = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",367)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",367)
		int _g1 = (int)0;
		int _g = floats->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",367)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",367)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",371)
			if ((((floats->__GetItem(i)->__Field(HX_CSTRING("y")) + floats->__GetItem(i)->__Field(HX_CSTRING("height"))) > flowY))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",372)
				newFloats->__Field(HX_CSTRING("push"))(floats->__GetItem(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",377)
	return newFloats;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,doRemoveFloat,return )

int FloatsManager_obj::getRightFloatOffset( int y,int containingWidth){
	HX_SOURCE_PUSH("FloatsManager_obj::getRightFloatOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",392)
	int rightFloatOffset = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",395)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",395)
		int _g1 = (int)0;
		int _g = this->_floats->__Field(HX_CSTRING("right"))->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",395)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",395)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",398)
			if (((bool(((this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("y")) + this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("height"))) > y)) && bool((this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("y")) <= y))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",400)
				if ((((containingWidth - this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("x"))) > rightFloatOffset))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",405)
					rightFloatOffset = (containingWidth - this->_floats->__Field(HX_CSTRING("right"))->__GetItem(i)->__Field(HX_CSTRING("x")));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",411)
	return rightFloatOffset;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatsManager_obj,getRightFloatOffset,return )

int FloatsManager_obj::getLeftFloatOffset( int y){
	HX_SOURCE_PUSH("FloatsManager_obj::getLeftFloatOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",422)
	int leftFloatOffset = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",425)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",425)
		int _g1 = (int)0;
		int _g = this->_floats->__Field(HX_CSTRING("left"))->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",425)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",425)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",428)
			if (((bool(((this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("y")) + this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("height"))) > y)) && bool((this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("y")) <= y))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",430)
				if ((((this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("x")) + this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("width"))) > leftFloatOffset))){
					HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",435)
					leftFloatOffset = (this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("x")) + this->_floats->__Field(HX_CSTRING("left"))->__GetItem(i)->__Field(HX_CSTRING("width")));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",441)
	return leftFloatOffset;
}


HX_DEFINE_DYNAMIC_FUNC1(FloatsManager_obj,getLeftFloatOffset,return )

Dynamic FloatsManager_obj::getFloats( ){
	HX_SOURCE_PUSH("FloatsManager_obj::getFloats")
	HX_SOURCE_POS("../../src/cocktail/core/style/floats/FloatsManager.hx",449)
	return this->_floats;
}


HX_DEFINE_DYNAMIC_FUNC0(FloatsManager_obj,getFloats,return )


FloatsManager_obj::FloatsManager_obj()
{
}

void FloatsManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatsManager);
	HX_MARK_MEMBER_NAME(_floats,"_floats");
	HX_MARK_MEMBER_NAME(floats,"floats");
	HX_MARK_END_CLASS();
}

Dynamic FloatsManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"floats") ) { return getFloats(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_floats") ) { return _floats; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"clearLeft") ) { return clearLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"clearBoth") ) { return clearBoth_dyn(); }
		if (HX_FIELD_EQ(inName,"getFloats") ) { return getFloats_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"clearFloat") ) { return clearFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"clearRight") ) { return clearRight_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"doClearFloat") ) { return doClearFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"getFloatData") ) { return getFloatData_dyn(); }
		if (HX_FIELD_EQ(inName,"removeFloats") ) { return removeFloats_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"doRemoveFloat") ) { return doRemoveFloat_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"computeFloatData") ) { return computeFloatData_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeftFloatData") ) { return getLeftFloatData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getRightFloatData") ) { return getRightFloatData_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getFirstAvailableY") ) { return getFirstAvailableY_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeftFloatOffset") ) { return getLeftFloatOffset_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getRightFloatOffset") ) { return getRightFloatOffset_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FloatsManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"floats") ) { floats=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_floats") ) { _floats=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FloatsManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_floats"));
	outFields->push(HX_CSTRING("floats"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_floats"),
	HX_CSTRING("floats"),
	HX_CSTRING("dispose"),
	HX_CSTRING("clearFloat"),
	HX_CSTRING("clearLeft"),
	HX_CSTRING("clearRight"),
	HX_CSTRING("clearBoth"),
	HX_CSTRING("doClearFloat"),
	HX_CSTRING("computeFloatData"),
	HX_CSTRING("getLeftFloatData"),
	HX_CSTRING("getRightFloatData"),
	HX_CSTRING("getFloatData"),
	HX_CSTRING("getFirstAvailableY"),
	HX_CSTRING("removeFloats"),
	HX_CSTRING("doRemoveFloat"),
	HX_CSTRING("getRightFloatOffset"),
	HX_CSTRING("getLeftFloatOffset"),
	HX_CSTRING("getFloats"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FloatsManager_obj::__mClass;

void FloatsManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.floats.FloatsManager"), hx::TCanCast< FloatsManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FloatsManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace floats
