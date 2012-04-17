#include <hxcpp.h>

#ifndef INCLUDED_hxtml_Token
#include <hxtml/Token.h>
#endif
namespace hxtml{

::hxtml::Token Token_obj::TBrClose;

::hxtml::Token Token_obj::TBrOpen;

::hxtml::Token Token_obj::TComma;

::hxtml::Token Token_obj::TDblDot;

::hxtml::Token Token_obj::TDot;

::hxtml::Token Token_obj::TEof;

::hxtml::Token Token_obj::TExclam;

::hxtml::Token  Token_obj::TFloat(double f)
	{ return hx::CreateEnum< Token_obj >(HX_CSTRING("TFloat"),3,hx::DynamicArray(0,1).Add(f)); }

::hxtml::Token  Token_obj::TIdent(::String i)
	{ return hx::CreateEnum< Token_obj >(HX_CSTRING("TIdent"),0,hx::DynamicArray(0,1).Add(i)); }

::hxtml::Token  Token_obj::TInt(int i)
	{ return hx::CreateEnum< Token_obj >(HX_CSTRING("TInt"),2,hx::DynamicArray(0,1).Add(i)); }

::hxtml::Token Token_obj::TPClose;

::hxtml::Token Token_obj::TPOpen;

::hxtml::Token Token_obj::TPercent;

::hxtml::Token Token_obj::TSemicolon;

::hxtml::Token Token_obj::TSharp;

::hxtml::Token Token_obj::TSlash;

::hxtml::Token Token_obj::TSpaces;

::hxtml::Token  Token_obj::TString(::String s)
	{ return hx::CreateEnum< Token_obj >(HX_CSTRING("TString"),1,hx::DynamicArray(0,1).Add(s)); }

HX_DEFINE_CREATE_ENUM(Token_obj)

int Token_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("TBrClose")) return 14;
	if (inName==HX_CSTRING("TBrOpen")) return 13;
	if (inName==HX_CSTRING("TComma")) return 9;
	if (inName==HX_CSTRING("TDblDot")) return 4;
	if (inName==HX_CSTRING("TDot")) return 15;
	if (inName==HX_CSTRING("TEof")) return 10;
	if (inName==HX_CSTRING("TExclam")) return 8;
	if (inName==HX_CSTRING("TFloat")) return 3;
	if (inName==HX_CSTRING("TIdent")) return 0;
	if (inName==HX_CSTRING("TInt")) return 2;
	if (inName==HX_CSTRING("TPClose")) return 7;
	if (inName==HX_CSTRING("TPOpen")) return 6;
	if (inName==HX_CSTRING("TPercent")) return 11;
	if (inName==HX_CSTRING("TSemicolon")) return 12;
	if (inName==HX_CSTRING("TSharp")) return 5;
	if (inName==HX_CSTRING("TSlash")) return 17;
	if (inName==HX_CSTRING("TSpaces")) return 16;
	if (inName==HX_CSTRING("TString")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TFloat,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TIdent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TInt,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TString,return)

int Token_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("TBrClose")) return 0;
	if (inName==HX_CSTRING("TBrOpen")) return 0;
	if (inName==HX_CSTRING("TComma")) return 0;
	if (inName==HX_CSTRING("TDblDot")) return 0;
	if (inName==HX_CSTRING("TDot")) return 0;
	if (inName==HX_CSTRING("TEof")) return 0;
	if (inName==HX_CSTRING("TExclam")) return 0;
	if (inName==HX_CSTRING("TFloat")) return 1;
	if (inName==HX_CSTRING("TIdent")) return 1;
	if (inName==HX_CSTRING("TInt")) return 1;
	if (inName==HX_CSTRING("TPClose")) return 0;
	if (inName==HX_CSTRING("TPOpen")) return 0;
	if (inName==HX_CSTRING("TPercent")) return 0;
	if (inName==HX_CSTRING("TSemicolon")) return 0;
	if (inName==HX_CSTRING("TSharp")) return 0;
	if (inName==HX_CSTRING("TSlash")) return 0;
	if (inName==HX_CSTRING("TSpaces")) return 0;
	if (inName==HX_CSTRING("TString")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Token_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("TBrClose")) return TBrClose;
	if (inName==HX_CSTRING("TBrOpen")) return TBrOpen;
	if (inName==HX_CSTRING("TComma")) return TComma;
	if (inName==HX_CSTRING("TDblDot")) return TDblDot;
	if (inName==HX_CSTRING("TDot")) return TDot;
	if (inName==HX_CSTRING("TEof")) return TEof;
	if (inName==HX_CSTRING("TExclam")) return TExclam;
	if (inName==HX_CSTRING("TFloat")) return TFloat_dyn();
	if (inName==HX_CSTRING("TIdent")) return TIdent_dyn();
	if (inName==HX_CSTRING("TInt")) return TInt_dyn();
	if (inName==HX_CSTRING("TPClose")) return TPClose;
	if (inName==HX_CSTRING("TPOpen")) return TPOpen;
	if (inName==HX_CSTRING("TPercent")) return TPercent;
	if (inName==HX_CSTRING("TSemicolon")) return TSemicolon;
	if (inName==HX_CSTRING("TSharp")) return TSharp;
	if (inName==HX_CSTRING("TSlash")) return TSlash;
	if (inName==HX_CSTRING("TSpaces")) return TSpaces;
	if (inName==HX_CSTRING("TString")) return TString_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("TIdent"),
	HX_CSTRING("TString"),
	HX_CSTRING("TInt"),
	HX_CSTRING("TFloat"),
	HX_CSTRING("TDblDot"),
	HX_CSTRING("TSharp"),
	HX_CSTRING("TPOpen"),
	HX_CSTRING("TPClose"),
	HX_CSTRING("TExclam"),
	HX_CSTRING("TComma"),
	HX_CSTRING("TEof"),
	HX_CSTRING("TPercent"),
	HX_CSTRING("TSemicolon"),
	HX_CSTRING("TBrOpen"),
	HX_CSTRING("TBrClose"),
	HX_CSTRING("TDot"),
	HX_CSTRING("TSpaces"),
	HX_CSTRING("TSlash"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Token_obj::TBrClose,"TBrClose");
	HX_MARK_MEMBER_NAME(Token_obj::TBrOpen,"TBrOpen");
	HX_MARK_MEMBER_NAME(Token_obj::TComma,"TComma");
	HX_MARK_MEMBER_NAME(Token_obj::TDblDot,"TDblDot");
	HX_MARK_MEMBER_NAME(Token_obj::TDot,"TDot");
	HX_MARK_MEMBER_NAME(Token_obj::TEof,"TEof");
	HX_MARK_MEMBER_NAME(Token_obj::TExclam,"TExclam");
	HX_MARK_MEMBER_NAME(Token_obj::TPClose,"TPClose");
	HX_MARK_MEMBER_NAME(Token_obj::TPOpen,"TPOpen");
	HX_MARK_MEMBER_NAME(Token_obj::TPercent,"TPercent");
	HX_MARK_MEMBER_NAME(Token_obj::TSemicolon,"TSemicolon");
	HX_MARK_MEMBER_NAME(Token_obj::TSharp,"TSharp");
	HX_MARK_MEMBER_NAME(Token_obj::TSlash,"TSlash");
	HX_MARK_MEMBER_NAME(Token_obj::TSpaces,"TSpaces");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Token_obj::__mClass;

Dynamic __Create_Token_obj() { return new Token_obj; }

void Token_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxtml.Token"), hx::TCanCast< Token_obj >,sStaticFields,sMemberFields,
	&__Create_Token_obj, &__Create,
	&super::__SGetClass(), &CreateToken_obj, sMarkStatics);
}

void Token_obj::__boot()
{
Static(TBrClose) = hx::CreateEnum< Token_obj >(HX_CSTRING("TBrClose"),14);
Static(TBrOpen) = hx::CreateEnum< Token_obj >(HX_CSTRING("TBrOpen"),13);
Static(TComma) = hx::CreateEnum< Token_obj >(HX_CSTRING("TComma"),9);
Static(TDblDot) = hx::CreateEnum< Token_obj >(HX_CSTRING("TDblDot"),4);
Static(TDot) = hx::CreateEnum< Token_obj >(HX_CSTRING("TDot"),15);
Static(TEof) = hx::CreateEnum< Token_obj >(HX_CSTRING("TEof"),10);
Static(TExclam) = hx::CreateEnum< Token_obj >(HX_CSTRING("TExclam"),8);
Static(TPClose) = hx::CreateEnum< Token_obj >(HX_CSTRING("TPClose"),7);
Static(TPOpen) = hx::CreateEnum< Token_obj >(HX_CSTRING("TPOpen"),6);
Static(TPercent) = hx::CreateEnum< Token_obj >(HX_CSTRING("TPercent"),11);
Static(TSemicolon) = hx::CreateEnum< Token_obj >(HX_CSTRING("TSemicolon"),12);
Static(TSharp) = hx::CreateEnum< Token_obj >(HX_CSTRING("TSharp"),5);
Static(TSlash) = hx::CreateEnum< Token_obj >(HX_CSTRING("TSlash"),17);
Static(TSpaces) = hx::CreateEnum< Token_obj >(HX_CSTRING("TSpaces"),16);
}


} // end namespace hxtml
