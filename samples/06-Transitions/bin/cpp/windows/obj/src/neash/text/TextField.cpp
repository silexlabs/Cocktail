#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_AntiAliasType
#include <neash/text/AntiAliasType.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
#ifndef INCLUDED_neash_text_TextFieldAutoSize
#include <neash/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_neash_text_TextFieldType
#include <neash/text/TextFieldType.h>
#endif
#ifndef INCLUDED_neash_text_TextFormat
#include <neash/text/TextFormat.h>
#endif
namespace neash{
namespace text{

Void TextField_obj::__construct()
{
HX_STACK_PUSH("TextField::new","neash/text/TextField.hx",40);
{
	HX_STACK_LINE(41)
	Dynamic handle = ::neash::text::TextField_obj::nme_text_field_create();		HX_STACK_VAR(handle,"handle");
	HX_STACK_LINE(42)
	super::__construct(handle,HX_CSTRING("TextField"));
}
;
	return null();
}

TextField_obj::~TextField_obj() { }

Dynamic TextField_obj::__CreateEmpty() { return  new TextField_obj; }
hx::ObjectPtr< TextField_obj > TextField_obj::__new()
{  hx::ObjectPtr< TextField_obj > result = new TextField_obj();
	result->__construct();
	return result;}

Dynamic TextField_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextField_obj > result = new TextField_obj();
	result->__construct();
	return result;}

bool TextField_obj::nmeSetWordWrap( bool inVal){
	HX_STACK_PUSH("TextField::nmeSetWordWrap","neash/text/TextField.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(120)
	::neash::text::TextField_obj::nme_text_field_set_word_wrap(this->nmeHandle,inVal);
	HX_STACK_LINE(120)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetWordWrap,return )

bool TextField_obj::nmeGetWordWrap( ){
	HX_STACK_PUSH("TextField::nmeGetWordWrap","neash/text/TextField.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_LINE(119)
	return ::neash::text::TextField_obj::nme_text_field_get_word_wrap(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetWordWrap,return )

::neash::text::TextFieldType TextField_obj::nmeSetType( ::neash::text::TextFieldType inType){
	HX_STACK_PUSH("TextField::nmeSetType","neash/text/TextField.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inType,"inType");
	HX_STACK_LINE(118)
	::neash::text::TextField_obj::nme_text_field_set_type(this->nmeHandle,(inType == ::neash::text::TextFieldType_obj::INPUT_dyn()));
	HX_STACK_LINE(118)
	return inType;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetType,return )

::neash::text::TextFieldType TextField_obj::nmeGetType( ){
	HX_STACK_PUSH("TextField::nmeGetType","neash/text/TextField.hx",117);
	HX_STACK_THIS(this);
	HX_STACK_LINE(117)
	return (  ((::neash::text::TextField_obj::nme_text_field_get_type(this->nmeHandle))) ? ::neash::text::TextFieldType(::neash::text::TextFieldType_obj::INPUT_dyn()) : ::neash::text::TextFieldType(::neash::text::TextFieldType_obj::DYNAMIC_dyn()) );
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetType,return )

Float TextField_obj::nmeGetTextHeight( ){
	HX_STACK_PUSH("TextField::nmeGetTextHeight","neash/text/TextField.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_LINE(116)
	return ::neash::text::TextField_obj::nme_text_field_get_text_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextHeight,return )

Float TextField_obj::nmeGetTextWidth( ){
	HX_STACK_PUSH("TextField::nmeGetTextWidth","neash/text/TextField.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return ::neash::text::TextField_obj::nme_text_field_get_text_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextWidth,return )

int TextField_obj::nmeSetTextColor( int inCol){
	HX_STACK_PUSH("TextField::nmeSetTextColor","neash/text/TextField.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inCol,"inCol");
	HX_STACK_LINE(114)
	::neash::text::TextField_obj::nme_text_field_set_text_color(this->nmeHandle,inCol);
	HX_STACK_LINE(114)
	return inCol;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetTextColor,return )

int TextField_obj::nmeGetTextColor( ){
	HX_STACK_PUSH("TextField::nmeGetTextColor","neash/text/TextField.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(113)
	return ::neash::text::TextField_obj::nme_text_field_get_text_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextColor,return )

::String TextField_obj::nmeSetText( ::String inText){
	HX_STACK_PUSH("TextField::nmeSetText","neash/text/TextField.hx",112);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inText,"inText");
	HX_STACK_LINE(112)
	::neash::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,inText);
	HX_STACK_LINE(112)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetText,return )

::String TextField_obj::nmeGetText( ){
	HX_STACK_PUSH("TextField::nmeGetText","neash/text/TextField.hx",111);
	HX_STACK_THIS(this);
	HX_STACK_LINE(111)
	return ::neash::text::TextField_obj::nme_text_field_get_text(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetText,return )

bool TextField_obj::nmeSetSelectable( bool inSel){
	HX_STACK_PUSH("TextField::nmeSetSelectable","neash/text/TextField.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inSel,"inSel");
	HX_STACK_LINE(110)
	::neash::text::TextField_obj::nme_text_field_set_selectable(this->nmeHandle,inSel);
	HX_STACK_LINE(110)
	return inSel;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetSelectable,return )

bool TextField_obj::nmeGetSelectable( ){
	HX_STACK_PUSH("TextField::nmeGetSelectable","neash/text/TextField.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(109)
	return ::neash::text::TextField_obj::nme_text_field_get_selectable(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetSelectable,return )

int TextField_obj::nmeSetScrollV( int inVal){
	HX_STACK_PUSH("TextField::nmeSetScrollV","neash/text/TextField.hx",108);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(108)
	::neash::text::TextField_obj::nme_text_field_set_scroll_v(this->nmeHandle,inVal);
	HX_STACK_LINE(108)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetScrollV,return )

int TextField_obj::nmeGetScrollV( ){
	HX_STACK_PUSH("TextField::nmeGetScrollV","neash/text/TextField.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_LINE(107)
	return ::neash::text::TextField_obj::nme_text_field_get_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetScrollV,return )

int TextField_obj::nmeSetScrollH( int inVal){
	HX_STACK_PUSH("TextField::nmeSetScrollH","neash/text/TextField.hx",106);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(106)
	::neash::text::TextField_obj::nme_text_field_set_scroll_h(this->nmeHandle,inVal);
	HX_STACK_LINE(106)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetScrollH,return )

int TextField_obj::nmeGetScrollH( ){
	HX_STACK_PUSH("TextField::nmeGetScrollH","neash/text/TextField.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(105)
	return ::neash::text::TextField_obj::nme_text_field_get_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetScrollH,return )

int TextField_obj::nmeGetNumLines( ){
	HX_STACK_PUSH("TextField::nmeGetNumLines","neash/text/TextField.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_LINE(104)
	return ::neash::text::TextField_obj::nme_text_field_get_num_lines(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetNumLines,return )

bool TextField_obj::nmeSetMultiline( bool inVal){
	HX_STACK_PUSH("TextField::nmeSetMultiline","neash/text/TextField.hx",103);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(103)
	::neash::text::TextField_obj::nme_text_field_set_multiline(this->nmeHandle,inVal);
	HX_STACK_LINE(103)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetMultiline,return )

bool TextField_obj::nmeGetMultiline( ){
	HX_STACK_PUSH("TextField::nmeGetMultiline","neash/text/TextField.hx",102);
	HX_STACK_THIS(this);
	HX_STACK_LINE(102)
	return ::neash::text::TextField_obj::nme_text_field_get_multiline(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMultiline,return )

int TextField_obj::nmeGetMaxScrollV( ){
	HX_STACK_PUSH("TextField::nmeGetMaxScrollV","neash/text/TextField.hx",101);
	HX_STACK_THIS(this);
	HX_STACK_LINE(101)
	return ::neash::text::TextField_obj::nme_text_field_get_max_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxScrollV,return )

int TextField_obj::nmeGetMaxScrollH( ){
	HX_STACK_PUSH("TextField::nmeGetMaxScrollH","neash/text/TextField.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(100)
	return ::neash::text::TextField_obj::nme_text_field_get_max_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxScrollH,return )

int TextField_obj::nmeSetMaxChars( int inVal){
	HX_STACK_PUSH("TextField::nmeSetMaxChars","neash/text/TextField.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(99)
	::neash::text::TextField_obj::nme_text_field_set_max_chars(this->nmeHandle,inVal);
	HX_STACK_LINE(99)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetMaxChars,return )

int TextField_obj::nmeGetMaxChars( ){
	HX_STACK_PUSH("TextField::nmeGetMaxChars","neash/text/TextField.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_LINE(98)
	return ::neash::text::TextField_obj::nme_text_field_get_max_chars(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxChars,return )

::String TextField_obj::nmeSetHTMLText( ::String inText){
	HX_STACK_PUSH("TextField::nmeSetHTMLText","neash/text/TextField.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inText,"inText");
	HX_STACK_LINE(97)
	::neash::text::TextField_obj::nme_text_field_set_html_text(this->nmeHandle,inText);
	HX_STACK_LINE(97)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetHTMLText,return )

::String TextField_obj::nmeGetHTMLText( ){
	HX_STACK_PUSH("TextField::nmeGetHTMLText","neash/text/TextField.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_LINE(96)
	return ::StringTools_obj::replace(::neash::text::TextField_obj::nme_text_field_get_html_text(this->nmeHandle),HX_CSTRING("\n"),HX_CSTRING("<br/>"));
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetHTMLText,return )

bool TextField_obj::nmeSetEmbedFonts( bool value){
	HX_STACK_PUSH("TextField::nmeSetEmbedFonts","neash/text/TextField.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(95)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetEmbedFonts,return )

bool TextField_obj::nmeGetEmbedFonts( ){
	HX_STACK_PUSH("TextField::nmeGetEmbedFonts","neash/text/TextField.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_LINE(94)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetEmbedFonts,return )

bool TextField_obj::nmeSetDisplayAsPassword( bool inVal){
	HX_STACK_PUSH("TextField::nmeSetDisplayAsPassword","neash/text/TextField.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(93)
	::neash::text::TextField_obj::nme_text_field_set_display_as_password(this->nmeHandle,inVal);
	HX_STACK_LINE(93)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetDisplayAsPassword,return )

bool TextField_obj::nmeGetDisplayAsPassword( ){
	HX_STACK_PUSH("TextField::nmeGetDisplayAsPassword","neash/text/TextField.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_LINE(92)
	return ::neash::text::TextField_obj::nme_text_field_get_display_as_password(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetDisplayAsPassword,return )

::neash::text::TextFormat TextField_obj::nmeSetDefaultTextFormat( ::neash::text::TextFormat inFormat){
	HX_STACK_PUSH("TextField::nmeSetDefaultTextFormat","neash/text/TextField.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inFormat,"inFormat");
	HX_STACK_LINE(91)
	::neash::text::TextField_obj::nme_text_field_set_def_text_format(this->nmeHandle,inFormat);
	HX_STACK_LINE(91)
	return inFormat;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetDefaultTextFormat,return )

::neash::text::TextFormat TextField_obj::nmeGetDefaultTextFormat( ){
	HX_STACK_PUSH("TextField::nmeGetDefaultTextFormat","neash/text/TextField.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_LINE(90)
	::neash::text::TextFormat result = ::neash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(90)
	::neash::text::TextField_obj::nme_text_field_get_def_text_format(this->nmeHandle,result);
	HX_STACK_LINE(90)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetDefaultTextFormat,return )

int TextField_obj::nmeGetBottomScrollV( ){
	HX_STACK_PUSH("TextField::nmeGetBottomScrollV","neash/text/TextField.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_LINE(89)
	return ::neash::text::TextField_obj::nme_text_field_get_bottom_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBottomScrollV,return )

int TextField_obj::nmeSetBorderColor( int inVal){
	HX_STACK_PUSH("TextField::nmeSetBorderColor","neash/text/TextField.hx",88);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(88)
	::neash::text::TextField_obj::nme_text_field_set_border_color(this->nmeHandle,inVal);
	HX_STACK_LINE(88)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBorderColor,return )

int TextField_obj::nmeGetBorderColor( ){
	HX_STACK_PUSH("TextField::nmeGetBorderColor","neash/text/TextField.hx",87);
	HX_STACK_THIS(this);
	HX_STACK_LINE(87)
	return ::neash::text::TextField_obj::nme_text_field_get_border_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBorderColor,return )

bool TextField_obj::nmeSetBorder( bool inVal){
	HX_STACK_PUSH("TextField::nmeSetBorder","neash/text/TextField.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(86)
	::neash::text::TextField_obj::nme_text_field_set_border(this->nmeHandle,inVal);
	HX_STACK_LINE(86)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBorder,return )

bool TextField_obj::nmeGetBorder( ){
	HX_STACK_PUSH("TextField::nmeGetBorder","neash/text/TextField.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(85)
	return ::neash::text::TextField_obj::nme_text_field_get_border(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBorder,return )

int TextField_obj::nmeSetBackgroundColor( int inVal){
	HX_STACK_PUSH("TextField::nmeSetBackgroundColor","neash/text/TextField.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(84)
	::neash::text::TextField_obj::nme_text_field_set_background_color(this->nmeHandle,inVal);
	HX_STACK_LINE(84)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBackgroundColor,return )

int TextField_obj::nmeGetBackgroundColor( ){
	HX_STACK_PUSH("TextField::nmeGetBackgroundColor","neash/text/TextField.hx",83);
	HX_STACK_THIS(this);
	HX_STACK_LINE(83)
	return ::neash::text::TextField_obj::nme_text_field_get_background_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBackgroundColor,return )

bool TextField_obj::nmeSetBackground( bool inVal){
	HX_STACK_PUSH("TextField::nmeSetBackground","neash/text/TextField.hx",82);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(82)
	::neash::text::TextField_obj::nme_text_field_set_background(this->nmeHandle,inVal);
	HX_STACK_LINE(82)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBackground,return )

bool TextField_obj::nmeGetBackground( ){
	HX_STACK_PUSH("TextField::nmeGetBackground","neash/text/TextField.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_LINE(81)
	return ::neash::text::TextField_obj::nme_text_field_get_background(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBackground,return )

::neash::text::TextFieldAutoSize TextField_obj::nmeSetAutoSize( ::neash::text::TextFieldAutoSize inVal){
	HX_STACK_PUSH("TextField::nmeSetAutoSize","neash/text/TextField.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(80)
	::neash::text::TextField_obj::nme_text_field_set_auto_size(this->nmeHandle,inVal->__Index());
	HX_STACK_LINE(80)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetAutoSize,return )

::neash::text::TextFieldAutoSize TextField_obj::nmeGetAutoSize( ){
	HX_STACK_PUSH("TextField::nmeGetAutoSize","neash/text/TextField.hx",79);
	HX_STACK_THIS(this);
	HX_STACK_LINE(79)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::text::TextFieldAutoSize >(),::neash::text::TextField_obj::nme_text_field_get_auto_size(this->nmeHandle),null());
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetAutoSize,return )

::String TextField_obj::getLineText( int lineIndex){
	HX_STACK_PUSH("TextField::getLineText","neash/text/TextField.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_ARG(lineIndex,"lineIndex");
	HX_STACK_LINE(70)
	return ::neash::text::TextField_obj::nme_text_field_get_line_text(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineText,return )

int TextField_obj::getLineOffset( int lineIndex){
	HX_STACK_PUSH("TextField::getLineOffset","neash/text/TextField.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_ARG(lineIndex,"lineIndex");
	HX_STACK_LINE(65)
	return ::neash::text::TextField_obj::nme_text_field_get_line_offset(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineOffset,return )

Void TextField_obj::setTextFormat( ::neash::text::TextFormat format,hx::Null< int >  __o_beginIndex,hx::Null< int >  __o_endIndex){
int beginIndex = __o_beginIndex.Default(-1);
int endIndex = __o_endIndex.Default(-1);
	HX_STACK_PUSH("TextField::setTextFormat","neash/text/TextField.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_ARG(format,"format");
	HX_STACK_ARG(beginIndex,"beginIndex");
	HX_STACK_ARG(endIndex,"endIndex");
{
		HX_STACK_LINE(60)
		::neash::text::TextField_obj::nme_text_field_set_text_format(this->nmeHandle,format,beginIndex,endIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TextField_obj,setTextFormat,(void))

Void TextField_obj::setSelection( int beginIndex,int endIndex){
{
		HX_STACK_PUSH("TextField::setSelection","neash/text/TextField.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_ARG(beginIndex,"beginIndex");
		HX_STACK_ARG(endIndex,"endIndex");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextField_obj,setSelection,(void))

Void TextField_obj::appendText( ::String newText){
{
		HX_STACK_PUSH("TextField::appendText","neash/text/TextField.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newText,"newText");
		HX_STACK_LINE(47)
		::neash::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,(::neash::text::TextField_obj::nme_text_field_get_text(this->nmeHandle) + newText));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,appendText,(void))

Dynamic TextField_obj::nme_text_field_create;

Dynamic TextField_obj::nme_text_field_get_text;

Dynamic TextField_obj::nme_text_field_set_text;

Dynamic TextField_obj::nme_text_field_get_html_text;

Dynamic TextField_obj::nme_text_field_set_html_text;

Dynamic TextField_obj::nme_text_field_get_text_color;

Dynamic TextField_obj::nme_text_field_set_text_color;

Dynamic TextField_obj::nme_text_field_get_selectable;

Dynamic TextField_obj::nme_text_field_set_selectable;

Dynamic TextField_obj::nme_text_field_get_display_as_password;

Dynamic TextField_obj::nme_text_field_set_display_as_password;

Dynamic TextField_obj::nme_text_field_get_def_text_format;

Dynamic TextField_obj::nme_text_field_set_def_text_format;

Dynamic TextField_obj::nme_text_field_get_auto_size;

Dynamic TextField_obj::nme_text_field_set_auto_size;

Dynamic TextField_obj::nme_text_field_get_type;

Dynamic TextField_obj::nme_text_field_set_type;

Dynamic TextField_obj::nme_text_field_get_multiline;

Dynamic TextField_obj::nme_text_field_set_multiline;

Dynamic TextField_obj::nme_text_field_get_word_wrap;

Dynamic TextField_obj::nme_text_field_set_word_wrap;

Dynamic TextField_obj::nme_text_field_get_border;

Dynamic TextField_obj::nme_text_field_set_border;

Dynamic TextField_obj::nme_text_field_get_border_color;

Dynamic TextField_obj::nme_text_field_set_border_color;

Dynamic TextField_obj::nme_text_field_get_background;

Dynamic TextField_obj::nme_text_field_set_background;

Dynamic TextField_obj::nme_text_field_get_background_color;

Dynamic TextField_obj::nme_text_field_set_background_color;

Dynamic TextField_obj::nme_text_field_get_text_width;

Dynamic TextField_obj::nme_text_field_get_text_height;

Dynamic TextField_obj::nme_text_field_set_text_format;

Dynamic TextField_obj::nme_text_field_get_max_scroll_v;

Dynamic TextField_obj::nme_text_field_get_max_scroll_h;

Dynamic TextField_obj::nme_text_field_get_bottom_scroll_v;

Dynamic TextField_obj::nme_text_field_get_scroll_h;

Dynamic TextField_obj::nme_text_field_set_scroll_h;

Dynamic TextField_obj::nme_text_field_get_scroll_v;

Dynamic TextField_obj::nme_text_field_set_scroll_v;

Dynamic TextField_obj::nme_text_field_get_num_lines;

Dynamic TextField_obj::nme_text_field_get_max_chars;

Dynamic TextField_obj::nme_text_field_set_max_chars;

Dynamic TextField_obj::nme_text_field_get_line_text;

Dynamic TextField_obj::nme_text_field_get_line_offset;


TextField_obj::TextField_obj()
{
}

void TextField_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextField);
	HX_MARK_MEMBER_NAME(wordWrap,"wordWrap");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(textWidth,"textWidth");
	HX_MARK_MEMBER_NAME(textHeight,"textHeight");
	HX_MARK_MEMBER_NAME(textColor,"textColor");
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(selectable,"selectable");
	HX_MARK_MEMBER_NAME(scrollV,"scrollV");
	HX_MARK_MEMBER_NAME(scrollH,"scrollH");
	HX_MARK_MEMBER_NAME(numLines,"numLines");
	HX_MARK_MEMBER_NAME(multiline,"multiline");
	HX_MARK_MEMBER_NAME(maxScrollV,"maxScrollV");
	HX_MARK_MEMBER_NAME(maxScrollH,"maxScrollH");
	HX_MARK_MEMBER_NAME(maxChars,"maxChars");
	HX_MARK_MEMBER_NAME(htmlText,"htmlText");
	HX_MARK_MEMBER_NAME(embedFonts,"embedFonts");
	HX_MARK_MEMBER_NAME(displayAsPassword,"displayAsPassword");
	HX_MARK_MEMBER_NAME(defaultTextFormat,"defaultTextFormat");
	HX_MARK_MEMBER_NAME(bottomScrollV,"bottomScrollV");
	HX_MARK_MEMBER_NAME(borderColor,"borderColor");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(autoSize,"autoSize");
	HX_MARK_MEMBER_NAME(antiAliasType,"antiAliasType");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextField_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(wordWrap,"wordWrap");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(textWidth,"textWidth");
	HX_VISIT_MEMBER_NAME(textHeight,"textHeight");
	HX_VISIT_MEMBER_NAME(textColor,"textColor");
	HX_VISIT_MEMBER_NAME(text,"text");
	HX_VISIT_MEMBER_NAME(selectable,"selectable");
	HX_VISIT_MEMBER_NAME(scrollV,"scrollV");
	HX_VISIT_MEMBER_NAME(scrollH,"scrollH");
	HX_VISIT_MEMBER_NAME(numLines,"numLines");
	HX_VISIT_MEMBER_NAME(multiline,"multiline");
	HX_VISIT_MEMBER_NAME(maxScrollV,"maxScrollV");
	HX_VISIT_MEMBER_NAME(maxScrollH,"maxScrollH");
	HX_VISIT_MEMBER_NAME(maxChars,"maxChars");
	HX_VISIT_MEMBER_NAME(htmlText,"htmlText");
	HX_VISIT_MEMBER_NAME(embedFonts,"embedFonts");
	HX_VISIT_MEMBER_NAME(displayAsPassword,"displayAsPassword");
	HX_VISIT_MEMBER_NAME(defaultTextFormat,"defaultTextFormat");
	HX_VISIT_MEMBER_NAME(bottomScrollV,"bottomScrollV");
	HX_VISIT_MEMBER_NAME(borderColor,"borderColor");
	HX_VISIT_MEMBER_NAME(border,"border");
	HX_VISIT_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_VISIT_MEMBER_NAME(background,"background");
	HX_VISIT_MEMBER_NAME(autoSize,"autoSize");
	HX_VISIT_MEMBER_NAME(antiAliasType,"antiAliasType");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextField_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? nmeGetType() : type; }
		if (HX_FIELD_EQ(inName,"text") ) { return inCallProp ? nmeGetText() : text; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return inCallProp ? nmeGetBorder() : border; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollV") ) { return inCallProp ? nmeGetScrollV() : scrollV; }
		if (HX_FIELD_EQ(inName,"scrollH") ) { return inCallProp ? nmeGetScrollH() : scrollH; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return inCallProp ? nmeGetWordWrap() : wordWrap; }
		if (HX_FIELD_EQ(inName,"numLines") ) { return inCallProp ? nmeGetNumLines() : numLines; }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return inCallProp ? nmeGetMaxChars() : maxChars; }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return inCallProp ? nmeGetHTMLText() : htmlText; }
		if (HX_FIELD_EQ(inName,"autoSize") ) { return inCallProp ? nmeGetAutoSize() : autoSize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"textWidth") ) { return inCallProp ? nmeGetTextWidth() : textWidth; }
		if (HX_FIELD_EQ(inName,"textColor") ) { return inCallProp ? nmeGetTextColor() : textColor; }
		if (HX_FIELD_EQ(inName,"multiline") ) { return inCallProp ? nmeGetMultiline() : multiline; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeSetType") ) { return nmeSetType_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetText") ) { return nmeSetText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetText") ) { return nmeGetText_dyn(); }
		if (HX_FIELD_EQ(inName,"appendText") ) { return appendText_dyn(); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { return inCallProp ? nmeGetTextHeight() : textHeight; }
		if (HX_FIELD_EQ(inName,"selectable") ) { return inCallProp ? nmeGetSelectable() : selectable; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { return inCallProp ? nmeGetMaxScrollV() : maxScrollV; }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { return inCallProp ? nmeGetMaxScrollH() : maxScrollH; }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return inCallProp ? nmeGetEmbedFonts() : embedFonts; }
		if (HX_FIELD_EQ(inName,"background") ) { return inCallProp ? nmeGetBackground() : background; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getLineText") ) { return getLineText_dyn(); }
		if (HX_FIELD_EQ(inName,"borderColor") ) { return inCallProp ? nmeGetBorderColor() : borderColor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeSetBorder") ) { return nmeSetBorder_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBorder") ) { return nmeGetBorder_dyn(); }
		if (HX_FIELD_EQ(inName,"setSelection") ) { return setSelection_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeSetScrollV") ) { return nmeSetScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollV") ) { return nmeGetScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScrollH") ) { return nmeSetScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollH") ) { return nmeGetScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineOffset") ) { return getLineOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextFormat") ) { return setTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { return inCallProp ? nmeGetBottomScrollV() : bottomScrollV; }
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { return antiAliasType; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeSetWordWrap") ) { return nmeSetWordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetWordWrap") ) { return nmeGetWordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumLines") ) { return nmeGetNumLines_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMaxChars") ) { return nmeSetMaxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxChars") ) { return nmeGetMaxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetHTMLText") ) { return nmeSetHTMLText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetHTMLText") ) { return nmeGetHTMLText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAutoSize") ) { return nmeSetAutoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetAutoSize") ) { return nmeGetAutoSize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeGetTextWidth") ) { return nmeGetTextWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTextColor") ) { return nmeSetTextColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTextColor") ) { return nmeGetTextColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMultiline") ) { return nmeSetMultiline_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMultiline") ) { return nmeGetMultiline_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return inCallProp ? nmeGetBackgroundColor() : backgroundColor; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeGetTextHeight") ) { return nmeGetTextHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetSelectable") ) { return nmeSetSelectable_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetSelectable") ) { return nmeGetSelectable_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxScrollV") ) { return nmeGetMaxScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxScrollH") ) { return nmeGetMaxScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetEmbedFonts") ) { return nmeSetEmbedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetEmbedFonts") ) { return nmeGetEmbedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBackground") ) { return nmeSetBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBackground") ) { return nmeGetBackground_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeSetBorderColor") ) { return nmeSetBorderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBorderColor") ) { return nmeGetBorderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return inCallProp ? nmeGetDisplayAsPassword() : displayAsPassword; }
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return inCallProp ? nmeGetDefaultTextFormat() : defaultTextFormat; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetBottomScrollV") ) { return nmeGetBottomScrollV_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_text_field_create") ) { return nme_text_field_create; }
		if (HX_FIELD_EQ(inName,"nmeSetBackgroundColor") ) { return nmeSetBackgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBackgroundColor") ) { return nmeGetBackgroundColor_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text") ) { return nme_text_field_get_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text") ) { return nme_text_field_set_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_type") ) { return nme_text_field_get_type; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_type") ) { return nme_text_field_set_type; }
		if (HX_FIELD_EQ(inName,"nmeSetDisplayAsPassword") ) { return nmeSetDisplayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetDisplayAsPassword") ) { return nmeGetDisplayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetDefaultTextFormat") ) { return nmeSetDefaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetDefaultTextFormat") ) { return nmeGetDefaultTextFormat_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_border") ) { return nme_text_field_get_border; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_border") ) { return nme_text_field_set_border; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_scroll_h") ) { return nme_text_field_get_scroll_h; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_scroll_h") ) { return nme_text_field_set_scroll_h; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_scroll_v") ) { return nme_text_field_get_scroll_v; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_scroll_v") ) { return nme_text_field_set_scroll_v; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_html_text") ) { return nme_text_field_get_html_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_html_text") ) { return nme_text_field_set_html_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_auto_size") ) { return nme_text_field_get_auto_size; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_auto_size") ) { return nme_text_field_set_auto_size; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_multiline") ) { return nme_text_field_get_multiline; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_multiline") ) { return nme_text_field_set_multiline; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_word_wrap") ) { return nme_text_field_get_word_wrap; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_word_wrap") ) { return nme_text_field_set_word_wrap; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_num_lines") ) { return nme_text_field_get_num_lines; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_chars") ) { return nme_text_field_get_max_chars; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_max_chars") ) { return nme_text_field_set_max_chars; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_line_text") ) { return nme_text_field_get_line_text; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_color") ) { return nme_text_field_get_text_color; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text_color") ) { return nme_text_field_set_text_color; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_selectable") ) { return nme_text_field_get_selectable; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_selectable") ) { return nme_text_field_set_selectable; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_background") ) { return nme_text_field_get_background; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_background") ) { return nme_text_field_set_background; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_width") ) { return nme_text_field_get_text_width; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_height") ) { return nme_text_field_get_text_height; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text_format") ) { return nme_text_field_set_text_format; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_line_offset") ) { return nme_text_field_get_line_offset; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_border_color") ) { return nme_text_field_get_border_color; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_border_color") ) { return nme_text_field_set_border_color; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_scroll_v") ) { return nme_text_field_get_max_scroll_v; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_scroll_h") ) { return nme_text_field_get_max_scroll_h; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_def_text_format") ) { return nme_text_field_get_def_text_format; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_def_text_format") ) { return nme_text_field_set_def_text_format; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_bottom_scroll_v") ) { return nme_text_field_get_bottom_scroll_v; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_background_color") ) { return nme_text_field_get_background_color; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_background_color") ) { return nme_text_field_set_background_color; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_display_as_password") ) { return nme_text_field_get_display_as_password; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_display_as_password") ) { return nme_text_field_set_display_as_password; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextField_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return nmeSetType(inValue);type=inValue.Cast< ::neash::text::TextFieldType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"text") ) { if (inCallProp) return nmeSetText(inValue);text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { if (inCallProp) return nmeSetBorder(inValue);border=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollV") ) { if (inCallProp) return nmeSetScrollV(inValue);scrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollH") ) { if (inCallProp) return nmeSetScrollH(inValue);scrollH=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"wordWrap") ) { if (inCallProp) return nmeSetWordWrap(inValue);wordWrap=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numLines") ) { numLines=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxChars") ) { if (inCallProp) return nmeSetMaxChars(inValue);maxChars=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"htmlText") ) { if (inCallProp) return nmeSetHTMLText(inValue);htmlText=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"autoSize") ) { if (inCallProp) return nmeSetAutoSize(inValue);autoSize=inValue.Cast< ::neash::text::TextFieldAutoSize >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"textWidth") ) { textWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textColor") ) { if (inCallProp) return nmeSetTextColor(inValue);textColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"multiline") ) { if (inCallProp) return nmeSetMultiline(inValue);multiline=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"textHeight") ) { textHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selectable") ) { if (inCallProp) return nmeSetSelectable(inValue);selectable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { maxScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { maxScrollH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { if (inCallProp) return nmeSetEmbedFonts(inValue);embedFonts=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"background") ) { if (inCallProp) return nmeSetBackground(inValue);background=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { if (inCallProp) return nmeSetBorderColor(inValue);borderColor=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { bottomScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { antiAliasType=inValue.Cast< ::neash::text::AntiAliasType >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { if (inCallProp) return nmeSetBackgroundColor(inValue);backgroundColor=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { if (inCallProp) return nmeSetDisplayAsPassword(inValue);displayAsPassword=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { if (inCallProp) return nmeSetDefaultTextFormat(inValue);defaultTextFormat=inValue.Cast< ::neash::text::TextFormat >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_text_field_create") ) { nme_text_field_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text") ) { nme_text_field_get_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text") ) { nme_text_field_set_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_type") ) { nme_text_field_get_type=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_type") ) { nme_text_field_set_type=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_border") ) { nme_text_field_get_border=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_border") ) { nme_text_field_set_border=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_scroll_h") ) { nme_text_field_get_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_scroll_h") ) { nme_text_field_set_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_scroll_v") ) { nme_text_field_get_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_scroll_v") ) { nme_text_field_set_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_html_text") ) { nme_text_field_get_html_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_html_text") ) { nme_text_field_set_html_text=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_auto_size") ) { nme_text_field_get_auto_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_auto_size") ) { nme_text_field_set_auto_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_multiline") ) { nme_text_field_get_multiline=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_multiline") ) { nme_text_field_set_multiline=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_word_wrap") ) { nme_text_field_get_word_wrap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_word_wrap") ) { nme_text_field_set_word_wrap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_num_lines") ) { nme_text_field_get_num_lines=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_chars") ) { nme_text_field_get_max_chars=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_max_chars") ) { nme_text_field_set_max_chars=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_line_text") ) { nme_text_field_get_line_text=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_color") ) { nme_text_field_get_text_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text_color") ) { nme_text_field_set_text_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_selectable") ) { nme_text_field_get_selectable=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_selectable") ) { nme_text_field_set_selectable=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_background") ) { nme_text_field_get_background=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_background") ) { nme_text_field_set_background=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_width") ) { nme_text_field_get_text_width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text_height") ) { nme_text_field_get_text_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text_format") ) { nme_text_field_set_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_line_offset") ) { nme_text_field_get_line_offset=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_border_color") ) { nme_text_field_get_border_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_border_color") ) { nme_text_field_set_border_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_scroll_v") ) { nme_text_field_get_max_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_max_scroll_h") ) { nme_text_field_get_max_scroll_h=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_def_text_format") ) { nme_text_field_get_def_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_def_text_format") ) { nme_text_field_set_def_text_format=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_bottom_scroll_v") ) { nme_text_field_get_bottom_scroll_v=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_background_color") ) { nme_text_field_get_background_color=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_background_color") ) { nme_text_field_set_background_color=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_display_as_password") ) { nme_text_field_get_display_as_password=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_display_as_password") ) { nme_text_field_set_display_as_password=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextField_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("wordWrap"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("textWidth"));
	outFields->push(HX_CSTRING("textHeight"));
	outFields->push(HX_CSTRING("textColor"));
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("selectable"));
	outFields->push(HX_CSTRING("scrollV"));
	outFields->push(HX_CSTRING("scrollH"));
	outFields->push(HX_CSTRING("numLines"));
	outFields->push(HX_CSTRING("multiline"));
	outFields->push(HX_CSTRING("maxScrollV"));
	outFields->push(HX_CSTRING("maxScrollH"));
	outFields->push(HX_CSTRING("maxChars"));
	outFields->push(HX_CSTRING("htmlText"));
	outFields->push(HX_CSTRING("embedFonts"));
	outFields->push(HX_CSTRING("displayAsPassword"));
	outFields->push(HX_CSTRING("defaultTextFormat"));
	outFields->push(HX_CSTRING("bottomScrollV"));
	outFields->push(HX_CSTRING("borderColor"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("autoSize"));
	outFields->push(HX_CSTRING("antiAliasType"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_text_field_create"),
	HX_CSTRING("nme_text_field_get_text"),
	HX_CSTRING("nme_text_field_set_text"),
	HX_CSTRING("nme_text_field_get_html_text"),
	HX_CSTRING("nme_text_field_set_html_text"),
	HX_CSTRING("nme_text_field_get_text_color"),
	HX_CSTRING("nme_text_field_set_text_color"),
	HX_CSTRING("nme_text_field_get_selectable"),
	HX_CSTRING("nme_text_field_set_selectable"),
	HX_CSTRING("nme_text_field_get_display_as_password"),
	HX_CSTRING("nme_text_field_set_display_as_password"),
	HX_CSTRING("nme_text_field_get_def_text_format"),
	HX_CSTRING("nme_text_field_set_def_text_format"),
	HX_CSTRING("nme_text_field_get_auto_size"),
	HX_CSTRING("nme_text_field_set_auto_size"),
	HX_CSTRING("nme_text_field_get_type"),
	HX_CSTRING("nme_text_field_set_type"),
	HX_CSTRING("nme_text_field_get_multiline"),
	HX_CSTRING("nme_text_field_set_multiline"),
	HX_CSTRING("nme_text_field_get_word_wrap"),
	HX_CSTRING("nme_text_field_set_word_wrap"),
	HX_CSTRING("nme_text_field_get_border"),
	HX_CSTRING("nme_text_field_set_border"),
	HX_CSTRING("nme_text_field_get_border_color"),
	HX_CSTRING("nme_text_field_set_border_color"),
	HX_CSTRING("nme_text_field_get_background"),
	HX_CSTRING("nme_text_field_set_background"),
	HX_CSTRING("nme_text_field_get_background_color"),
	HX_CSTRING("nme_text_field_set_background_color"),
	HX_CSTRING("nme_text_field_get_text_width"),
	HX_CSTRING("nme_text_field_get_text_height"),
	HX_CSTRING("nme_text_field_set_text_format"),
	HX_CSTRING("nme_text_field_get_max_scroll_v"),
	HX_CSTRING("nme_text_field_get_max_scroll_h"),
	HX_CSTRING("nme_text_field_get_bottom_scroll_v"),
	HX_CSTRING("nme_text_field_get_scroll_h"),
	HX_CSTRING("nme_text_field_set_scroll_h"),
	HX_CSTRING("nme_text_field_get_scroll_v"),
	HX_CSTRING("nme_text_field_set_scroll_v"),
	HX_CSTRING("nme_text_field_get_num_lines"),
	HX_CSTRING("nme_text_field_get_max_chars"),
	HX_CSTRING("nme_text_field_set_max_chars"),
	HX_CSTRING("nme_text_field_get_line_text"),
	HX_CSTRING("nme_text_field_get_line_offset"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetWordWrap"),
	HX_CSTRING("nmeGetWordWrap"),
	HX_CSTRING("nmeSetType"),
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("nmeGetTextHeight"),
	HX_CSTRING("nmeGetTextWidth"),
	HX_CSTRING("nmeSetTextColor"),
	HX_CSTRING("nmeGetTextColor"),
	HX_CSTRING("nmeSetText"),
	HX_CSTRING("nmeGetText"),
	HX_CSTRING("nmeSetSelectable"),
	HX_CSTRING("nmeGetSelectable"),
	HX_CSTRING("nmeSetScrollV"),
	HX_CSTRING("nmeGetScrollV"),
	HX_CSTRING("nmeSetScrollH"),
	HX_CSTRING("nmeGetScrollH"),
	HX_CSTRING("nmeGetNumLines"),
	HX_CSTRING("nmeSetMultiline"),
	HX_CSTRING("nmeGetMultiline"),
	HX_CSTRING("nmeGetMaxScrollV"),
	HX_CSTRING("nmeGetMaxScrollH"),
	HX_CSTRING("nmeSetMaxChars"),
	HX_CSTRING("nmeGetMaxChars"),
	HX_CSTRING("nmeSetHTMLText"),
	HX_CSTRING("nmeGetHTMLText"),
	HX_CSTRING("nmeSetEmbedFonts"),
	HX_CSTRING("nmeGetEmbedFonts"),
	HX_CSTRING("nmeSetDisplayAsPassword"),
	HX_CSTRING("nmeGetDisplayAsPassword"),
	HX_CSTRING("nmeSetDefaultTextFormat"),
	HX_CSTRING("nmeGetDefaultTextFormat"),
	HX_CSTRING("nmeGetBottomScrollV"),
	HX_CSTRING("nmeSetBorderColor"),
	HX_CSTRING("nmeGetBorderColor"),
	HX_CSTRING("nmeSetBorder"),
	HX_CSTRING("nmeGetBorder"),
	HX_CSTRING("nmeSetBackgroundColor"),
	HX_CSTRING("nmeGetBackgroundColor"),
	HX_CSTRING("nmeSetBackground"),
	HX_CSTRING("nmeGetBackground"),
	HX_CSTRING("nmeSetAutoSize"),
	HX_CSTRING("nmeGetAutoSize"),
	HX_CSTRING("getLineText"),
	HX_CSTRING("getLineOffset"),
	HX_CSTRING("setTextFormat"),
	HX_CSTRING("setSelection"),
	HX_CSTRING("appendText"),
	HX_CSTRING("wordWrap"),
	HX_CSTRING("type"),
	HX_CSTRING("textWidth"),
	HX_CSTRING("textHeight"),
	HX_CSTRING("textColor"),
	HX_CSTRING("text"),
	HX_CSTRING("selectable"),
	HX_CSTRING("scrollV"),
	HX_CSTRING("scrollH"),
	HX_CSTRING("numLines"),
	HX_CSTRING("multiline"),
	HX_CSTRING("maxScrollV"),
	HX_CSTRING("maxScrollH"),
	HX_CSTRING("maxChars"),
	HX_CSTRING("htmlText"),
	HX_CSTRING("embedFonts"),
	HX_CSTRING("displayAsPassword"),
	HX_CSTRING("defaultTextFormat"),
	HX_CSTRING("bottomScrollV"),
	HX_CSTRING("borderColor"),
	HX_CSTRING("border"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("background"),
	HX_CSTRING("autoSize"),
	HX_CSTRING("antiAliasType"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextField_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_create,"nme_text_field_create");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_text,"nme_text_field_get_text");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_text,"nme_text_field_set_text");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_html_text,"nme_text_field_get_html_text");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_html_text,"nme_text_field_set_html_text");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_text_color,"nme_text_field_get_text_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_text_color,"nme_text_field_set_text_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_selectable,"nme_text_field_get_selectable");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_selectable,"nme_text_field_set_selectable");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_display_as_password,"nme_text_field_get_display_as_password");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_display_as_password,"nme_text_field_set_display_as_password");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_def_text_format,"nme_text_field_get_def_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_def_text_format,"nme_text_field_set_def_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_auto_size,"nme_text_field_get_auto_size");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_auto_size,"nme_text_field_set_auto_size");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_type,"nme_text_field_get_type");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_type,"nme_text_field_set_type");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_multiline,"nme_text_field_get_multiline");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_multiline,"nme_text_field_set_multiline");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_word_wrap,"nme_text_field_get_word_wrap");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_word_wrap,"nme_text_field_set_word_wrap");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_border,"nme_text_field_get_border");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_border,"nme_text_field_set_border");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_border_color,"nme_text_field_get_border_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_border_color,"nme_text_field_set_border_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_background,"nme_text_field_get_background");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_background,"nme_text_field_set_background");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_background_color,"nme_text_field_get_background_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_background_color,"nme_text_field_set_background_color");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_text_width,"nme_text_field_get_text_width");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_text_height,"nme_text_field_get_text_height");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_text_format,"nme_text_field_set_text_format");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_max_scroll_v,"nme_text_field_get_max_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_max_scroll_h,"nme_text_field_get_max_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_bottom_scroll_v,"nme_text_field_get_bottom_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_scroll_h,"nme_text_field_get_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_scroll_h,"nme_text_field_set_scroll_h");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_scroll_v,"nme_text_field_get_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_scroll_v,"nme_text_field_set_scroll_v");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_num_lines,"nme_text_field_get_num_lines");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_max_chars,"nme_text_field_get_max_chars");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_set_max_chars,"nme_text_field_set_max_chars");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_line_text,"nme_text_field_get_line_text");
	HX_MARK_MEMBER_NAME(TextField_obj::nme_text_field_get_line_offset,"nme_text_field_get_line_offset");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextField_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_create,"nme_text_field_create");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_text,"nme_text_field_get_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_text,"nme_text_field_set_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_html_text,"nme_text_field_get_html_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_html_text,"nme_text_field_set_html_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_text_color,"nme_text_field_get_text_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_text_color,"nme_text_field_set_text_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_selectable,"nme_text_field_get_selectable");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_selectable,"nme_text_field_set_selectable");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_display_as_password,"nme_text_field_get_display_as_password");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_display_as_password,"nme_text_field_set_display_as_password");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_def_text_format,"nme_text_field_get_def_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_def_text_format,"nme_text_field_set_def_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_auto_size,"nme_text_field_get_auto_size");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_auto_size,"nme_text_field_set_auto_size");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_type,"nme_text_field_get_type");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_type,"nme_text_field_set_type");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_multiline,"nme_text_field_get_multiline");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_multiline,"nme_text_field_set_multiline");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_word_wrap,"nme_text_field_get_word_wrap");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_word_wrap,"nme_text_field_set_word_wrap");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_border,"nme_text_field_get_border");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_border,"nme_text_field_set_border");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_border_color,"nme_text_field_get_border_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_border_color,"nme_text_field_set_border_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_background,"nme_text_field_get_background");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_background,"nme_text_field_set_background");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_background_color,"nme_text_field_get_background_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_background_color,"nme_text_field_set_background_color");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_text_width,"nme_text_field_get_text_width");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_text_height,"nme_text_field_get_text_height");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_text_format,"nme_text_field_set_text_format");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_max_scroll_v,"nme_text_field_get_max_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_max_scroll_h,"nme_text_field_get_max_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_bottom_scroll_v,"nme_text_field_get_bottom_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_scroll_h,"nme_text_field_get_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_scroll_h,"nme_text_field_set_scroll_h");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_scroll_v,"nme_text_field_get_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_scroll_v,"nme_text_field_set_scroll_v");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_num_lines,"nme_text_field_get_num_lines");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_max_chars,"nme_text_field_get_max_chars");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_set_max_chars,"nme_text_field_set_max_chars");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_line_text,"nme_text_field_get_line_text");
	HX_VISIT_MEMBER_NAME(TextField_obj::nme_text_field_get_line_offset,"nme_text_field_get_line_offset");
};

Class TextField_obj::__mClass;

void TextField_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.text.TextField"), hx::TCanCast< TextField_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextField_obj::__boot()
{
	nme_text_field_create= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_create"),(int)0);
	nme_text_field_get_text= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_text"),(int)1);
	nme_text_field_set_text= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_text"),(int)2);
	nme_text_field_get_html_text= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_html_text"),(int)1);
	nme_text_field_set_html_text= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_html_text"),(int)2);
	nme_text_field_get_text_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_color"),(int)1);
	nme_text_field_set_text_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_color"),(int)2);
	nme_text_field_get_selectable= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_selectable"),(int)1);
	nme_text_field_set_selectable= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_selectable"),(int)2);
	nme_text_field_get_display_as_password= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_display_as_password"),(int)1);
	nme_text_field_set_display_as_password= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_display_as_password"),(int)2);
	nme_text_field_get_def_text_format= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_def_text_format"),(int)2);
	nme_text_field_set_def_text_format= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_def_text_format"),(int)2);
	nme_text_field_get_auto_size= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_auto_size"),(int)1);
	nme_text_field_set_auto_size= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_auto_size"),(int)2);
	nme_text_field_get_type= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_type"),(int)1);
	nme_text_field_set_type= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_type"),(int)2);
	nme_text_field_get_multiline= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_multiline"),(int)1);
	nme_text_field_set_multiline= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_multiline"),(int)2);
	nme_text_field_get_word_wrap= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_word_wrap"),(int)1);
	nme_text_field_set_word_wrap= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_word_wrap"),(int)2);
	nme_text_field_get_border= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_border"),(int)1);
	nme_text_field_set_border= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_border"),(int)2);
	nme_text_field_get_border_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_border_color"),(int)1);
	nme_text_field_set_border_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_border_color"),(int)2);
	nme_text_field_get_background= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_background"),(int)1);
	nme_text_field_set_background= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_background"),(int)2);
	nme_text_field_get_background_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_background_color"),(int)1);
	nme_text_field_set_background_color= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_background_color"),(int)2);
	nme_text_field_get_text_width= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_width"),(int)1);
	nme_text_field_get_text_height= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_height"),(int)1);
	nme_text_field_set_text_format= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_format"),(int)4);
	nme_text_field_get_max_scroll_v= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_v"),(int)1);
	nme_text_field_get_max_scroll_h= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_h"),(int)1);
	nme_text_field_get_bottom_scroll_v= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_bottom_scroll_v"),(int)1);
	nme_text_field_get_scroll_h= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_h"),(int)1);
	nme_text_field_set_scroll_h= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_h"),(int)2);
	nme_text_field_get_scroll_v= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_v"),(int)1);
	nme_text_field_set_scroll_v= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_v"),(int)2);
	nme_text_field_get_num_lines= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_num_lines"),(int)1);
	nme_text_field_get_max_chars= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_chars"),(int)1);
	nme_text_field_set_max_chars= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_set_max_chars"),(int)2);
	nme_text_field_get_line_text= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_text"),(int)2);
	nme_text_field_get_line_offset= ::neash::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_offset"),(int)2);
}

} // end namespace neash
} // end namespace text
