#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_TextTokenValue
#include <cocktail/core/dom/TextTokenValue.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#include <cocktail/core/renderer/TextRenderer.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Text_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",69)
	super::__construct();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",70)
	this->_textFragments = Dynamic( Array_obj<Dynamic>::__new() );
}
;
	return null();
}

Text_obj::~Text_obj() { }

Dynamic Text_obj::__CreateEmpty() { return  new Text_obj; }
hx::ObjectPtr< Text_obj > Text_obj::__new()
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

Dynamic Text_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

Void Text_obj::reset( ){
{
		HX_SOURCE_PUSH("Text_obj::reset")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",85)
		int _g1 = (int)0;
		int _g = this->_textFragments->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",85)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",85)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",87)
			this->_textFragments->__GetItem(i)->__FieldRef(HX_CSTRING("textRenderer")) = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Text_obj,reset,(void))

Dynamic Text_obj::getTextFragments( ::String text){
	HX_SOURCE_PUSH("Text_obj::getTextFragments")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",99)
	if (((this->_textFragments->__Field(HX_CSTRING("length")) == (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",100)
		this->_textFragments = ::cocktail::core::dom::Text_obj::doGetTextFragments(text);
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",104)
	return this->_textFragments;
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,getTextFragments,return )

Dynamic Text_obj::get_nativeElement( ){
	HX_SOURCE_PUSH("Text_obj::get_nativeElement")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",221)
	return this->_nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(Text_obj,get_nativeElement,return )

::String Text_obj::get_nodeValue( ){
	HX_SOURCE_PUSH("Text_obj::get_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",226)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC0(Text_obj,get_nodeValue,return )

::String Text_obj::set_nodeValue( ::String value){
	HX_SOURCE_PUSH("Text_obj::set_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",231)
	return this->set_data(value);
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,set_nodeValue,return )

Dynamic Text_obj::doGetTextFragments( ::String text){
	HX_SOURCE_PUSH("Text_obj::doGetTextFragments")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",122)
	Dynamic textFragments = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",125)
	::String textFragment = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",127)
	int i = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",130)
	while(((i < text.length))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",133)
		if (((text.charAt(i) == HX_CSTRING("\\")))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",134)
			if (((i < (text.length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",136)
				if (((text.charAt((i + (int)1)) == HX_CSTRING("n")))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",140)
					if (((textFragment != null()))){
						HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",143)
						textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::word(textFragment)));
						HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",144)
						textFragment = null();
					}
					HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",147)
					textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::lineFeed_dyn()));
					HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",148)
					(i)++;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",151)
					if (((text.charAt((i + (int)1)) == HX_CSTRING("t")))){
						HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",153)
						if (((textFragment != null()))){
							HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",156)
							textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::word(textFragment)));
							HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",157)
							textFragment = null();
						}
						HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",160)
						textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::tab_dyn()));
						HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",161)
						(i)++;
					}
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",167)
		if (((::StringTools_obj::isSpace(text,i) == true))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",172)
			if (((textFragment != null()))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",175)
				textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::word(textFragment)));
				HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",176)
				textFragment = null();
			}
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",180)
			textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::space_dyn()));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",187)
			if (((textFragment == null()))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",188)
				textFragment = HX_CSTRING("");
			}
			HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",191)
			hx::AddEq(textFragment,text.charAt(i));
		}
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",194)
		(i)++;
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",199)
	if (((textFragment != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",200)
		textFragments->__Field(HX_CSTRING("push"))(::cocktail::core::dom::Text_obj::insertTextToken(::cocktail::core::dom::TextTokenValue_obj::word(textFragment)));
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",204)
	return textFragments;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Text_obj,doGetTextFragments,return )

Dynamic Text_obj::insertTextToken( ::cocktail::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("Text_obj::insertTextToken")
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::dom::TextTokenValue &textToken){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("textToken") , textToken,false);
			__result->Add(HX_CSTRING("textRenderer") , null(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/dom/Text.hx",212)
	return _Function_1_1::Block(textToken);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Text_obj,insertTextToken,return )


Text_obj::Text_obj()
{
}

void Text_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Text);
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_MARK_MEMBER_NAME(nativeElement,"nativeElement");
	HX_MARK_MEMBER_NAME(_textFragments,"_textFragments");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Text_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { return get_nativeElement(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
		if (HX_FIELD_EQ(inName,"_textFragments") ) { return _textFragments; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"insertTextToken") ) { return insertTextToken_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getTextFragments") ) { return getTextFragments_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_nativeElement") ) { return get_nativeElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doGetTextFragments") ) { return doGetTextFragments_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Text_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_textFragments") ) { _textFragments=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Text_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nativeElement"));
	outFields->push(HX_CSTRING("nativeElement"));
	outFields->push(HX_CSTRING("_textFragments"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("doGetTextFragments"),
	HX_CSTRING("insertTextToken"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("nativeElement"),
	HX_CSTRING("_textFragments"),
	HX_CSTRING("reset"),
	HX_CSTRING("getTextFragments"),
	HX_CSTRING("get_nativeElement"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("set_nodeValue"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Text_obj::__mClass;

void Text_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Text"), hx::TCanCast< Text_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Text_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
