#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_font_AbstractFontLoader
#include <cocktail/core/font/AbstractFontLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManager
#include <cocktail/core/font/AbstractFontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_FontLoader
#include <cocktail/port/flash_player/FontLoader.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace cocktail{
namespace core{
namespace font{

Void AbstractFontManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",42)
	if (((::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",43)
		::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray = Array_obj< ::cocktail::port::flash_player::FontLoader >::__new();
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",44)
	if (((::cocktail::core::font::AbstractFontManager_obj::_loadedFonts == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",45)
		::cocktail::core::font::AbstractFontManager_obj::_loadedFonts = Dynamic( Array_obj<Dynamic>::__new() );
	}
}
;
	return null();
}

AbstractFontManager_obj::~AbstractFontManager_obj() { }

Dynamic AbstractFontManager_obj::__CreateEmpty() { return  new AbstractFontManager_obj; }
hx::ObjectPtr< AbstractFontManager_obj > AbstractFontManager_obj::__new()
{  hx::ObjectPtr< AbstractFontManager_obj > result = new AbstractFontManager_obj();
	result->__construct();
	return result;}

Dynamic AbstractFontManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractFontManager_obj > result = new AbstractFontManager_obj();
	result->__construct();
	return result;}

Dynamic AbstractFontManager_obj::getEmbeddedFonts( ){
	HX_SOURCE_PUSH("AbstractFontManager_obj::getEmbeddedFonts")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",55)
	return ::cocktail::core::font::AbstractFontManager_obj::_loadedFonts;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFontManager_obj,getEmbeddedFonts,return )

Dynamic AbstractFontManager_obj::getSystemFonts( ){
	HX_SOURCE_PUSH("AbstractFontManager_obj::getSystemFonts")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",63)
	hx::Throw (HX_CSTRING("Virtual method should be implemented in sub class"));
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",64)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFontManager_obj,getSystemFonts,return )

bool AbstractFontManager_obj::hasFont( ::String fontName){
	HX_SOURCE_PUSH("AbstractFontManager_obj::hasFont")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",71)
	Dynamic fontDataArray;
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",72)
	int idx;
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",75)
	fontDataArray = this->getEmbeddedFonts();
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",76)
	{
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",76)
		int _g1 = (int)0;
		int _g = fontDataArray->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",76)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",76)
			int idx1 = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",77)
			if (((fontDataArray->__GetItem(idx1)->__Field(HX_CSTRING("name")) == fontName))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",78)
				return true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",81)
	fontDataArray = this->getSystemFonts();
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",82)
	{
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",82)
		int _g1 = (int)0;
		int _g = fontDataArray->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",82)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",82)
			int idx1 = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",83)
			if (((fontDataArray->__GetItem(idx1)->__Field(HX_CSTRING("name")) == fontName))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",84)
				return true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",86)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontManager_obj,hasFont,return )

Dynamic AbstractFontManager_obj::getFontMetrics( ::String fontFamily,double fontSize){
	HX_SOURCE_PUSH("AbstractFontManager_obj::getFontMetrics")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",99)
	hx::Throw (HX_CSTRING("Virtual method should be implemented in sub class"));
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",100)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManager_obj,getFontMetrics,return )

Dynamic AbstractFontManager_obj::createNativeTextElement( ::String text,Dynamic computedStyle){
	HX_SOURCE_PUSH("AbstractFontManager_obj::createNativeTextElement")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",113)
	hx::Throw (HX_CSTRING("Virtual method should be implemented in sub class"));
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",114)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManager_obj,createNativeTextElement,return )

::String AbstractFontManager_obj::applyTextTransform( ::String text,::cocktail::core::style::TextTransform textTransform){
	HX_SOURCE_PUSH("AbstractFontManager_obj::applyTextTransform")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",128)
	{
::cocktail::core::style::TextTransform _switch_1 = (textTransform);
		switch((_switch_1)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",130)
				text = text.toUpperCase();
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",133)
				text = text.toLowerCase();
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",136)
				text = this->capitalizeText(text);
			}
			;break;
			case 3: {
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",142)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManager_obj,applyTextTransform,return )

::String AbstractFontManager_obj::capitalizeText( ::String text){
	HX_SOURCE_PUSH("AbstractFontManager_obj::capitalizeText")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",153)
	::String capitalizedText = text.charAt((int)0);
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",159)
	{
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",159)
		int _g1 = (int)1;
		int _g = text.length;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",159)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",159)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",161)
			if (((text.charAt((i - (int)1)) == HX_CSTRING(" ")))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",162)
				hx::AddEq(capitalizedText,text.charAt(i).toUpperCase());
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",166)
				hx::AddEq(capitalizedText,text.charAt(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",170)
	return capitalizedText;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontManager_obj,capitalizeText,return )

Void AbstractFontManager_obj::loadFont( ::String url,::String name,Dynamic successCallback,Dynamic errorCallback){
{
		HX_SOURCE_PUSH("AbstractFontManager_obj::loadFont")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",188)
		::cocktail::port::flash_player::FontLoader fontLoader;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",189)
		int idx;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",191)
		{
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",191)
			int _g1 = (int)0;
			int _g = ::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->length;
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",191)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",191)
				int idx1 = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",193)
				if (((bool((::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1)->fontData->__Field(HX_CSTRING("url")) == url)) && bool((::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1)->fontData->__Field(HX_CSTRING("name")) == name))))){
					HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",195)
					::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1)->addCallback(successCallback,errorCallback);
					HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",196)
					return null();
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",200)
		fontLoader = ::cocktail::port::flash_player::FontLoader_obj::__new();
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",201)
		fontLoader->addCallback(this->_onFontLoadingSuccess_dyn(),this->_onFontLoadingError_dyn());
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",202)
		fontLoader->addCallback(successCallback,errorCallback);
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",203)
		fontLoader->load(url,name);
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",204)
		::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->push(fontLoader);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractFontManager_obj,loadFont,(void))

Void AbstractFontManager_obj::_onFontLoadingSuccess( Dynamic fontData){
{
		HX_SOURCE_PUSH("AbstractFontManager_obj::_onFontLoadingSuccess")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",217)
		::cocktail::core::font::AbstractFontManager_obj::_loadedFonts->__Field(HX_CSTRING("push"))(fontData);
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",220)
		if (((this->_removeFontLoader(fontData) == false))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",221)
			::haxe::Log_obj::trace(HX_CSTRING("could not remove font loader from the list after the font was successfully loaded"),hx::SourceInfo(HX_CSTRING("AbstractFontManager.hx"),223,HX_CSTRING("cocktail.core.font.AbstractFontManager"),HX_CSTRING("_onFontLoadingSuccess")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontManager_obj,_onFontLoadingSuccess,(void))

Void AbstractFontManager_obj::_onFontLoadingError( Dynamic fontData,::String errorStr){
{
		HX_SOURCE_PUSH("AbstractFontManager_obj::_onFontLoadingError")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",232)
		::haxe::Log_obj::trace(HX_CSTRING("font loading has failed"),hx::SourceInfo(HX_CSTRING("AbstractFontManager.hx"),232,HX_CSTRING("cocktail.core.font.AbstractFontManager"),HX_CSTRING("_onFontLoadingError")));
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",235)
		if (((this->_removeFontLoader(fontData) == false))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",236)
			::haxe::Log_obj::trace(HX_CSTRING("could not remove font loader from the list after the font loading has failed"),hx::SourceInfo(HX_CSTRING("AbstractFontManager.hx"),238,HX_CSTRING("cocktail.core.font.AbstractFontManager"),HX_CSTRING("_onFontLoadingError")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManager_obj,_onFontLoadingError,(void))

bool AbstractFontManager_obj::_removeFontLoader( Dynamic fontData){
	HX_SOURCE_PUSH("AbstractFontManager_obj::_removeFontLoader")
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",250)
	::cocktail::port::flash_player::FontLoader fontLoader;
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",251)
	int idx;
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",252)
	{
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",252)
		int _g1 = (int)0;
		int _g = ::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->length;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",252)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",252)
			int idx1 = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",254)
			if (((bool((::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1)->fontData->__Field(HX_CSTRING("url")) == fontData->__Field(HX_CSTRING("url")))) && bool((::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1)->fontData->__Field(HX_CSTRING("name")) == fontData->__Field(HX_CSTRING("name"))))))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",256)
				::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->remove(::cocktail::core::font::AbstractFontManager_obj::_fontLoaderArray->__get(idx1));
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",257)
				return true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontManager.hx",260)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontManager_obj,_removeFontLoader,return )

Dynamic AbstractFontManager_obj::_loadedFonts;

Array< ::cocktail::port::flash_player::FontLoader > AbstractFontManager_obj::_fontLoaderArray;


AbstractFontManager_obj::AbstractFontManager_obj()
{
}

void AbstractFontManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractFontManager);
	HX_MARK_END_CLASS();
}

Dynamic AbstractFontManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"hasFont") ) { return hasFont_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"loadFont") ) { return loadFont_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_loadedFonts") ) { return _loadedFonts; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getSystemFonts") ) { return getSystemFonts_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontMetrics") ) { return getFontMetrics_dyn(); }
		if (HX_FIELD_EQ(inName,"capitalizeText") ) { return capitalizeText_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fontLoaderArray") ) { return _fontLoaderArray; }
		if (HX_FIELD_EQ(inName,"getEmbeddedFonts") ) { return getEmbeddedFonts_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_removeFontLoader") ) { return _removeFontLoader_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"applyTextTransform") ) { return applyTextTransform_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_onFontLoadingError") ) { return _onFontLoadingError_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_onFontLoadingSuccess") ) { return _onFontLoadingSuccess_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"createNativeTextElement") ) { return createNativeTextElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractFontManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_loadedFonts") ) { _loadedFonts=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fontLoaderArray") ) { _fontLoaderArray=inValue.Cast< Array< ::cocktail::port::flash_player::FontLoader > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractFontManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_loadedFonts"),
	HX_CSTRING("_fontLoaderArray"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getEmbeddedFonts"),
	HX_CSTRING("getSystemFonts"),
	HX_CSTRING("hasFont"),
	HX_CSTRING("getFontMetrics"),
	HX_CSTRING("createNativeTextElement"),
	HX_CSTRING("applyTextTransform"),
	HX_CSTRING("capitalizeText"),
	HX_CSTRING("loadFont"),
	HX_CSTRING("_onFontLoadingSuccess"),
	HX_CSTRING("_onFontLoadingError"),
	HX_CSTRING("_removeFontLoader"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractFontManager_obj::_loadedFonts,"_loadedFonts");
	HX_MARK_MEMBER_NAME(AbstractFontManager_obj::_fontLoaderArray,"_fontLoaderArray");
};

Class AbstractFontManager_obj::__mClass;

void AbstractFontManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.AbstractFontManager"), hx::TCanCast< AbstractFontManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractFontManager_obj::__boot()
{
	hx::Static(_loadedFonts);
	hx::Static(_fontLoaderArray);
}

} // end namespace cocktail
} // end namespace core
} // end namespace font
