#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
namespace cocktail{
namespace core{
namespace font{

Void FontMetricsVO_obj::__construct(Float fontSize,Float ascent,Float descent,Float xHeight,Float subscriptOffset,Float superscriptOffset,Float underlineOffset,Float spaceWidth)
{
HX_STACK_PUSH("FontMetricsVO::new","cocktail/core/font/FontData.hx",81);
{
	HX_STACK_LINE(82)
	this->fontSize = fontSize;
	HX_STACK_LINE(83)
	this->ascent = ascent;
	HX_STACK_LINE(84)
	this->descent = descent;
	HX_STACK_LINE(85)
	this->xHeight = xHeight;
	HX_STACK_LINE(86)
	this->subscriptOffset = subscriptOffset;
	HX_STACK_LINE(87)
	this->superscriptOffset = superscriptOffset;
	HX_STACK_LINE(88)
	this->underlineOffset = underlineOffset;
	HX_STACK_LINE(89)
	this->spaceWidth = spaceWidth;
}
;
	return null();
}

FontMetricsVO_obj::~FontMetricsVO_obj() { }

Dynamic FontMetricsVO_obj::__CreateEmpty() { return  new FontMetricsVO_obj; }
hx::ObjectPtr< FontMetricsVO_obj > FontMetricsVO_obj::__new(Float fontSize,Float ascent,Float descent,Float xHeight,Float subscriptOffset,Float superscriptOffset,Float underlineOffset,Float spaceWidth)
{  hx::ObjectPtr< FontMetricsVO_obj > result = new FontMetricsVO_obj();
	result->__construct(fontSize,ascent,descent,xHeight,subscriptOffset,superscriptOffset,underlineOffset,spaceWidth);
	return result;}

Dynamic FontMetricsVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontMetricsVO_obj > result = new FontMetricsVO_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}


FontMetricsVO_obj::FontMetricsVO_obj()
{
}

void FontMetricsVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontMetricsVO);
	HX_MARK_MEMBER_NAME(spaceWidth,"spaceWidth");
	HX_MARK_MEMBER_NAME(underlineOffset,"underlineOffset");
	HX_MARK_MEMBER_NAME(superscriptOffset,"superscriptOffset");
	HX_MARK_MEMBER_NAME(subscriptOffset,"subscriptOffset");
	HX_MARK_MEMBER_NAME(xHeight,"xHeight");
	HX_MARK_MEMBER_NAME(descent,"descent");
	HX_MARK_MEMBER_NAME(ascent,"ascent");
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_END_CLASS();
}

void FontMetricsVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(spaceWidth,"spaceWidth");
	HX_VISIT_MEMBER_NAME(underlineOffset,"underlineOffset");
	HX_VISIT_MEMBER_NAME(superscriptOffset,"superscriptOffset");
	HX_VISIT_MEMBER_NAME(subscriptOffset,"subscriptOffset");
	HX_VISIT_MEMBER_NAME(xHeight,"xHeight");
	HX_VISIT_MEMBER_NAME(descent,"descent");
	HX_VISIT_MEMBER_NAME(ascent,"ascent");
	HX_VISIT_MEMBER_NAME(fontSize,"fontSize");
}

Dynamic FontMetricsVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"ascent") ) { return ascent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"xHeight") ) { return xHeight; }
		if (HX_FIELD_EQ(inName,"descent") ) { return descent; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fontSize") ) { return fontSize; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"spaceWidth") ) { return spaceWidth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"underlineOffset") ) { return underlineOffset; }
		if (HX_FIELD_EQ(inName,"subscriptOffset") ) { return subscriptOffset; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"superscriptOffset") ) { return superscriptOffset; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FontMetricsVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"ascent") ) { ascent=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"xHeight") ) { xHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"descent") ) { descent=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fontSize") ) { fontSize=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"spaceWidth") ) { spaceWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"underlineOffset") ) { underlineOffset=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"subscriptOffset") ) { subscriptOffset=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"superscriptOffset") ) { superscriptOffset=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FontMetricsVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("spaceWidth"));
	outFields->push(HX_CSTRING("underlineOffset"));
	outFields->push(HX_CSTRING("superscriptOffset"));
	outFields->push(HX_CSTRING("subscriptOffset"));
	outFields->push(HX_CSTRING("xHeight"));
	outFields->push(HX_CSTRING("descent"));
	outFields->push(HX_CSTRING("ascent"));
	outFields->push(HX_CSTRING("fontSize"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("spaceWidth"),
	HX_CSTRING("underlineOffset"),
	HX_CSTRING("superscriptOffset"),
	HX_CSTRING("subscriptOffset"),
	HX_CSTRING("xHeight"),
	HX_CSTRING("descent"),
	HX_CSTRING("ascent"),
	HX_CSTRING("fontSize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontMetricsVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FontMetricsVO_obj::__mClass,"__mClass");
};

Class FontMetricsVO_obj::__mClass;

void FontMetricsVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.FontMetricsVO"), hx::TCanCast< FontMetricsVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FontMetricsVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace font
