#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_font_AbstractFontLoader
#include <cocktail/core/font/AbstractFontLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontType
#include <cocktail/core/font/FontType.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_FontLoader
#include <cocktail/port/flash_player/FontLoader.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void FontLoader_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",31)
	super::__construct();
}
;
	return null();
}

FontLoader_obj::~FontLoader_obj() { }

Dynamic FontLoader_obj::__CreateEmpty() { return  new FontLoader_obj; }
hx::ObjectPtr< FontLoader_obj > FontLoader_obj::__new()
{  hx::ObjectPtr< FontLoader_obj > result = new FontLoader_obj();
	result->__construct();
	return result;}

Dynamic FontLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontLoader_obj > result = new FontLoader_obj();
	result->__construct();
	return result;}

Void FontLoader_obj::load( ::String url,::String name){
{
		HX_SOURCE_PUSH("FontLoader_obj::load")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",50)
		this->super::load(url,name);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",53)
		if (((bool((this->fontData->__Field(HX_CSTRING("type")) == ::cocktail::core::font::FontType_obj::swf_dyn())) || bool((this->fontData->__Field(HX_CSTRING("type")) == ::cocktail::core::font::FontType_obj::unknown_dyn()))))){
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",61)
			::haxe::Log_obj::trace((HX_CSTRING("Could not load font, the font format is not appropriate for the target: ") + url),hx::SourceInfo(HX_CSTRING("FontLoader.hx"),61,HX_CSTRING("cocktail.port.flash_player.FontLoader"),HX_CSTRING("load")));
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",62)
			this->_onLoadError((HX_CSTRING("Could not load font, the font format is not appropriate for the target: ") + url));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FontLoader_obj,load,(void))

Void FontLoader_obj::_onLoadComplete( Dynamic data){
{
		HX_SOURCE_PUSH("FontLoader_obj::_onLoadComplete")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",76)
		::haxe::Log_obj::trace(HX_CSTRING("onLoadComplete"),hx::SourceInfo(HX_CSTRING("FontLoader.hx"),76,HX_CSTRING("cocktail.port.flash_player.FontLoader"),HX_CSTRING("_onLoadComplete")));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",77)
		this->_successCallback();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FontLoader_obj,_onLoadComplete,(void))

Void FontLoader_obj::_onLoadError( Dynamic data){
{
		HX_SOURCE_PUSH("FontLoader_obj::_onLoadError")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",85)
		::haxe::Log_obj::trace(HX_CSTRING("onLoadError"),hx::SourceInfo(HX_CSTRING("FontLoader.hx"),85,HX_CSTRING("cocktail.port.flash_player.FontLoader"),HX_CSTRING("_onLoadError")));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/FontLoader.hx",86)
		this->_errorCallback(data);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FontLoader_obj,_onLoadError,(void))


FontLoader_obj::FontLoader_obj()
{
}

void FontLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontLoader);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FontLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onLoadError") ) { return _onLoadError_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_onLoadComplete") ) { return _onLoadComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FontLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FontLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("load"),
	HX_CSTRING("_onLoadComplete"),
	HX_CSTRING("_onLoadError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FontLoader_obj::__mClass;

void FontLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.FontLoader"), hx::TCanCast< FontLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontLoader_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
