#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_native_Loader
#include <native/Loader.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_text_AntiAliasType
#include <native/text/AntiAliasType.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFieldAutoSize
#include <native/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_native_text_TextFieldType
#include <native/text/TextFieldType.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
namespace native{
namespace text{

Void TextField_obj::__construct()
{
HX_STACK_PUSH("TextField::new","native/text/TextField.hx",39);
{
	HX_STACK_LINE(41)
	Dynamic handle = ::native::text::TextField_obj::nme_text_field_create();		HX_STACK_VAR(handle,"handle");
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

bool TextField_obj::set_wordWrap( bool inVal){
	HX_STACK_PUSH("TextField::set_wordWrap","native/text/TextField.hx",130);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(130)
	::native::text::TextField_obj::nme_text_field_set_word_wrap(this->nmeHandle,inVal);
	HX_STACK_LINE(130)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_wordWrap,return )

bool TextField_obj::get_wordWrap( ){
	HX_STACK_PUSH("TextField::get_wordWrap","native/text/TextField.hx",129);
	HX_STACK_THIS(this);
	HX_STACK_LINE(129)
	return ::native::text::TextField_obj::nme_text_field_get_word_wrap(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_wordWrap,return )

::native::text::TextFieldType TextField_obj::set_type( ::native::text::TextFieldType inType){
	HX_STACK_PUSH("TextField::set_type","native/text/TextField.hx",128);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inType,"inType");
	HX_STACK_LINE(128)
	::native::text::TextField_obj::nme_text_field_set_type(this->nmeHandle,(inType == ::native::text::TextFieldType_obj::INPUT_dyn()));
	HX_STACK_LINE(128)
	return inType;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_type,return )

::native::text::TextFieldType TextField_obj::get_type( ){
	HX_STACK_PUSH("TextField::get_type","native/text/TextField.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_LINE(127)
	return (  ((::native::text::TextField_obj::nme_text_field_get_type(this->nmeHandle))) ? ::native::text::TextFieldType(::native::text::TextFieldType_obj::INPUT_dyn()) : ::native::text::TextFieldType(::native::text::TextFieldType_obj::DYNAMIC_dyn()) );
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_type,return )

Float TextField_obj::get_textHeight( ){
	HX_STACK_PUSH("TextField::get_textHeight","native/text/TextField.hx",126);
	HX_STACK_THIS(this);
	HX_STACK_LINE(126)
	return ::native::text::TextField_obj::nme_text_field_get_text_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textHeight,return )

Float TextField_obj::get_textWidth( ){
	HX_STACK_PUSH("TextField::get_textWidth","native/text/TextField.hx",125);
	HX_STACK_THIS(this);
	HX_STACK_LINE(125)
	return ::native::text::TextField_obj::nme_text_field_get_text_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textWidth,return )

int TextField_obj::set_textColor( int inCol){
	HX_STACK_PUSH("TextField::set_textColor","native/text/TextField.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inCol,"inCol");
	HX_STACK_LINE(124)
	::native::text::TextField_obj::nme_text_field_set_text_color(this->nmeHandle,inCol);
	HX_STACK_LINE(124)
	return inCol;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_textColor,return )

int TextField_obj::get_textColor( ){
	HX_STACK_PUSH("TextField::get_textColor","native/text/TextField.hx",123);
	HX_STACK_THIS(this);
	HX_STACK_LINE(123)
	return ::native::text::TextField_obj::nme_text_field_get_text_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_textColor,return )

::String TextField_obj::set_text( ::String inText){
	HX_STACK_PUSH("TextField::set_text","native/text/TextField.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inText,"inText");
	HX_STACK_LINE(122)
	::native::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,inText);
	HX_STACK_LINE(122)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_text,return )

::String TextField_obj::get_text( ){
	HX_STACK_PUSH("TextField::get_text","native/text/TextField.hx",121);
	HX_STACK_THIS(this);
	HX_STACK_LINE(121)
	return ::native::text::TextField_obj::nme_text_field_get_text(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_text,return )

bool TextField_obj::set_selectable( bool inSel){
	HX_STACK_PUSH("TextField::set_selectable","native/text/TextField.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inSel,"inSel");
	HX_STACK_LINE(120)
	::native::text::TextField_obj::nme_text_field_set_selectable(this->nmeHandle,inSel);
	HX_STACK_LINE(120)
	return inSel;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_selectable,return )

bool TextField_obj::get_selectable( ){
	HX_STACK_PUSH("TextField::get_selectable","native/text/TextField.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_LINE(119)
	return ::native::text::TextField_obj::nme_text_field_get_selectable(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_selectable,return )

int TextField_obj::set_scrollV( int inVal){
	HX_STACK_PUSH("TextField::set_scrollV","native/text/TextField.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(118)
	::native::text::TextField_obj::nme_text_field_set_scroll_v(this->nmeHandle,inVal);
	HX_STACK_LINE(118)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_scrollV,return )

int TextField_obj::get_scrollV( ){
	HX_STACK_PUSH("TextField::get_scrollV","native/text/TextField.hx",117);
	HX_STACK_THIS(this);
	HX_STACK_LINE(117)
	return ::native::text::TextField_obj::nme_text_field_get_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_scrollV,return )

int TextField_obj::set_scrollH( int inVal){
	HX_STACK_PUSH("TextField::set_scrollH","native/text/TextField.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(116)
	::native::text::TextField_obj::nme_text_field_set_scroll_h(this->nmeHandle,inVal);
	HX_STACK_LINE(116)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_scrollH,return )

int TextField_obj::get_scrollH( ){
	HX_STACK_PUSH("TextField::get_scrollH","native/text/TextField.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return ::native::text::TextField_obj::nme_text_field_get_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_scrollH,return )

int TextField_obj::get_numLines( ){
	HX_STACK_PUSH("TextField::get_numLines","native/text/TextField.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	return ::native::text::TextField_obj::nme_text_field_get_num_lines(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_numLines,return )

bool TextField_obj::set_multiline( bool inVal){
	HX_STACK_PUSH("TextField::set_multiline","native/text/TextField.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(113)
	::native::text::TextField_obj::nme_text_field_set_multiline(this->nmeHandle,inVal);
	HX_STACK_LINE(113)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_multiline,return )

bool TextField_obj::get_multiline( ){
	HX_STACK_PUSH("TextField::get_multiline","native/text/TextField.hx",112);
	HX_STACK_THIS(this);
	HX_STACK_LINE(112)
	return ::native::text::TextField_obj::nme_text_field_get_multiline(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_multiline,return )

int TextField_obj::get_maxScrollV( ){
	HX_STACK_PUSH("TextField::get_maxScrollV","native/text/TextField.hx",111);
	HX_STACK_THIS(this);
	HX_STACK_LINE(111)
	return ::native::text::TextField_obj::nme_text_field_get_max_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxScrollV,return )

int TextField_obj::get_maxScrollH( ){
	HX_STACK_PUSH("TextField::get_maxScrollH","native/text/TextField.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	return ::native::text::TextField_obj::nme_text_field_get_max_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxScrollH,return )

int TextField_obj::set_maxChars( int inVal){
	HX_STACK_PUSH("TextField::set_maxChars","native/text/TextField.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(109)
	::native::text::TextField_obj::nme_text_field_set_max_chars(this->nmeHandle,inVal);
	HX_STACK_LINE(109)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_maxChars,return )

int TextField_obj::get_maxChars( ){
	HX_STACK_PUSH("TextField::get_maxChars","native/text/TextField.hx",108);
	HX_STACK_THIS(this);
	HX_STACK_LINE(108)
	return ::native::text::TextField_obj::nme_text_field_get_max_chars(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_maxChars,return )

::String TextField_obj::set_htmlText( ::String inText){
	HX_STACK_PUSH("TextField::set_htmlText","native/text/TextField.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inText,"inText");
	HX_STACK_LINE(107)
	::native::text::TextField_obj::nme_text_field_set_html_text(this->nmeHandle,inText);
	HX_STACK_LINE(107)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_htmlText,return )

::String TextField_obj::get_htmlText( ){
	HX_STACK_PUSH("TextField::get_htmlText","native/text/TextField.hx",106);
	HX_STACK_THIS(this);
	HX_STACK_LINE(106)
	return ::StringTools_obj::replace(::native::text::TextField_obj::nme_text_field_get_html_text(this->nmeHandle),HX_CSTRING("\n"),HX_CSTRING("<br/>"));
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_htmlText,return )

bool TextField_obj::set_embedFonts( bool value){
	HX_STACK_PUSH("TextField::set_embedFonts","native/text/TextField.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(105)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_embedFonts,return )

bool TextField_obj::get_embedFonts( ){
	HX_STACK_PUSH("TextField::get_embedFonts","native/text/TextField.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_LINE(104)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_embedFonts,return )

bool TextField_obj::set_displayAsPassword( bool inVal){
	HX_STACK_PUSH("TextField::set_displayAsPassword","native/text/TextField.hx",103);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(103)
	::native::text::TextField_obj::nme_text_field_set_display_as_password(this->nmeHandle,inVal);
	HX_STACK_LINE(103)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_displayAsPassword,return )

bool TextField_obj::get_displayAsPassword( ){
	HX_STACK_PUSH("TextField::get_displayAsPassword","native/text/TextField.hx",102);
	HX_STACK_THIS(this);
	HX_STACK_LINE(102)
	return ::native::text::TextField_obj::nme_text_field_get_display_as_password(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_displayAsPassword,return )

::native::text::TextFormat TextField_obj::set_defaultTextFormat( ::native::text::TextFormat inFormat){
	HX_STACK_PUSH("TextField::set_defaultTextFormat","native/text/TextField.hx",101);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inFormat,"inFormat");
	HX_STACK_LINE(101)
	::native::text::TextField_obj::nme_text_field_set_def_text_format(this->nmeHandle,inFormat);
	HX_STACK_LINE(101)
	return inFormat;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_defaultTextFormat,return )

::native::text::TextFormat TextField_obj::get_defaultTextFormat( ){
	HX_STACK_PUSH("TextField::get_defaultTextFormat","native/text/TextField.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(100)
	::native::text::TextFormat result = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(100)
	::native::text::TextField_obj::nme_text_field_get_def_text_format(this->nmeHandle,result);
	HX_STACK_LINE(100)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_defaultTextFormat,return )

int TextField_obj::get_bottomScrollV( ){
	HX_STACK_PUSH("TextField::get_bottomScrollV","native/text/TextField.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_LINE(99)
	return ::native::text::TextField_obj::nme_text_field_get_bottom_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_bottomScrollV,return )

int TextField_obj::set_borderColor( int inVal){
	HX_STACK_PUSH("TextField::set_borderColor","native/text/TextField.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(98)
	::native::text::TextField_obj::nme_text_field_set_border_color(this->nmeHandle,inVal);
	HX_STACK_LINE(98)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_borderColor,return )

int TextField_obj::get_borderColor( ){
	HX_STACK_PUSH("TextField::get_borderColor","native/text/TextField.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_LINE(97)
	return ::native::text::TextField_obj::nme_text_field_get_border_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_borderColor,return )

bool TextField_obj::set_border( bool inVal){
	HX_STACK_PUSH("TextField::set_border","native/text/TextField.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(96)
	::native::text::TextField_obj::nme_text_field_set_border(this->nmeHandle,inVal);
	HX_STACK_LINE(96)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_border,return )

bool TextField_obj::get_border( ){
	HX_STACK_PUSH("TextField::get_border","native/text/TextField.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_LINE(95)
	return ::native::text::TextField_obj::nme_text_field_get_border(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_border,return )

int TextField_obj::set_backgroundColor( int inVal){
	HX_STACK_PUSH("TextField::set_backgroundColor","native/text/TextField.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(94)
	::native::text::TextField_obj::nme_text_field_set_background_color(this->nmeHandle,inVal);
	HX_STACK_LINE(94)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_backgroundColor,return )

int TextField_obj::get_backgroundColor( ){
	HX_STACK_PUSH("TextField::get_backgroundColor","native/text/TextField.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_LINE(93)
	return ::native::text::TextField_obj::nme_text_field_get_background_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_backgroundColor,return )

bool TextField_obj::set_background( bool inVal){
	HX_STACK_PUSH("TextField::set_background","native/text/TextField.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(92)
	::native::text::TextField_obj::nme_text_field_set_background(this->nmeHandle,inVal);
	HX_STACK_LINE(92)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_background,return )

bool TextField_obj::get_background( ){
	HX_STACK_PUSH("TextField::get_background","native/text/TextField.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_LINE(91)
	return ::native::text::TextField_obj::nme_text_field_get_background(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_background,return )

::native::text::TextFieldAutoSize TextField_obj::set_autoSize( ::native::text::TextFieldAutoSize inVal){
	HX_STACK_PUSH("TextField::set_autoSize","native/text/TextField.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(90)
	::native::text::TextField_obj::nme_text_field_set_auto_size(this->nmeHandle,inVal->__Index());
	HX_STACK_LINE(90)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,set_autoSize,return )

::native::text::TextFieldAutoSize TextField_obj::get_autoSize( ){
	HX_STACK_PUSH("TextField::get_autoSize","native/text/TextField.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_LINE(89)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::native::text::TextFieldAutoSize >(),::native::text::TextField_obj::nme_text_field_get_auto_size(this->nmeHandle),null());
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,get_autoSize,return )

Void TextField_obj::setTextFormat( ::native::text::TextFormat format,hx::Null< int >  __o_beginIndex,hx::Null< int >  __o_endIndex){
int beginIndex = __o_beginIndex.Default(-1);
int endIndex = __o_endIndex.Default(-1);
	HX_STACK_PUSH("TextField::setTextFormat","native/text/TextField.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(format,"format");
	HX_STACK_ARG(beginIndex,"beginIndex");
	HX_STACK_ARG(endIndex,"endIndex");
{
		HX_STACK_LINE(75)
		::native::text::TextField_obj::nme_text_field_set_text_format(this->nmeHandle,format,beginIndex,endIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TextField_obj,setTextFormat,(void))

Void TextField_obj::setSelection( int beginIndex,int endIndex){
{
		HX_STACK_PUSH("TextField::setSelection","native/text/TextField.hx",68);
		HX_STACK_THIS(this);
		HX_STACK_ARG(beginIndex,"beginIndex");
		HX_STACK_ARG(endIndex,"endIndex");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextField_obj,setSelection,(void))

::String TextField_obj::getLineText( int lineIndex){
	HX_STACK_PUSH("TextField::getLineText","native/text/TextField.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_ARG(lineIndex,"lineIndex");
	HX_STACK_LINE(61)
	return ::native::text::TextField_obj::nme_text_field_get_line_text(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineText,return )

int TextField_obj::getLineOffset( int lineIndex){
	HX_STACK_PUSH("TextField::getLineOffset","native/text/TextField.hx",54);
	HX_STACK_THIS(this);
	HX_STACK_ARG(lineIndex,"lineIndex");
	HX_STACK_LINE(54)
	return ::native::text::TextField_obj::nme_text_field_get_line_offset(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineOffset,return )

Void TextField_obj::appendText( ::String newText){
{
		HX_STACK_PUSH("TextField::appendText","native/text/TextField.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newText,"newText");
		HX_STACK_LINE(47)
		::native::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,(::native::text::TextField_obj::nme_text_field_get_text(this->nmeHandle) + newText));
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
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		if (HX_FIELD_EQ(inName,"text") ) { return inCallProp ? get_text() : text; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return inCallProp ? get_border() : border; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollV") ) { return inCallProp ? get_scrollV() : scrollV; }
		if (HX_FIELD_EQ(inName,"scrollH") ) { return inCallProp ? get_scrollH() : scrollH; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"set_text") ) { return set_text_dyn(); }
		if (HX_FIELD_EQ(inName,"get_text") ) { return get_text_dyn(); }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return inCallProp ? get_wordWrap() : wordWrap; }
		if (HX_FIELD_EQ(inName,"numLines") ) { return inCallProp ? get_numLines() : numLines; }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return inCallProp ? get_maxChars() : maxChars; }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return inCallProp ? get_htmlText() : htmlText; }
		if (HX_FIELD_EQ(inName,"autoSize") ) { return inCallProp ? get_autoSize() : autoSize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"textWidth") ) { return inCallProp ? get_textWidth() : textWidth; }
		if (HX_FIELD_EQ(inName,"textColor") ) { return inCallProp ? get_textColor() : textColor; }
		if (HX_FIELD_EQ(inName,"multiline") ) { return inCallProp ? get_multiline() : multiline; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_border") ) { return set_border_dyn(); }
		if (HX_FIELD_EQ(inName,"get_border") ) { return get_border_dyn(); }
		if (HX_FIELD_EQ(inName,"appendText") ) { return appendText_dyn(); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { return inCallProp ? get_textHeight() : textHeight; }
		if (HX_FIELD_EQ(inName,"selectable") ) { return inCallProp ? get_selectable() : selectable; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { return inCallProp ? get_maxScrollV() : maxScrollV; }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { return inCallProp ? get_maxScrollH() : maxScrollH; }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return inCallProp ? get_embedFonts() : embedFonts; }
		if (HX_FIELD_EQ(inName,"background") ) { return inCallProp ? get_background() : background; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_scrollV") ) { return set_scrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollV") ) { return get_scrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollH") ) { return set_scrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollH") ) { return get_scrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineText") ) { return getLineText_dyn(); }
		if (HX_FIELD_EQ(inName,"borderColor") ) { return inCallProp ? get_borderColor() : borderColor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_wordWrap") ) { return set_wordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_wordWrap") ) { return get_wordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_numLines") ) { return get_numLines_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxChars") ) { return set_maxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxChars") ) { return get_maxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"set_htmlText") ) { return set_htmlText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_htmlText") ) { return get_htmlText_dyn(); }
		if (HX_FIELD_EQ(inName,"set_autoSize") ) { return set_autoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_autoSize") ) { return get_autoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"setSelection") ) { return setSelection_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_textWidth") ) { return get_textWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textColor") ) { return set_textColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textColor") ) { return get_textColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_multiline") ) { return set_multiline_dyn(); }
		if (HX_FIELD_EQ(inName,"get_multiline") ) { return get_multiline_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextFormat") ) { return setTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineOffset") ) { return getLineOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { return inCallProp ? get_bottomScrollV() : bottomScrollV; }
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { return antiAliasType; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_textHeight") ) { return get_textHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_selectable") ) { return set_selectable_dyn(); }
		if (HX_FIELD_EQ(inName,"get_selectable") ) { return get_selectable_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxScrollV") ) { return get_maxScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxScrollH") ) { return get_maxScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"set_embedFonts") ) { return set_embedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"get_embedFonts") ) { return get_embedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"set_background") ) { return set_background_dyn(); }
		if (HX_FIELD_EQ(inName,"get_background") ) { return get_background_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_borderColor") ) { return set_borderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderColor") ) { return get_borderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return inCallProp ? get_backgroundColor() : backgroundColor; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_bottomScrollV") ) { return get_bottomScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return inCallProp ? get_displayAsPassword() : displayAsPassword; }
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return inCallProp ? get_defaultTextFormat() : defaultTextFormat; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"set_backgroundColor") ) { return set_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundColor") ) { return get_backgroundColor_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_text_field_create") ) { return nme_text_field_create; }
		if (HX_FIELD_EQ(inName,"set_displayAsPassword") ) { return set_displayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"get_displayAsPassword") ) { return get_displayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"set_defaultTextFormat") ) { return set_defaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_defaultTextFormat") ) { return get_defaultTextFormat_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text") ) { return nme_text_field_get_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text") ) { return nme_text_field_set_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_type") ) { return nme_text_field_get_type; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_type") ) { return nme_text_field_set_type; }
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
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< ::native::text::TextFieldType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"text") ) { if (inCallProp) return set_text(inValue);text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { if (inCallProp) return set_border(inValue);border=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollV") ) { if (inCallProp) return set_scrollV(inValue);scrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollH") ) { if (inCallProp) return set_scrollH(inValue);scrollH=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"wordWrap") ) { if (inCallProp) return set_wordWrap(inValue);wordWrap=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numLines") ) { numLines=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxChars") ) { if (inCallProp) return set_maxChars(inValue);maxChars=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"htmlText") ) { if (inCallProp) return set_htmlText(inValue);htmlText=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"autoSize") ) { if (inCallProp) return set_autoSize(inValue);autoSize=inValue.Cast< ::native::text::TextFieldAutoSize >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"textWidth") ) { textWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textColor") ) { if (inCallProp) return set_textColor(inValue);textColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"multiline") ) { if (inCallProp) return set_multiline(inValue);multiline=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"textHeight") ) { textHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selectable") ) { if (inCallProp) return set_selectable(inValue);selectable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { maxScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { maxScrollH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { if (inCallProp) return set_embedFonts(inValue);embedFonts=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"background") ) { if (inCallProp) return set_background(inValue);background=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { if (inCallProp) return set_borderColor(inValue);borderColor=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { bottomScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { antiAliasType=inValue.Cast< ::native::text::AntiAliasType >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { if (inCallProp) return set_backgroundColor(inValue);backgroundColor=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { if (inCallProp) return set_displayAsPassword(inValue);displayAsPassword=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { if (inCallProp) return set_defaultTextFormat(inValue);defaultTextFormat=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
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
	HX_CSTRING("set_wordWrap"),
	HX_CSTRING("get_wordWrap"),
	HX_CSTRING("set_type"),
	HX_CSTRING("get_type"),
	HX_CSTRING("get_textHeight"),
	HX_CSTRING("get_textWidth"),
	HX_CSTRING("set_textColor"),
	HX_CSTRING("get_textColor"),
	HX_CSTRING("set_text"),
	HX_CSTRING("get_text"),
	HX_CSTRING("set_selectable"),
	HX_CSTRING("get_selectable"),
	HX_CSTRING("set_scrollV"),
	HX_CSTRING("get_scrollV"),
	HX_CSTRING("set_scrollH"),
	HX_CSTRING("get_scrollH"),
	HX_CSTRING("get_numLines"),
	HX_CSTRING("set_multiline"),
	HX_CSTRING("get_multiline"),
	HX_CSTRING("get_maxScrollV"),
	HX_CSTRING("get_maxScrollH"),
	HX_CSTRING("set_maxChars"),
	HX_CSTRING("get_maxChars"),
	HX_CSTRING("set_htmlText"),
	HX_CSTRING("get_htmlText"),
	HX_CSTRING("set_embedFonts"),
	HX_CSTRING("get_embedFonts"),
	HX_CSTRING("set_displayAsPassword"),
	HX_CSTRING("get_displayAsPassword"),
	HX_CSTRING("set_defaultTextFormat"),
	HX_CSTRING("get_defaultTextFormat"),
	HX_CSTRING("get_bottomScrollV"),
	HX_CSTRING("set_borderColor"),
	HX_CSTRING("get_borderColor"),
	HX_CSTRING("set_border"),
	HX_CSTRING("get_border"),
	HX_CSTRING("set_backgroundColor"),
	HX_CSTRING("get_backgroundColor"),
	HX_CSTRING("set_background"),
	HX_CSTRING("get_background"),
	HX_CSTRING("set_autoSize"),
	HX_CSTRING("get_autoSize"),
	HX_CSTRING("setTextFormat"),
	HX_CSTRING("setSelection"),
	HX_CSTRING("getLineText"),
	HX_CSTRING("getLineOffset"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.text.TextField"), hx::TCanCast< TextField_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextField_obj::__boot()
{
	nme_text_field_create= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_create"),(int)0);
	nme_text_field_get_text= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_text"),(int)1);
	nme_text_field_set_text= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_text"),(int)2);
	nme_text_field_get_html_text= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_html_text"),(int)1);
	nme_text_field_set_html_text= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_html_text"),(int)2);
	nme_text_field_get_text_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_color"),(int)1);
	nme_text_field_set_text_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_color"),(int)2);
	nme_text_field_get_selectable= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_selectable"),(int)1);
	nme_text_field_set_selectable= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_selectable"),(int)2);
	nme_text_field_get_display_as_password= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_display_as_password"),(int)1);
	nme_text_field_set_display_as_password= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_display_as_password"),(int)2);
	nme_text_field_get_def_text_format= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_def_text_format"),(int)2);
	nme_text_field_set_def_text_format= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_def_text_format"),(int)2);
	nme_text_field_get_auto_size= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_auto_size"),(int)1);
	nme_text_field_set_auto_size= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_auto_size"),(int)2);
	nme_text_field_get_type= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_type"),(int)1);
	nme_text_field_set_type= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_type"),(int)2);
	nme_text_field_get_multiline= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_multiline"),(int)1);
	nme_text_field_set_multiline= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_multiline"),(int)2);
	nme_text_field_get_word_wrap= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_word_wrap"),(int)1);
	nme_text_field_set_word_wrap= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_word_wrap"),(int)2);
	nme_text_field_get_border= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_border"),(int)1);
	nme_text_field_set_border= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_border"),(int)2);
	nme_text_field_get_border_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_border_color"),(int)1);
	nme_text_field_set_border_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_border_color"),(int)2);
	nme_text_field_get_background= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_background"),(int)1);
	nme_text_field_set_background= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_background"),(int)2);
	nme_text_field_get_background_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_background_color"),(int)1);
	nme_text_field_set_background_color= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_background_color"),(int)2);
	nme_text_field_get_text_width= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_width"),(int)1);
	nme_text_field_get_text_height= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_height"),(int)1);
	nme_text_field_set_text_format= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_format"),(int)4);
	nme_text_field_get_max_scroll_v= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_v"),(int)1);
	nme_text_field_get_max_scroll_h= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_h"),(int)1);
	nme_text_field_get_bottom_scroll_v= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_bottom_scroll_v"),(int)1);
	nme_text_field_get_scroll_h= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_h"),(int)1);
	nme_text_field_set_scroll_h= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_h"),(int)2);
	nme_text_field_get_scroll_v= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_v"),(int)1);
	nme_text_field_set_scroll_v= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_v"),(int)2);
	nme_text_field_get_num_lines= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_num_lines"),(int)1);
	nme_text_field_get_max_chars= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_chars"),(int)1);
	nme_text_field_set_max_chars= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_set_max_chars"),(int)2);
	nme_text_field_get_line_text= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_text"),(int)2);
	nme_text_field_get_line_offset= ::native::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_offset"),(int)2);
}

} // end namespace native
} // end namespace text
