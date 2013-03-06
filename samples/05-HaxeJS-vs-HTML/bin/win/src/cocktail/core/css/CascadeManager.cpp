#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CascadeManager_obj::__construct()
{
HX_STACK_PUSH("CascadeManager::new","cocktail/core/css/CascadeManager.hx",134);
{
	HX_STACK_LINE(135)
	this->propertiesToCascade = Array_obj< bool >::__new();
	HX_STACK_LINE(136)
	this->reset();
}
;
	return null();
}

CascadeManager_obj::~CascadeManager_obj() { }

Dynamic CascadeManager_obj::__CreateEmpty() { return  new CascadeManager_obj; }
hx::ObjectPtr< CascadeManager_obj > CascadeManager_obj::__new()
{  hx::ObjectPtr< CascadeManager_obj > result = new CascadeManager_obj();
	result->__construct();
	return result;}

Dynamic CascadeManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CascadeManager_obj > result = new CascadeManager_obj();
	result->__construct();
	return result;}

Void CascadeManager_obj::unFlagProperty( int index){
{
		HX_STACK_PUSH("CascadeManager::unFlagProperty","cocktail/core/css/CascadeManager.hx",388);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(388)
		switch( (int)(index)){
			case (int)40: {
				HX_STACK_LINE(391)
				this->hasColor = false;
			}
			;break;
			case (int)34: {
				HX_STACK_LINE(394)
				this->hasFontSize = false;
			}
			;break;
			case (int)37: {
				HX_STACK_LINE(397)
				this->hasFontFamily = false;
			}
			;break;
			case (int)57: {
				HX_STACK_LINE(400)
				this->hasTransitionProperty = false;
			}
			;break;
			case (int)72: {
				HX_STACK_LINE(403)
				this->hasTopBorderStyle = false;
			}
			;break;
			case (int)73: {
				HX_STACK_LINE(406)
				this->hasRightBorderStyle = false;
			}
			;break;
			case (int)75: {
				HX_STACK_LINE(409)
				this->hasLeftBorderStyle = false;
			}
			;break;
			case (int)74: {
				HX_STACK_LINE(412)
				this->hasBottomBorderStyle = false;
			}
			;break;
			case (int)83: {
				HX_STACK_LINE(415)
				this->hasOutlineStyle = false;
			}
			;break;
			default: {
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CascadeManager_obj,unFlagProperty,(void))

Void CascadeManager_obj::flagProperty( int index){
{
		HX_STACK_PUSH("CascadeManager::flagProperty","cocktail/core/css/CascadeManager.hx",248);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(248)
		switch( (int)(index)){
			case (int)34: {
				HX_STACK_LINE(252)
				this->hasFontSize = true;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(255)
				this->hasMarginTop = true;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(258)
				this->hasMarginBottom = true;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(261)
				this->hasMarginLeft = true;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(264)
				this->hasMarginRight = true;
			}
			;break;
			case (int)57: {
				HX_STACK_LINE(267)
				this->hasTransitionProperty = true;
			}
			;break;
			case (int)21: {
				HX_STACK_LINE(270)
				this->hasTop = true;
			}
			;break;
			case (int)24: {
				HX_STACK_LINE(273)
				this->hasBottom = true;
			}
			;break;
			case (int)22: {
				HX_STACK_LINE(276)
				this->hasLeft = true;
			}
			;break;
			case (int)23: {
				HX_STACK_LINE(279)
				this->hasRight = true;
			}
			;break;
			case (int)46: {
				HX_STACK_LINE(282)
				this->hasTextAlign = true;
			}
			;break;
			case (int)18: {
				HX_STACK_LINE(285)
				this->hasMaxHeight = true;
			}
			;break;
			case (int)20: {
				HX_STACK_LINE(288)
				this->hasMaxWidth = true;
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(291)
				this->hasWidth = true;
			}
			;break;
			case (int)16: {
				HX_STACK_LINE(294)
				this->hasHeight = true;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(297)
				this->hasClear = true;
			}
			;break;
			case (int)45: {
				HX_STACK_LINE(300)
				this->hasWhiteSpace = true;
			}
			;break;
			case (int)26: {
				HX_STACK_LINE(303)
				this->hasBackgroundImage = true;
			}
			;break;
			case (int)48: {
				HX_STACK_LINE(306)
				this->hasVerticalAlign = true;
			}
			;break;
			case (int)41: {
				HX_STACK_LINE(309)
				this->hasLineHeight = true;
			}
			;break;
			case (int)43: {
				HX_STACK_LINE(312)
				this->hasLetterSpacing = true;
			}
			;break;
			case (int)53: {
				HX_STACK_LINE(315)
				this->hasOpacity = true;
			}
			;break;
			case (int)37: {
				HX_STACK_LINE(318)
				this->hasFontFamily = true;
			}
			;break;
			case (int)49: {
				HX_STACK_LINE(321)
				this->hasVisible = true;
			}
			;break;
			case (int)25: {
				HX_STACK_LINE(324)
				this->hasBackgroundColor = true;
			}
			;break;
			case (int)40: {
				HX_STACK_LINE(327)
				this->hasColor = true;
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(330)
				this->hasDisplay = true;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(333)
				this->hasFloat = true;
			}
			;break;
			case (int)51: {
				HX_STACK_LINE(336)
				this->hasOverflowX = true;
			}
			;break;
			case (int)52: {
				HX_STACK_LINE(339)
				this->hasOverflowY = true;
			}
			;break;
			case (int)61: {
				HX_STACK_LINE(342)
				this->hasTransform = true;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(345)
				this->hasZIndex = true;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(348)
				this->hasPosition = true;
			}
			;break;
			case (int)75: {
				HX_STACK_LINE(351)
				this->hasLeftBorderStyle = true;
			}
			;break;
			case (int)72: {
				HX_STACK_LINE(354)
				this->hasTopBorderStyle = true;
			}
			;break;
			case (int)73: {
				HX_STACK_LINE(357)
				this->hasRightBorderStyle = true;
			}
			;break;
			case (int)74: {
				HX_STACK_LINE(360)
				this->hasBottomBorderStyle = true;
			}
			;break;
			case (int)67: {
				HX_STACK_LINE(363)
				this->hasTopBorderColor = true;
			}
			;break;
			case (int)69: {
				HX_STACK_LINE(366)
				this->hasBottomBorderColor = true;
			}
			;break;
			case (int)68: {
				HX_STACK_LINE(369)
				this->hasRightBorderColor = true;
			}
			;break;
			case (int)70: {
				HX_STACK_LINE(372)
				this->hasLeftBorderColor = true;
			}
			;break;
			case (int)83: {
				HX_STACK_LINE(375)
				this->hasOutlineStyle = true;
			}
			;break;
			case (int)84: {
				HX_STACK_LINE(378)
				this->hasOutlineColor = true;
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CascadeManager_obj,flagProperty,(void))

Void CascadeManager_obj::shouldCascadeAll( ){
{
		HX_STACK_PUSH("CascadeManager::shouldCascadeAll","cocktail/core/css/CascadeManager.hx",232);
		HX_STACK_THIS(this);
		HX_STACK_LINE(233)
		this->cascadeAll = true;
		HX_STACK_LINE(234)
		this->hasPropertiesToCascade = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CascadeManager_obj,shouldCascadeAll,(void))

Void CascadeManager_obj::removePropertyToCascade( int index){
{
		HX_STACK_PUSH("CascadeManager::removePropertyToCascade","cocktail/core/css/CascadeManager.hx",222);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(223)
		this->unFlagProperty(index);
		HX_STACK_LINE(224)
		this->propertiesToCascade[index] = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CascadeManager_obj,removePropertyToCascade,(void))

Void CascadeManager_obj::addPropertyToCascade( int index){
{
		HX_STACK_PUSH("CascadeManager::addPropertyToCascade","cocktail/core/css/CascadeManager.hx",205);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(208)
		if (((this->cascadeAll == true))){
			HX_STACK_LINE(209)
			return null();
		}
		HX_STACK_LINE(213)
		this->propertiesToCascade[index] = true;
		HX_STACK_LINE(214)
		this->flagProperty(index);
		HX_STACK_LINE(215)
		this->hasPropertiesToCascade = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CascadeManager_obj,addPropertyToCascade,(void))

Void CascadeManager_obj::reset( ){
{
		HX_STACK_PUSH("CascadeManager::reset","cocktail/core/css/CascadeManager.hx",143);
		HX_STACK_THIS(this);
		HX_STACK_LINE(144)
		if (((this->hasPropertiesToCascade == true))){
			HX_STACK_LINE(147)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(147)
			while(((_g < (int)87))){
				HX_STACK_LINE(147)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(149)
				this->propertiesToCascade[i] = false;
			}
		}
		HX_STACK_LINE(153)
		this->hasFontSize = false;
		HX_STACK_LINE(154)
		this->hasFontFamily = false;
		HX_STACK_LINE(155)
		this->hasBackgroundColor = false;
		HX_STACK_LINE(156)
		this->hasColor = false;
		HX_STACK_LINE(157)
		this->hasDisplay = false;
		HX_STACK_LINE(158)
		this->hasFloat = false;
		HX_STACK_LINE(159)
		this->hasOverflowX = false;
		HX_STACK_LINE(160)
		this->hasOverflowY = false;
		HX_STACK_LINE(161)
		this->hasLetterSpacing = false;
		HX_STACK_LINE(162)
		this->hasLineHeight = false;
		HX_STACK_LINE(163)
		this->hasTransform = false;
		HX_STACK_LINE(164)
		this->hasZIndex = false;
		HX_STACK_LINE(165)
		this->hasPosition = false;
		HX_STACK_LINE(166)
		this->hasVisible = false;
		HX_STACK_LINE(167)
		this->hasOpacity = false;
		HX_STACK_LINE(168)
		this->hasBackgroundImage = false;
		HX_STACK_LINE(169)
		this->hasVerticalAlign = false;
		HX_STACK_LINE(170)
		this->hasClear = false;
		HX_STACK_LINE(171)
		this->hasWhiteSpace = false;
		HX_STACK_LINE(172)
		this->hasWidth = false;
		HX_STACK_LINE(173)
		this->hasHeight = false;
		HX_STACK_LINE(174)
		this->hasMaxHeight = false;
		HX_STACK_LINE(175)
		this->hasMaxWidth = false;
		HX_STACK_LINE(176)
		this->hasTextAlign = false;
		HX_STACK_LINE(177)
		this->hasTop = false;
		HX_STACK_LINE(178)
		this->hasBottom = false;
		HX_STACK_LINE(179)
		this->hasLeft = false;
		HX_STACK_LINE(180)
		this->hasRight = false;
		HX_STACK_LINE(181)
		this->hasMarginTop = false;
		HX_STACK_LINE(182)
		this->hasMarginBottom = false;
		HX_STACK_LINE(183)
		this->hasMarginLeft = false;
		HX_STACK_LINE(184)
		this->hasMarginRight = false;
		HX_STACK_LINE(185)
		this->hasTransitionProperty = false;
		HX_STACK_LINE(186)
		this->hasLeftBorderStyle = false;
		HX_STACK_LINE(187)
		this->hasTopBorderStyle = false;
		HX_STACK_LINE(188)
		this->hasRightBorderStyle = false;
		HX_STACK_LINE(189)
		this->hasBottomBorderStyle = false;
		HX_STACK_LINE(190)
		this->hasBottomBorderColor = false;
		HX_STACK_LINE(191)
		this->hasTopBorderColor = false;
		HX_STACK_LINE(192)
		this->hasLeftBorderColor = false;
		HX_STACK_LINE(193)
		this->hasRightBorderColor = false;
		HX_STACK_LINE(194)
		this->hasOutlineStyle = false;
		HX_STACK_LINE(195)
		this->hasOutlineColor = false;
		HX_STACK_LINE(197)
		this->hasPropertiesToCascade = false;
		HX_STACK_LINE(198)
		this->cascadeAll = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CascadeManager_obj,reset,(void))


CascadeManager_obj::CascadeManager_obj()
{
}

void CascadeManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CascadeManager);
	HX_MARK_MEMBER_NAME(hasOutlineColor,"hasOutlineColor");
	HX_MARK_MEMBER_NAME(hasOutlineStyle,"hasOutlineStyle");
	HX_MARK_MEMBER_NAME(hasBottomBorderColor,"hasBottomBorderColor");
	HX_MARK_MEMBER_NAME(hasTopBorderColor,"hasTopBorderColor");
	HX_MARK_MEMBER_NAME(hasRightBorderColor,"hasRightBorderColor");
	HX_MARK_MEMBER_NAME(hasLeftBorderColor,"hasLeftBorderColor");
	HX_MARK_MEMBER_NAME(hasBottomBorderStyle,"hasBottomBorderStyle");
	HX_MARK_MEMBER_NAME(hasTopBorderStyle,"hasTopBorderStyle");
	HX_MARK_MEMBER_NAME(hasRightBorderStyle,"hasRightBorderStyle");
	HX_MARK_MEMBER_NAME(hasLeftBorderStyle,"hasLeftBorderStyle");
	HX_MARK_MEMBER_NAME(hasTransitionProperty,"hasTransitionProperty");
	HX_MARK_MEMBER_NAME(hasMarginBottom,"hasMarginBottom");
	HX_MARK_MEMBER_NAME(hasMarginRight,"hasMarginRight");
	HX_MARK_MEMBER_NAME(hasMarginTop,"hasMarginTop");
	HX_MARK_MEMBER_NAME(hasMarginLeft,"hasMarginLeft");
	HX_MARK_MEMBER_NAME(hasRight,"hasRight");
	HX_MARK_MEMBER_NAME(hasLeft,"hasLeft");
	HX_MARK_MEMBER_NAME(hasBottom,"hasBottom");
	HX_MARK_MEMBER_NAME(hasTop,"hasTop");
	HX_MARK_MEMBER_NAME(hasTextAlign,"hasTextAlign");
	HX_MARK_MEMBER_NAME(hasMaxWidth,"hasMaxWidth");
	HX_MARK_MEMBER_NAME(hasMaxHeight,"hasMaxHeight");
	HX_MARK_MEMBER_NAME(hasHeight,"hasHeight");
	HX_MARK_MEMBER_NAME(hasWidth,"hasWidth");
	HX_MARK_MEMBER_NAME(hasWhiteSpace,"hasWhiteSpace");
	HX_MARK_MEMBER_NAME(hasClear,"hasClear");
	HX_MARK_MEMBER_NAME(hasVerticalAlign,"hasVerticalAlign");
	HX_MARK_MEMBER_NAME(hasBackgroundImage,"hasBackgroundImage");
	HX_MARK_MEMBER_NAME(hasOpacity,"hasOpacity");
	HX_MARK_MEMBER_NAME(hasVisible,"hasVisible");
	HX_MARK_MEMBER_NAME(hasPosition,"hasPosition");
	HX_MARK_MEMBER_NAME(hasZIndex,"hasZIndex");
	HX_MARK_MEMBER_NAME(hasTransform,"hasTransform");
	HX_MARK_MEMBER_NAME(hasOverflowY,"hasOverflowY");
	HX_MARK_MEMBER_NAME(hasOverflowX,"hasOverflowX");
	HX_MARK_MEMBER_NAME(hasFloat,"hasFloat");
	HX_MARK_MEMBER_NAME(hasLetterSpacing,"hasLetterSpacing");
	HX_MARK_MEMBER_NAME(hasLineHeight,"hasLineHeight");
	HX_MARK_MEMBER_NAME(hasDisplay,"hasDisplay");
	HX_MARK_MEMBER_NAME(hasColor,"hasColor");
	HX_MARK_MEMBER_NAME(hasBackgroundColor,"hasBackgroundColor");
	HX_MARK_MEMBER_NAME(hasFontFamily,"hasFontFamily");
	HX_MARK_MEMBER_NAME(hasFontSize,"hasFontSize");
	HX_MARK_MEMBER_NAME(hasPropertiesToCascade,"hasPropertiesToCascade");
	HX_MARK_MEMBER_NAME(cascadeAll,"cascadeAll");
	HX_MARK_MEMBER_NAME(propertiesToCascade,"propertiesToCascade");
	HX_MARK_END_CLASS();
}

void CascadeManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hasOutlineColor,"hasOutlineColor");
	HX_VISIT_MEMBER_NAME(hasOutlineStyle,"hasOutlineStyle");
	HX_VISIT_MEMBER_NAME(hasBottomBorderColor,"hasBottomBorderColor");
	HX_VISIT_MEMBER_NAME(hasTopBorderColor,"hasTopBorderColor");
	HX_VISIT_MEMBER_NAME(hasRightBorderColor,"hasRightBorderColor");
	HX_VISIT_MEMBER_NAME(hasLeftBorderColor,"hasLeftBorderColor");
	HX_VISIT_MEMBER_NAME(hasBottomBorderStyle,"hasBottomBorderStyle");
	HX_VISIT_MEMBER_NAME(hasTopBorderStyle,"hasTopBorderStyle");
	HX_VISIT_MEMBER_NAME(hasRightBorderStyle,"hasRightBorderStyle");
	HX_VISIT_MEMBER_NAME(hasLeftBorderStyle,"hasLeftBorderStyle");
	HX_VISIT_MEMBER_NAME(hasTransitionProperty,"hasTransitionProperty");
	HX_VISIT_MEMBER_NAME(hasMarginBottom,"hasMarginBottom");
	HX_VISIT_MEMBER_NAME(hasMarginRight,"hasMarginRight");
	HX_VISIT_MEMBER_NAME(hasMarginTop,"hasMarginTop");
	HX_VISIT_MEMBER_NAME(hasMarginLeft,"hasMarginLeft");
	HX_VISIT_MEMBER_NAME(hasRight,"hasRight");
	HX_VISIT_MEMBER_NAME(hasLeft,"hasLeft");
	HX_VISIT_MEMBER_NAME(hasBottom,"hasBottom");
	HX_VISIT_MEMBER_NAME(hasTop,"hasTop");
	HX_VISIT_MEMBER_NAME(hasTextAlign,"hasTextAlign");
	HX_VISIT_MEMBER_NAME(hasMaxWidth,"hasMaxWidth");
	HX_VISIT_MEMBER_NAME(hasMaxHeight,"hasMaxHeight");
	HX_VISIT_MEMBER_NAME(hasHeight,"hasHeight");
	HX_VISIT_MEMBER_NAME(hasWidth,"hasWidth");
	HX_VISIT_MEMBER_NAME(hasWhiteSpace,"hasWhiteSpace");
	HX_VISIT_MEMBER_NAME(hasClear,"hasClear");
	HX_VISIT_MEMBER_NAME(hasVerticalAlign,"hasVerticalAlign");
	HX_VISIT_MEMBER_NAME(hasBackgroundImage,"hasBackgroundImage");
	HX_VISIT_MEMBER_NAME(hasOpacity,"hasOpacity");
	HX_VISIT_MEMBER_NAME(hasVisible,"hasVisible");
	HX_VISIT_MEMBER_NAME(hasPosition,"hasPosition");
	HX_VISIT_MEMBER_NAME(hasZIndex,"hasZIndex");
	HX_VISIT_MEMBER_NAME(hasTransform,"hasTransform");
	HX_VISIT_MEMBER_NAME(hasOverflowY,"hasOverflowY");
	HX_VISIT_MEMBER_NAME(hasOverflowX,"hasOverflowX");
	HX_VISIT_MEMBER_NAME(hasFloat,"hasFloat");
	HX_VISIT_MEMBER_NAME(hasLetterSpacing,"hasLetterSpacing");
	HX_VISIT_MEMBER_NAME(hasLineHeight,"hasLineHeight");
	HX_VISIT_MEMBER_NAME(hasDisplay,"hasDisplay");
	HX_VISIT_MEMBER_NAME(hasColor,"hasColor");
	HX_VISIT_MEMBER_NAME(hasBackgroundColor,"hasBackgroundColor");
	HX_VISIT_MEMBER_NAME(hasFontFamily,"hasFontFamily");
	HX_VISIT_MEMBER_NAME(hasFontSize,"hasFontSize");
	HX_VISIT_MEMBER_NAME(hasPropertiesToCascade,"hasPropertiesToCascade");
	HX_VISIT_MEMBER_NAME(cascadeAll,"cascadeAll");
	HX_VISIT_MEMBER_NAME(propertiesToCascade,"propertiesToCascade");
}

Dynamic CascadeManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"hasTop") ) { return hasTop; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasLeft") ) { return hasLeft; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasRight") ) { return hasRight; }
		if (HX_FIELD_EQ(inName,"hasWidth") ) { return hasWidth; }
		if (HX_FIELD_EQ(inName,"hasClear") ) { return hasClear; }
		if (HX_FIELD_EQ(inName,"hasFloat") ) { return hasFloat; }
		if (HX_FIELD_EQ(inName,"hasColor") ) { return hasColor; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasBottom") ) { return hasBottom; }
		if (HX_FIELD_EQ(inName,"hasHeight") ) { return hasHeight; }
		if (HX_FIELD_EQ(inName,"hasZIndex") ) { return hasZIndex; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasOpacity") ) { return hasOpacity; }
		if (HX_FIELD_EQ(inName,"hasVisible") ) { return hasVisible; }
		if (HX_FIELD_EQ(inName,"hasDisplay") ) { return hasDisplay; }
		if (HX_FIELD_EQ(inName,"cascadeAll") ) { return cascadeAll; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasMaxWidth") ) { return hasMaxWidth; }
		if (HX_FIELD_EQ(inName,"hasPosition") ) { return hasPosition; }
		if (HX_FIELD_EQ(inName,"hasFontSize") ) { return hasFontSize; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"flagProperty") ) { return flagProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasMarginTop") ) { return hasMarginTop; }
		if (HX_FIELD_EQ(inName,"hasTextAlign") ) { return hasTextAlign; }
		if (HX_FIELD_EQ(inName,"hasMaxHeight") ) { return hasMaxHeight; }
		if (HX_FIELD_EQ(inName,"hasTransform") ) { return hasTransform; }
		if (HX_FIELD_EQ(inName,"hasOverflowY") ) { return hasOverflowY; }
		if (HX_FIELD_EQ(inName,"hasOverflowX") ) { return hasOverflowX; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasMarginLeft") ) { return hasMarginLeft; }
		if (HX_FIELD_EQ(inName,"hasWhiteSpace") ) { return hasWhiteSpace; }
		if (HX_FIELD_EQ(inName,"hasLineHeight") ) { return hasLineHeight; }
		if (HX_FIELD_EQ(inName,"hasFontFamily") ) { return hasFontFamily; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"unFlagProperty") ) { return unFlagProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasMarginRight") ) { return hasMarginRight; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasOutlineColor") ) { return hasOutlineColor; }
		if (HX_FIELD_EQ(inName,"hasOutlineStyle") ) { return hasOutlineStyle; }
		if (HX_FIELD_EQ(inName,"hasMarginBottom") ) { return hasMarginBottom; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"shouldCascadeAll") ) { return shouldCascadeAll_dyn(); }
		if (HX_FIELD_EQ(inName,"hasVerticalAlign") ) { return hasVerticalAlign; }
		if (HX_FIELD_EQ(inName,"hasLetterSpacing") ) { return hasLetterSpacing; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"hasTopBorderColor") ) { return hasTopBorderColor; }
		if (HX_FIELD_EQ(inName,"hasTopBorderStyle") ) { return hasTopBorderStyle; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"hasLeftBorderColor") ) { return hasLeftBorderColor; }
		if (HX_FIELD_EQ(inName,"hasLeftBorderStyle") ) { return hasLeftBorderStyle; }
		if (HX_FIELD_EQ(inName,"hasBackgroundImage") ) { return hasBackgroundImage; }
		if (HX_FIELD_EQ(inName,"hasBackgroundColor") ) { return hasBackgroundColor; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"hasRightBorderColor") ) { return hasRightBorderColor; }
		if (HX_FIELD_EQ(inName,"hasRightBorderStyle") ) { return hasRightBorderStyle; }
		if (HX_FIELD_EQ(inName,"propertiesToCascade") ) { return propertiesToCascade; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"addPropertyToCascade") ) { return addPropertyToCascade_dyn(); }
		if (HX_FIELD_EQ(inName,"hasBottomBorderColor") ) { return hasBottomBorderColor; }
		if (HX_FIELD_EQ(inName,"hasBottomBorderStyle") ) { return hasBottomBorderStyle; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"hasTransitionProperty") ) { return hasTransitionProperty; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"hasPropertiesToCascade") ) { return hasPropertiesToCascade; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"removePropertyToCascade") ) { return removePropertyToCascade_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CascadeManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"hasTop") ) { hasTop=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasLeft") ) { hasLeft=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasRight") ) { hasRight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasWidth") ) { hasWidth=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasClear") ) { hasClear=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasFloat") ) { hasFloat=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasColor") ) { hasColor=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasBottom") ) { hasBottom=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasHeight") ) { hasHeight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasZIndex") ) { hasZIndex=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasOpacity") ) { hasOpacity=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasVisible") ) { hasVisible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasDisplay") ) { hasDisplay=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cascadeAll") ) { cascadeAll=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasMaxWidth") ) { hasMaxWidth=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasPosition") ) { hasPosition=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasFontSize") ) { hasFontSize=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hasMarginTop") ) { hasMarginTop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasTextAlign") ) { hasTextAlign=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasMaxHeight") ) { hasMaxHeight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasTransform") ) { hasTransform=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasOverflowY") ) { hasOverflowY=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasOverflowX") ) { hasOverflowX=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasMarginLeft") ) { hasMarginLeft=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasWhiteSpace") ) { hasWhiteSpace=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasLineHeight") ) { hasLineHeight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasFontFamily") ) { hasFontFamily=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hasMarginRight") ) { hasMarginRight=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasOutlineColor") ) { hasOutlineColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasOutlineStyle") ) { hasOutlineStyle=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasMarginBottom") ) { hasMarginBottom=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hasVerticalAlign") ) { hasVerticalAlign=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasLetterSpacing") ) { hasLetterSpacing=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"hasTopBorderColor") ) { hasTopBorderColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasTopBorderStyle") ) { hasTopBorderStyle=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"hasLeftBorderColor") ) { hasLeftBorderColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasLeftBorderStyle") ) { hasLeftBorderStyle=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBackgroundImage") ) { hasBackgroundImage=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBackgroundColor") ) { hasBackgroundColor=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"hasRightBorderColor") ) { hasRightBorderColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasRightBorderStyle") ) { hasRightBorderStyle=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"propertiesToCascade") ) { propertiesToCascade=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"hasBottomBorderColor") ) { hasBottomBorderColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBottomBorderStyle") ) { hasBottomBorderStyle=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"hasTransitionProperty") ) { hasTransitionProperty=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"hasPropertiesToCascade") ) { hasPropertiesToCascade=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CascadeManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hasOutlineColor"));
	outFields->push(HX_CSTRING("hasOutlineStyle"));
	outFields->push(HX_CSTRING("hasBottomBorderColor"));
	outFields->push(HX_CSTRING("hasTopBorderColor"));
	outFields->push(HX_CSTRING("hasRightBorderColor"));
	outFields->push(HX_CSTRING("hasLeftBorderColor"));
	outFields->push(HX_CSTRING("hasBottomBorderStyle"));
	outFields->push(HX_CSTRING("hasTopBorderStyle"));
	outFields->push(HX_CSTRING("hasRightBorderStyle"));
	outFields->push(HX_CSTRING("hasLeftBorderStyle"));
	outFields->push(HX_CSTRING("hasTransitionProperty"));
	outFields->push(HX_CSTRING("hasMarginBottom"));
	outFields->push(HX_CSTRING("hasMarginRight"));
	outFields->push(HX_CSTRING("hasMarginTop"));
	outFields->push(HX_CSTRING("hasMarginLeft"));
	outFields->push(HX_CSTRING("hasRight"));
	outFields->push(HX_CSTRING("hasLeft"));
	outFields->push(HX_CSTRING("hasBottom"));
	outFields->push(HX_CSTRING("hasTop"));
	outFields->push(HX_CSTRING("hasTextAlign"));
	outFields->push(HX_CSTRING("hasMaxWidth"));
	outFields->push(HX_CSTRING("hasMaxHeight"));
	outFields->push(HX_CSTRING("hasHeight"));
	outFields->push(HX_CSTRING("hasWidth"));
	outFields->push(HX_CSTRING("hasWhiteSpace"));
	outFields->push(HX_CSTRING("hasClear"));
	outFields->push(HX_CSTRING("hasVerticalAlign"));
	outFields->push(HX_CSTRING("hasBackgroundImage"));
	outFields->push(HX_CSTRING("hasOpacity"));
	outFields->push(HX_CSTRING("hasVisible"));
	outFields->push(HX_CSTRING("hasPosition"));
	outFields->push(HX_CSTRING("hasZIndex"));
	outFields->push(HX_CSTRING("hasTransform"));
	outFields->push(HX_CSTRING("hasOverflowY"));
	outFields->push(HX_CSTRING("hasOverflowX"));
	outFields->push(HX_CSTRING("hasFloat"));
	outFields->push(HX_CSTRING("hasLetterSpacing"));
	outFields->push(HX_CSTRING("hasLineHeight"));
	outFields->push(HX_CSTRING("hasDisplay"));
	outFields->push(HX_CSTRING("hasColor"));
	outFields->push(HX_CSTRING("hasBackgroundColor"));
	outFields->push(HX_CSTRING("hasFontFamily"));
	outFields->push(HX_CSTRING("hasFontSize"));
	outFields->push(HX_CSTRING("hasPropertiesToCascade"));
	outFields->push(HX_CSTRING("cascadeAll"));
	outFields->push(HX_CSTRING("propertiesToCascade"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unFlagProperty"),
	HX_CSTRING("flagProperty"),
	HX_CSTRING("shouldCascadeAll"),
	HX_CSTRING("removePropertyToCascade"),
	HX_CSTRING("addPropertyToCascade"),
	HX_CSTRING("reset"),
	HX_CSTRING("hasOutlineColor"),
	HX_CSTRING("hasOutlineStyle"),
	HX_CSTRING("hasBottomBorderColor"),
	HX_CSTRING("hasTopBorderColor"),
	HX_CSTRING("hasRightBorderColor"),
	HX_CSTRING("hasLeftBorderColor"),
	HX_CSTRING("hasBottomBorderStyle"),
	HX_CSTRING("hasTopBorderStyle"),
	HX_CSTRING("hasRightBorderStyle"),
	HX_CSTRING("hasLeftBorderStyle"),
	HX_CSTRING("hasTransitionProperty"),
	HX_CSTRING("hasMarginBottom"),
	HX_CSTRING("hasMarginRight"),
	HX_CSTRING("hasMarginTop"),
	HX_CSTRING("hasMarginLeft"),
	HX_CSTRING("hasRight"),
	HX_CSTRING("hasLeft"),
	HX_CSTRING("hasBottom"),
	HX_CSTRING("hasTop"),
	HX_CSTRING("hasTextAlign"),
	HX_CSTRING("hasMaxWidth"),
	HX_CSTRING("hasMaxHeight"),
	HX_CSTRING("hasHeight"),
	HX_CSTRING("hasWidth"),
	HX_CSTRING("hasWhiteSpace"),
	HX_CSTRING("hasClear"),
	HX_CSTRING("hasVerticalAlign"),
	HX_CSTRING("hasBackgroundImage"),
	HX_CSTRING("hasOpacity"),
	HX_CSTRING("hasVisible"),
	HX_CSTRING("hasPosition"),
	HX_CSTRING("hasZIndex"),
	HX_CSTRING("hasTransform"),
	HX_CSTRING("hasOverflowY"),
	HX_CSTRING("hasOverflowX"),
	HX_CSTRING("hasFloat"),
	HX_CSTRING("hasLetterSpacing"),
	HX_CSTRING("hasLineHeight"),
	HX_CSTRING("hasDisplay"),
	HX_CSTRING("hasColor"),
	HX_CSTRING("hasBackgroundColor"),
	HX_CSTRING("hasFontFamily"),
	HX_CSTRING("hasFontSize"),
	HX_CSTRING("hasPropertiesToCascade"),
	HX_CSTRING("cascadeAll"),
	HX_CSTRING("propertiesToCascade"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CascadeManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CascadeManager_obj::__mClass,"__mClass");
};

Class CascadeManager_obj::__mClass;

void CascadeManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CascadeManager"), hx::TCanCast< CascadeManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CascadeManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
