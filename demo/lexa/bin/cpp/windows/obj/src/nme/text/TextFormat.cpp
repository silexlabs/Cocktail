#include <hxcpp.h>

#ifndef INCLUDED_nme_text_TextFormat
#include <nme/text/TextFormat.h>
#endif
namespace nme{
namespace text{

Void TextFormat_obj::__construct(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",31)
	this->font = in_font;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",32)
	this->size = in_size;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",33)
	this->color = in_color;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",34)
	this->bold = in_bold;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",35)
	this->italic = in_italic;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",36)
	this->underline = in_underline;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",37)
	this->url = in_url;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",38)
	this->target = in_target;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",39)
	this->align = in_align;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",40)
	this->leftMargin = in_leftMargin;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",41)
	this->rightMargin = in_rightMargin;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",42)
	this->indent = in_indent;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextFormat.hx",43)
	this->leading = in_leading;
}
;
	return null();
}

TextFormat_obj::~TextFormat_obj() { }

Dynamic TextFormat_obj::__CreateEmpty() { return  new TextFormat_obj; }
hx::ObjectPtr< TextFormat_obj > TextFormat_obj::__new(::String in_font,Dynamic in_size,Dynamic in_color,Dynamic in_bold,Dynamic in_italic,Dynamic in_underline,::String in_url,::String in_target,::String in_align,Dynamic in_leftMargin,Dynamic in_rightMargin,Dynamic in_indent,Dynamic in_leading)
{  hx::ObjectPtr< TextFormat_obj > result = new TextFormat_obj();
	result->__construct(in_font,in_size,in_color,in_bold,in_italic,in_underline,in_url,in_target,in_align,in_leftMargin,in_rightMargin,in_indent,in_leading);
	return result;}

Dynamic TextFormat_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextFormat_obj > result = new TextFormat_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12]);
	return result;}


TextFormat_obj::TextFormat_obj()
{
}

void TextFormat_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextFormat);
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_MEMBER_NAME(blockIndent,"blockIndent");
	HX_MARK_MEMBER_NAME(bold,"bold");
	HX_MARK_MEMBER_NAME(bullet,"bullet");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_MEMBER_NAME(indent,"indent");
	HX_MARK_MEMBER_NAME(italic,"italic");
	HX_MARK_MEMBER_NAME(kerning,"kerning");
	HX_MARK_MEMBER_NAME(leading,"leading");
	HX_MARK_MEMBER_NAME(leftMargin,"leftMargin");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(rightMargin,"rightMargin");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(tabStops,"tabStops");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(underline,"underline");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_END_CLASS();
}

Dynamic TextFormat_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { return bold; }
		if (HX_FIELD_EQ(inName,"font") ) { return font; }
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return align; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { return bullet; }
		if (HX_FIELD_EQ(inName,"indent") ) { return indent; }
		if (HX_FIELD_EQ(inName,"italic") ) { return italic; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return display; }
		if (HX_FIELD_EQ(inName,"kerning") ) { return kerning; }
		if (HX_FIELD_EQ(inName,"leading") ) { return leading; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tabStops") ) { return tabStops; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"underline") ) { return underline; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"leftMargin") ) { return leftMargin; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"blockIndent") ) { return blockIndent; }
		if (HX_FIELD_EQ(inName,"rightMargin") ) { return rightMargin; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return letterSpacing; }
	}
	return super::__Field(inName);
}

Dynamic TextFormat_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { bold=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"font") ) { font=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { align=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { bullet=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indent") ) { indent=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"italic") ) { italic=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { display=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"kerning") ) { kerning=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"leading") ) { leading=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tabStops") ) { tabStops=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"underline") ) { underline=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"leftMargin") ) { leftMargin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"blockIndent") ) { blockIndent=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightMargin") ) { rightMargin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { letterSpacing=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("align"));
	outFields->push(HX_CSTRING("blockIndent"));
	outFields->push(HX_CSTRING("bold"));
	outFields->push(HX_CSTRING("bullet"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("font"));
	outFields->push(HX_CSTRING("indent"));
	outFields->push(HX_CSTRING("italic"));
	outFields->push(HX_CSTRING("kerning"));
	outFields->push(HX_CSTRING("leading"));
	outFields->push(HX_CSTRING("leftMargin"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("rightMargin"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("tabStops"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("underline"));
	outFields->push(HX_CSTRING("url"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("align"),
	HX_CSTRING("blockIndent"),
	HX_CSTRING("bold"),
	HX_CSTRING("bullet"),
	HX_CSTRING("color"),
	HX_CSTRING("display"),
	HX_CSTRING("font"),
	HX_CSTRING("indent"),
	HX_CSTRING("italic"),
	HX_CSTRING("kerning"),
	HX_CSTRING("leading"),
	HX_CSTRING("leftMargin"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("rightMargin"),
	HX_CSTRING("size"),
	HX_CSTRING("tabStops"),
	HX_CSTRING("target"),
	HX_CSTRING("underline"),
	HX_CSTRING("url"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TextFormat_obj::__mClass;

void TextFormat_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.text.TextFormat"), hx::TCanCast< TextFormat_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextFormat_obj::__boot()
{
}

} // end namespace nme
} // end namespace text
