#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_layout_FloatVO
#include <cocktail/core/layout/FloatVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_FloatsVO
#include <cocktail/core/layout/FloatsVO.h>
#endif
namespace cocktail{
namespace core{
namespace layout{

Void FloatsVO_obj::__construct(Array< ::cocktail::core::layout::FloatVO > left,Array< ::cocktail::core::layout::FloatVO > right)
{
HX_STACK_PUSH("FloatsVO::new","cocktail/core/layout/LayoutData.hx",162);
{
	HX_STACK_LINE(163)
	this->left = left;
	HX_STACK_LINE(164)
	this->right = right;
}
;
	return null();
}

FloatsVO_obj::~FloatsVO_obj() { }

Dynamic FloatsVO_obj::__CreateEmpty() { return  new FloatsVO_obj; }
hx::ObjectPtr< FloatsVO_obj > FloatsVO_obj::__new(Array< ::cocktail::core::layout::FloatVO > left,Array< ::cocktail::core::layout::FloatVO > right)
{  hx::ObjectPtr< FloatsVO_obj > result = new FloatsVO_obj();
	result->__construct(left,right);
	return result;}

Dynamic FloatsVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatsVO_obj > result = new FloatsVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FloatsVO_obj::FloatsVO_obj()
{
}

void FloatsVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatsVO);
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_END_CLASS();
}

void FloatsVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(right,"right");
	HX_VISIT_MEMBER_NAME(left,"left");
}

Dynamic FloatsVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return right; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatsVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { left=inValue.Cast< Array< ::cocktail::core::layout::FloatVO > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { right=inValue.Cast< Array< ::cocktail::core::layout::FloatVO > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatsVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("left"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("right"),
	HX_CSTRING("left"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatsVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatsVO_obj::__mClass,"__mClass");
};

Class FloatsVO_obj::__mClass;

void FloatsVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.FloatsVO"), hx::TCanCast< FloatsVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FloatsVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
