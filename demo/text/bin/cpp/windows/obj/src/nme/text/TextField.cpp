#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_text_AntiAliasType
#include <nme/text/AntiAliasType.h>
#endif
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
#endif
#ifndef INCLUDED_nme_text_TextFieldAutoSize
#include <nme/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_nme_text_TextFieldType
#include <nme/text/TextFieldType.h>
#endif
#ifndef INCLUDED_nme_text_TextFormat
#include <nme/text/TextFormat.h>
#endif
namespace nme{
namespace text{

Void TextField_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",42)
	Dynamic handle = ::nme::text::TextField_obj::nme_text_field_create();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",43)
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

Void TextField_obj::appendText( ::String newText){
{
		HX_SOURCE_PUSH("TextField_obj::appendText")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",48)
		::nme::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,(::nme::text::TextField_obj::nme_text_field_get_text(this->nmeHandle) + newText));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,appendText,(void))

Void TextField_obj::setSelection( int beginIndex,int endIndex){
{
		HX_SOURCE_PUSH("TextField_obj::setSelection")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextField_obj,setSelection,(void))

Void TextField_obj::setTextFormat( ::nme::text::TextFormat format,Dynamic __o_beginIndex,Dynamic __o_endIndex){
int beginIndex = __o_beginIndex.Default(-1);
int endIndex = __o_endIndex.Default(-1);
	HX_SOURCE_PUSH("TextField_obj::setTextFormat");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",61)
		::nme::text::TextField_obj::nme_text_field_set_text_format(this->nmeHandle,format,beginIndex,endIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TextField_obj,setTextFormat,(void))

int TextField_obj::getLineOffset( int lineIndex){
	HX_SOURCE_PUSH("TextField_obj::getLineOffset")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",66)
	return ::nme::text::TextField_obj::nme_text_field_get_line_offset(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineOffset,return )

::String TextField_obj::getLineText( int lineIndex){
	HX_SOURCE_PUSH("TextField_obj::getLineText")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",71)
	return ::nme::text::TextField_obj::nme_text_field_get_line_text(this->nmeHandle,lineIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,getLineText,return )

::nme::text::TextFieldAutoSize TextField_obj::nmeGetAutoSize( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetAutoSize")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",80)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::nme::text::TextFieldAutoSize >(),::nme::text::TextField_obj::nme_text_field_get_auto_size(this->nmeHandle),null());
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetAutoSize,return )

::nme::text::TextFieldAutoSize TextField_obj::nmeSetAutoSize( ::nme::text::TextFieldAutoSize inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetAutoSize")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",81)
	::nme::text::TextField_obj::nme_text_field_set_auto_size(this->nmeHandle,inVal->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",81)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetAutoSize,return )

bool TextField_obj::nmeGetBackground( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetBackground")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",82)
	return ::nme::text::TextField_obj::nme_text_field_get_background(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBackground,return )

bool TextField_obj::nmeSetBackground( bool inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetBackground")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",83)
	::nme::text::TextField_obj::nme_text_field_set_background(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",83)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBackground,return )

int TextField_obj::nmeGetBackgroundColor( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetBackgroundColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",84)
	return ::nme::text::TextField_obj::nme_text_field_get_background_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBackgroundColor,return )

int TextField_obj::nmeSetBackgroundColor( int inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetBackgroundColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",85)
	::nme::text::TextField_obj::nme_text_field_set_background_color(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",85)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBackgroundColor,return )

bool TextField_obj::nmeGetBorder( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetBorder")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",86)
	return ::nme::text::TextField_obj::nme_text_field_get_border(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBorder,return )

bool TextField_obj::nmeSetBorder( bool inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetBorder")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",87)
	::nme::text::TextField_obj::nme_text_field_set_border(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",87)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBorder,return )

int TextField_obj::nmeGetBorderColor( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetBorderColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",88)
	return ::nme::text::TextField_obj::nme_text_field_get_border_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBorderColor,return )

int TextField_obj::nmeSetBorderColor( int inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetBorderColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",89)
	::nme::text::TextField_obj::nme_text_field_set_border_color(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",89)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetBorderColor,return )

int TextField_obj::nmeGetBottomScrollV( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetBottomScrollV")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",90)
	return ::nme::text::TextField_obj::nme_text_field_get_bottom_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetBottomScrollV,return )

::nme::text::TextFormat TextField_obj::nmeGetDefaultTextFormat( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetDefaultTextFormat")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",91)
	::nme::text::TextFormat result = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",91)
	::nme::text::TextField_obj::nme_text_field_get_def_text_format(this->nmeHandle,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",91)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetDefaultTextFormat,return )

::nme::text::TextFormat TextField_obj::nmeSetDefaultTextFormat( ::nme::text::TextFormat inFormat){
	HX_SOURCE_PUSH("TextField_obj::nmeSetDefaultTextFormat")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",92)
	::nme::text::TextField_obj::nme_text_field_set_def_text_format(this->nmeHandle,inFormat);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",92)
	return inFormat;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetDefaultTextFormat,return )

bool TextField_obj::nmeGetDisplayAsPassword( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetDisplayAsPassword")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",93)
	return ::nme::text::TextField_obj::nme_text_field_get_display_as_password(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetDisplayAsPassword,return )

bool TextField_obj::nmeSetDisplayAsPassword( bool inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetDisplayAsPassword")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",94)
	::nme::text::TextField_obj::nme_text_field_set_display_as_password(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",94)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetDisplayAsPassword,return )

bool TextField_obj::nmeGetEmbedFonts( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetEmbedFonts")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",95)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetEmbedFonts,return )

bool TextField_obj::nmeSetEmbedFonts( bool value){
	HX_SOURCE_PUSH("TextField_obj::nmeSetEmbedFonts")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",96)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetEmbedFonts,return )

::String TextField_obj::nmeGetHTMLText( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetHTMLText")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",97)
	return ::nme::text::TextField_obj::nme_text_field_get_html_text(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetHTMLText,return )

::String TextField_obj::nmeSetHTMLText( ::String inText){
	HX_SOURCE_PUSH("TextField_obj::nmeSetHTMLText")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",98)
	::nme::text::TextField_obj::nme_text_field_set_html_text(this->nmeHandle,inText);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",98)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetHTMLText,return )

int TextField_obj::nmeGetMaxChars( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetMaxChars")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",99)
	return ::nme::text::TextField_obj::nme_text_field_get_max_chars(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxChars,return )

int TextField_obj::nmeSetMaxChars( int inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetMaxChars")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",100)
	::nme::text::TextField_obj::nme_text_field_set_max_chars(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",100)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetMaxChars,return )

int TextField_obj::nmeGetMaxScrollH( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetMaxScrollH")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",101)
	return ::nme::text::TextField_obj::nme_text_field_get_max_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxScrollH,return )

int TextField_obj::nmeGetMaxScrollV( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetMaxScrollV")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",102)
	return ::nme::text::TextField_obj::nme_text_field_get_max_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMaxScrollV,return )

bool TextField_obj::nmeGetMultiline( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetMultiline")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",103)
	return ::nme::text::TextField_obj::nme_text_field_get_multiline(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetMultiline,return )

bool TextField_obj::nmeSetMultiline( bool inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetMultiline")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",104)
	::nme::text::TextField_obj::nme_text_field_set_multiline(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",104)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetMultiline,return )

int TextField_obj::nmeGetNumLines( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetNumLines")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",105)
	return ::nme::text::TextField_obj::nme_text_field_get_num_lines(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetNumLines,return )

int TextField_obj::nmeGetScrollH( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetScrollH")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",106)
	return ::nme::text::TextField_obj::nme_text_field_get_scroll_h(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetScrollH,return )

int TextField_obj::nmeSetScrollH( int inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetScrollH")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",107)
	::nme::text::TextField_obj::nme_text_field_set_scroll_h(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",107)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetScrollH,return )

int TextField_obj::nmeGetScrollV( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetScrollV")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",108)
	return ::nme::text::TextField_obj::nme_text_field_get_scroll_v(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetScrollV,return )

int TextField_obj::nmeSetScrollV( int inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetScrollV")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",109)
	::nme::text::TextField_obj::nme_text_field_set_scroll_v(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",109)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetScrollV,return )

bool TextField_obj::nmeGetSelectable( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetSelectable")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",110)
	return ::nme::text::TextField_obj::nme_text_field_get_selectable(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetSelectable,return )

bool TextField_obj::nmeSetSelectable( bool inSel){
	HX_SOURCE_PUSH("TextField_obj::nmeSetSelectable")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",111)
	::nme::text::TextField_obj::nme_text_field_set_selectable(this->nmeHandle,inSel);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",111)
	return inSel;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetSelectable,return )

::String TextField_obj::nmeGetText( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetText")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",112)
	return ::nme::text::TextField_obj::nme_text_field_get_text(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetText,return )

::String TextField_obj::nmeSetText( ::String inText){
	HX_SOURCE_PUSH("TextField_obj::nmeSetText")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",113)
	::nme::text::TextField_obj::nme_text_field_set_text(this->nmeHandle,inText);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",113)
	return inText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetText,return )

int TextField_obj::nmeGetTextColor( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetTextColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",114)
	return ::nme::text::TextField_obj::nme_text_field_get_text_color(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextColor,return )

int TextField_obj::nmeSetTextColor( int inCol){
	HX_SOURCE_PUSH("TextField_obj::nmeSetTextColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",115)
	::nme::text::TextField_obj::nme_text_field_set_text_color(this->nmeHandle,inCol);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",115)
	return inCol;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetTextColor,return )

double TextField_obj::nmeGetTextWidth( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetTextWidth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",116)
	return ::nme::text::TextField_obj::nme_text_field_get_text_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextWidth,return )

double TextField_obj::nmeGetTextHeight( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetTextHeight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",117)
	return ::nme::text::TextField_obj::nme_text_field_get_text_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetTextHeight,return )

::nme::text::TextFieldType TextField_obj::nmeGetType( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetType")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",118)
	return (  ((::nme::text::TextField_obj::nme_text_field_get_type(this->nmeHandle))) ? ::nme::text::TextFieldType(::nme::text::TextFieldType_obj::INPUT_dyn()) : ::nme::text::TextFieldType(::nme::text::TextFieldType_obj::DYNAMIC_dyn()) );
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetType,return )

::nme::text::TextFieldType TextField_obj::nmeSetType( ::nme::text::TextFieldType inType){
	HX_SOURCE_PUSH("TextField_obj::nmeSetType")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",119)
	::nme::text::TextField_obj::nme_text_field_set_type(this->nmeHandle,(inType == ::nme::text::TextFieldType_obj::INPUT_dyn()));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",119)
	return inType;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetType,return )

bool TextField_obj::nmeGetWordWrap( ){
	HX_SOURCE_PUSH("TextField_obj::nmeGetWordWrap")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",120)
	return ::nme::text::TextField_obj::nme_text_field_get_word_wrap(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(TextField_obj,nmeGetWordWrap,return )

bool TextField_obj::nmeSetWordWrap( bool inVal){
	HX_SOURCE_PUSH("TextField_obj::nmeSetWordWrap")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",121)
	::nme::text::TextField_obj::nme_text_field_set_word_wrap(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/text/TextField.hx",121)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(TextField_obj,nmeSetWordWrap,return )

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
	HX_MARK_MEMBER_NAME(antiAliasType,"antiAliasType");
	HX_MARK_MEMBER_NAME(autoSize,"autoSize");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(borderColor,"borderColor");
	HX_MARK_MEMBER_NAME(bottomScrollV,"bottomScrollV");
	HX_MARK_MEMBER_NAME(defaultTextFormat,"defaultTextFormat");
	HX_MARK_MEMBER_NAME(displayAsPassword,"displayAsPassword");
	HX_MARK_MEMBER_NAME(embedFonts,"embedFonts");
	HX_MARK_MEMBER_NAME(htmlText,"htmlText");
	HX_MARK_MEMBER_NAME(maxChars,"maxChars");
	HX_MARK_MEMBER_NAME(maxScrollH,"maxScrollH");
	HX_MARK_MEMBER_NAME(maxScrollV,"maxScrollV");
	HX_MARK_MEMBER_NAME(multiline,"multiline");
	HX_MARK_MEMBER_NAME(numLines,"numLines");
	HX_MARK_MEMBER_NAME(scrollH,"scrollH");
	HX_MARK_MEMBER_NAME(scrollV,"scrollV");
	HX_MARK_MEMBER_NAME(selectable,"selectable");
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(textColor,"textColor");
	HX_MARK_MEMBER_NAME(textHeight,"textHeight");
	HX_MARK_MEMBER_NAME(textWidth,"textWidth");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(wordWrap,"wordWrap");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TextField_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return nmeGetText(); }
		if (HX_FIELD_EQ(inName,"type") ) { return nmeGetType(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return nmeGetBorder(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollH") ) { return nmeGetScrollH(); }
		if (HX_FIELD_EQ(inName,"scrollV") ) { return nmeGetScrollV(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"autoSize") ) { return nmeGetAutoSize(); }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return nmeGetHTMLText(); }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return nmeGetMaxChars(); }
		if (HX_FIELD_EQ(inName,"numLines") ) { return nmeGetNumLines(); }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return nmeGetWordWrap(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"multiline") ) { return nmeGetMultiline(); }
		if (HX_FIELD_EQ(inName,"textColor") ) { return nmeGetTextColor(); }
		if (HX_FIELD_EQ(inName,"textWidth") ) { return nmeGetTextWidth(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return nmeGetBackground(); }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return nmeGetEmbedFonts(); }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { return nmeGetMaxScrollH(); }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { return nmeGetMaxScrollV(); }
		if (HX_FIELD_EQ(inName,"selectable") ) { return nmeGetSelectable(); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { return nmeGetTextHeight(); }
		if (HX_FIELD_EQ(inName,"appendText") ) { return appendText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetText") ) { return nmeGetText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetText") ) { return nmeSetText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetType") ) { return nmeSetType_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { return nmeGetBorderColor(); }
		if (HX_FIELD_EQ(inName,"getLineText") ) { return getLineText_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setSelection") ) { return setSelection_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBorder") ) { return nmeGetBorder_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBorder") ) { return nmeSetBorder_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { return antiAliasType; }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { return nmeGetBottomScrollV(); }
		if (HX_FIELD_EQ(inName,"setTextFormat") ) { return setTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineOffset") ) { return getLineOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollH") ) { return nmeGetScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScrollH") ) { return nmeSetScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollV") ) { return nmeGetScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScrollV") ) { return nmeSetScrollV_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeGetAutoSize") ) { return nmeGetAutoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAutoSize") ) { return nmeSetAutoSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetHTMLText") ) { return nmeGetHTMLText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetHTMLText") ) { return nmeSetHTMLText_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxChars") ) { return nmeGetMaxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMaxChars") ) { return nmeSetMaxChars_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumLines") ) { return nmeGetNumLines_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetWordWrap") ) { return nmeGetWordWrap_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetWordWrap") ) { return nmeSetWordWrap_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return nmeGetBackgroundColor(); }
		if (HX_FIELD_EQ(inName,"nmeGetMultiline") ) { return nmeGetMultiline_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMultiline") ) { return nmeSetMultiline_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTextColor") ) { return nmeGetTextColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTextColor") ) { return nmeSetTextColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTextWidth") ) { return nmeGetTextWidth_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeGetBackground") ) { return nmeGetBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBackground") ) { return nmeSetBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetEmbedFonts") ) { return nmeGetEmbedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetEmbedFonts") ) { return nmeSetEmbedFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxScrollH") ) { return nmeGetMaxScrollH_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMaxScrollV") ) { return nmeGetMaxScrollV_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetSelectable") ) { return nmeGetSelectable_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetSelectable") ) { return nmeSetSelectable_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTextHeight") ) { return nmeGetTextHeight_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return nmeGetDefaultTextFormat(); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return nmeGetDisplayAsPassword(); }
		if (HX_FIELD_EQ(inName,"nmeGetBorderColor") ) { return nmeGetBorderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBorderColor") ) { return nmeSetBorderColor_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetBottomScrollV") ) { return nmeGetBottomScrollV_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_text_field_create") ) { return nme_text_field_create; }
		if (HX_FIELD_EQ(inName,"nmeGetBackgroundColor") ) { return nmeGetBackgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBackgroundColor") ) { return nmeSetBackgroundColor_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_text_field_get_text") ) { return nme_text_field_get_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_text") ) { return nme_text_field_set_text; }
		if (HX_FIELD_EQ(inName,"nme_text_field_get_type") ) { return nme_text_field_get_type; }
		if (HX_FIELD_EQ(inName,"nme_text_field_set_type") ) { return nme_text_field_set_type; }
		if (HX_FIELD_EQ(inName,"nmeGetDefaultTextFormat") ) { return nmeGetDefaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetDefaultTextFormat") ) { return nmeSetDefaultTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetDisplayAsPassword") ) { return nmeGetDisplayAsPassword_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetDisplayAsPassword") ) { return nmeSetDisplayAsPassword_dyn(); }
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
	return super::__Field(inName);
}

Dynamic TextField_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return nmeSetText(inValue); }
		if (HX_FIELD_EQ(inName,"type") ) { return nmeSetType(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return nmeSetBorder(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollH") ) { return nmeSetScrollH(inValue); }
		if (HX_FIELD_EQ(inName,"scrollV") ) { return nmeSetScrollV(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"autoSize") ) { return nmeSetAutoSize(inValue); }
		if (HX_FIELD_EQ(inName,"htmlText") ) { return nmeSetHTMLText(inValue); }
		if (HX_FIELD_EQ(inName,"maxChars") ) { return nmeSetMaxChars(inValue); }
		if (HX_FIELD_EQ(inName,"numLines") ) { numLines=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { return nmeSetWordWrap(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"multiline") ) { return nmeSetMultiline(inValue); }
		if (HX_FIELD_EQ(inName,"textColor") ) { return nmeSetTextColor(inValue); }
		if (HX_FIELD_EQ(inName,"textWidth") ) { textWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return nmeSetBackground(inValue); }
		if (HX_FIELD_EQ(inName,"embedFonts") ) { return nmeSetEmbedFonts(inValue); }
		if (HX_FIELD_EQ(inName,"maxScrollH") ) { maxScrollH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxScrollV") ) { maxScrollV=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selectable") ) { return nmeSetSelectable(inValue); }
		if (HX_FIELD_EQ(inName,"textHeight") ) { textHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { return nmeSetBorderColor(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"antiAliasType") ) { antiAliasType=inValue.Cast< ::nme::text::AntiAliasType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottomScrollV") ) { bottomScrollV=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return nmeSetBackgroundColor(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"defaultTextFormat") ) { return nmeSetDefaultTextFormat(inValue); }
		if (HX_FIELD_EQ(inName,"displayAsPassword") ) { return nmeSetDisplayAsPassword(inValue); }
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
	return super::__SetField(inName,inValue);
}

void TextField_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("antiAliasType"));
	outFields->push(HX_CSTRING("autoSize"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("borderColor"));
	outFields->push(HX_CSTRING("bottomScrollV"));
	outFields->push(HX_CSTRING("defaultTextFormat"));
	outFields->push(HX_CSTRING("displayAsPassword"));
	outFields->push(HX_CSTRING("embedFonts"));
	outFields->push(HX_CSTRING("htmlText"));
	outFields->push(HX_CSTRING("maxChars"));
	outFields->push(HX_CSTRING("maxScrollH"));
	outFields->push(HX_CSTRING("maxScrollV"));
	outFields->push(HX_CSTRING("multiline"));
	outFields->push(HX_CSTRING("numLines"));
	outFields->push(HX_CSTRING("scrollH"));
	outFields->push(HX_CSTRING("scrollV"));
	outFields->push(HX_CSTRING("selectable"));
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("textColor"));
	outFields->push(HX_CSTRING("textHeight"));
	outFields->push(HX_CSTRING("textWidth"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("wordWrap"));
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
	HX_CSTRING("antiAliasType"),
	HX_CSTRING("autoSize"),
	HX_CSTRING("background"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("border"),
	HX_CSTRING("borderColor"),
	HX_CSTRING("bottomScrollV"),
	HX_CSTRING("defaultTextFormat"),
	HX_CSTRING("displayAsPassword"),
	HX_CSTRING("embedFonts"),
	HX_CSTRING("htmlText"),
	HX_CSTRING("maxChars"),
	HX_CSTRING("maxScrollH"),
	HX_CSTRING("maxScrollV"),
	HX_CSTRING("multiline"),
	HX_CSTRING("numLines"),
	HX_CSTRING("scrollH"),
	HX_CSTRING("scrollV"),
	HX_CSTRING("selectable"),
	HX_CSTRING("text"),
	HX_CSTRING("textColor"),
	HX_CSTRING("textHeight"),
	HX_CSTRING("textWidth"),
	HX_CSTRING("type"),
	HX_CSTRING("wordWrap"),
	HX_CSTRING("appendText"),
	HX_CSTRING("setSelection"),
	HX_CSTRING("setTextFormat"),
	HX_CSTRING("getLineOffset"),
	HX_CSTRING("getLineText"),
	HX_CSTRING("nmeGetAutoSize"),
	HX_CSTRING("nmeSetAutoSize"),
	HX_CSTRING("nmeGetBackground"),
	HX_CSTRING("nmeSetBackground"),
	HX_CSTRING("nmeGetBackgroundColor"),
	HX_CSTRING("nmeSetBackgroundColor"),
	HX_CSTRING("nmeGetBorder"),
	HX_CSTRING("nmeSetBorder"),
	HX_CSTRING("nmeGetBorderColor"),
	HX_CSTRING("nmeSetBorderColor"),
	HX_CSTRING("nmeGetBottomScrollV"),
	HX_CSTRING("nmeGetDefaultTextFormat"),
	HX_CSTRING("nmeSetDefaultTextFormat"),
	HX_CSTRING("nmeGetDisplayAsPassword"),
	HX_CSTRING("nmeSetDisplayAsPassword"),
	HX_CSTRING("nmeGetEmbedFonts"),
	HX_CSTRING("nmeSetEmbedFonts"),
	HX_CSTRING("nmeGetHTMLText"),
	HX_CSTRING("nmeSetHTMLText"),
	HX_CSTRING("nmeGetMaxChars"),
	HX_CSTRING("nmeSetMaxChars"),
	HX_CSTRING("nmeGetMaxScrollH"),
	HX_CSTRING("nmeGetMaxScrollV"),
	HX_CSTRING("nmeGetMultiline"),
	HX_CSTRING("nmeSetMultiline"),
	HX_CSTRING("nmeGetNumLines"),
	HX_CSTRING("nmeGetScrollH"),
	HX_CSTRING("nmeSetScrollH"),
	HX_CSTRING("nmeGetScrollV"),
	HX_CSTRING("nmeSetScrollV"),
	HX_CSTRING("nmeGetSelectable"),
	HX_CSTRING("nmeSetSelectable"),
	HX_CSTRING("nmeGetText"),
	HX_CSTRING("nmeSetText"),
	HX_CSTRING("nmeGetTextColor"),
	HX_CSTRING("nmeSetTextColor"),
	HX_CSTRING("nmeGetTextWidth"),
	HX_CSTRING("nmeGetTextHeight"),
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("nmeSetType"),
	HX_CSTRING("nmeGetWordWrap"),
	HX_CSTRING("nmeSetWordWrap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
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

Class TextField_obj::__mClass;

void TextField_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.text.TextField"), hx::TCanCast< TextField_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextField_obj::__boot()
{
	hx::Static(nme_text_field_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_create"),(int)0);
	hx::Static(nme_text_field_get_text) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_text"),(int)1);
	hx::Static(nme_text_field_set_text) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_text"),(int)2);
	hx::Static(nme_text_field_get_html_text) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_html_text"),(int)1);
	hx::Static(nme_text_field_set_html_text) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_html_text"),(int)2);
	hx::Static(nme_text_field_get_text_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_color"),(int)1);
	hx::Static(nme_text_field_set_text_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_color"),(int)2);
	hx::Static(nme_text_field_get_selectable) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_selectable"),(int)1);
	hx::Static(nme_text_field_set_selectable) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_selectable"),(int)2);
	hx::Static(nme_text_field_get_display_as_password) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_display_as_password"),(int)1);
	hx::Static(nme_text_field_set_display_as_password) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_display_as_password"),(int)2);
	hx::Static(nme_text_field_get_def_text_format) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_def_text_format"),(int)2);
	hx::Static(nme_text_field_set_def_text_format) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_def_text_format"),(int)2);
	hx::Static(nme_text_field_get_auto_size) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_auto_size"),(int)1);
	hx::Static(nme_text_field_set_auto_size) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_auto_size"),(int)2);
	hx::Static(nme_text_field_get_type) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_type"),(int)1);
	hx::Static(nme_text_field_set_type) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_type"),(int)2);
	hx::Static(nme_text_field_get_multiline) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_multiline"),(int)1);
	hx::Static(nme_text_field_set_multiline) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_multiline"),(int)2);
	hx::Static(nme_text_field_get_word_wrap) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_word_wrap"),(int)1);
	hx::Static(nme_text_field_set_word_wrap) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_word_wrap"),(int)2);
	hx::Static(nme_text_field_get_border) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_border"),(int)1);
	hx::Static(nme_text_field_set_border) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_border"),(int)2);
	hx::Static(nme_text_field_get_border_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_border_color"),(int)1);
	hx::Static(nme_text_field_set_border_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_border_color"),(int)2);
	hx::Static(nme_text_field_get_background) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_background"),(int)1);
	hx::Static(nme_text_field_set_background) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_background"),(int)2);
	hx::Static(nme_text_field_get_background_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_background_color"),(int)1);
	hx::Static(nme_text_field_set_background_color) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_background_color"),(int)2);
	hx::Static(nme_text_field_get_text_width) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_width"),(int)1);
	hx::Static(nme_text_field_get_text_height) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_text_height"),(int)1);
	hx::Static(nme_text_field_set_text_format) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_text_format"),(int)4);
	hx::Static(nme_text_field_get_max_scroll_v) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_v"),(int)1);
	hx::Static(nme_text_field_get_max_scroll_h) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_scroll_h"),(int)1);
	hx::Static(nme_text_field_get_bottom_scroll_v) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_bottom_scroll_v"),(int)1);
	hx::Static(nme_text_field_get_scroll_h) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_h"),(int)1);
	hx::Static(nme_text_field_set_scroll_h) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_h"),(int)2);
	hx::Static(nme_text_field_get_scroll_v) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_scroll_v"),(int)1);
	hx::Static(nme_text_field_set_scroll_v) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_scroll_v"),(int)2);
	hx::Static(nme_text_field_get_num_lines) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_num_lines"),(int)1);
	hx::Static(nme_text_field_get_max_chars) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_max_chars"),(int)1);
	hx::Static(nme_text_field_set_max_chars) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_set_max_chars"),(int)2);
	hx::Static(nme_text_field_get_line_text) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_text"),(int)2);
	hx::Static(nme_text_field_get_line_offset) = ::nme::Loader_obj::load(HX_CSTRING("nme_text_field_get_line_offset"),(int)2);
}

} // end namespace nme
} // end namespace text
