#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_MatchedPseudoClassesVO
#include <cocktail/core/css/MatchedPseudoClassesVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void MatchedPseudoClassesVO_obj::__construct(bool hover,bool focus,bool active,bool link,bool enabled,bool disabled,bool checked,bool hasId,bool hasClasses,::String nodeId,Array< ::String > nodeClassList,::String nodeType)
{
HX_STACK_PUSH("MatchedPseudoClassesVO::new","cocktail/core/css/CSSData.hx",116);
{
	HX_STACK_LINE(117)
	this->hover = hover;
	HX_STACK_LINE(118)
	this->focus = focus;
	HX_STACK_LINE(119)
	this->active = active;
	HX_STACK_LINE(120)
	this->link = link;
	HX_STACK_LINE(121)
	this->enabled = enabled;
	HX_STACK_LINE(122)
	this->disabled = disabled;
	HX_STACK_LINE(123)
	this->checked = checked;
	HX_STACK_LINE(124)
	this->hasId = hasId;
	HX_STACK_LINE(125)
	this->hasClasses = false;
	HX_STACK_LINE(126)
	this->nodeId = nodeId;
	HX_STACK_LINE(127)
	this->nodeClassList = nodeClassList;
	HX_STACK_LINE(128)
	this->nodeType = nodeType;
}
;
	return null();
}

MatchedPseudoClassesVO_obj::~MatchedPseudoClassesVO_obj() { }

Dynamic MatchedPseudoClassesVO_obj::__CreateEmpty() { return  new MatchedPseudoClassesVO_obj; }
hx::ObjectPtr< MatchedPseudoClassesVO_obj > MatchedPseudoClassesVO_obj::__new(bool hover,bool focus,bool active,bool link,bool enabled,bool disabled,bool checked,bool hasId,bool hasClasses,::String nodeId,Array< ::String > nodeClassList,::String nodeType)
{  hx::ObjectPtr< MatchedPseudoClassesVO_obj > result = new MatchedPseudoClassesVO_obj();
	result->__construct(hover,focus,active,link,enabled,disabled,checked,hasId,hasClasses,nodeId,nodeClassList,nodeType);
	return result;}

Dynamic MatchedPseudoClassesVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MatchedPseudoClassesVO_obj > result = new MatchedPseudoClassesVO_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11]);
	return result;}


MatchedPseudoClassesVO_obj::MatchedPseudoClassesVO_obj()
{
}

void MatchedPseudoClassesVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MatchedPseudoClassesVO);
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(nodeClassList,"nodeClassList");
	HX_MARK_MEMBER_NAME(hasClasses,"hasClasses");
	HX_MARK_MEMBER_NAME(nodeId,"nodeId");
	HX_MARK_MEMBER_NAME(hasId,"hasId");
	HX_MARK_MEMBER_NAME(checked,"checked");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(link,"link");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(focus,"focus");
	HX_MARK_MEMBER_NAME(hover,"hover");
	HX_MARK_END_CLASS();
}

void MatchedPseudoClassesVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nodeType,"nodeType");
	HX_VISIT_MEMBER_NAME(nodeClassList,"nodeClassList");
	HX_VISIT_MEMBER_NAME(hasClasses,"hasClasses");
	HX_VISIT_MEMBER_NAME(nodeId,"nodeId");
	HX_VISIT_MEMBER_NAME(hasId,"hasId");
	HX_VISIT_MEMBER_NAME(checked,"checked");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(link,"link");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(focus,"focus");
	HX_VISIT_MEMBER_NAME(hover,"hover");
}

Dynamic MatchedPseudoClassesVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"link") ) { return link; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"hasId") ) { return hasId; }
		if (HX_FIELD_EQ(inName,"focus") ) { return focus; }
		if (HX_FIELD_EQ(inName,"hover") ) { return hover; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"nodeId") ) { return nodeId; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"checked") ) { return checked; }
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { return nodeType; }
		if (HX_FIELD_EQ(inName,"disabled") ) { return disabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasClasses") ) { return hasClasses; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nodeClassList") ) { return nodeClassList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MatchedPseudoClassesVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"link") ) { link=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"hasId") ) { hasId=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"focus") ) { focus=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hover") ) { hover=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"nodeId") ) { nodeId=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"checked") ) { checked=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disabled") ) { disabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasClasses") ) { hasClasses=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nodeClassList") ) { nodeClassList=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MatchedPseudoClassesVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nodeType"));
	outFields->push(HX_CSTRING("nodeClassList"));
	outFields->push(HX_CSTRING("hasClasses"));
	outFields->push(HX_CSTRING("nodeId"));
	outFields->push(HX_CSTRING("hasId"));
	outFields->push(HX_CSTRING("checked"));
	outFields->push(HX_CSTRING("disabled"));
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("link"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("focus"));
	outFields->push(HX_CSTRING("hover"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nodeType"),
	HX_CSTRING("nodeClassList"),
	HX_CSTRING("hasClasses"),
	HX_CSTRING("nodeId"),
	HX_CSTRING("hasId"),
	HX_CSTRING("checked"),
	HX_CSTRING("disabled"),
	HX_CSTRING("enabled"),
	HX_CSTRING("link"),
	HX_CSTRING("active"),
	HX_CSTRING("focus"),
	HX_CSTRING("hover"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MatchedPseudoClassesVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MatchedPseudoClassesVO_obj::__mClass,"__mClass");
};

Class MatchedPseudoClassesVO_obj::__mClass;

void MatchedPseudoClassesVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.MatchedPseudoClassesVO"), hx::TCanCast< MatchedPseudoClassesVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MatchedPseudoClassesVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
