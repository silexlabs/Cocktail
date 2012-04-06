#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_font_AbstractFontLoader
#include <cocktail/core/font/AbstractFontLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontType
#include <cocktail/core/font/FontType.h>
#endif
namespace cocktail{
namespace core{
namespace font{

Void AbstractFontLoader_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",40)
	this->_successCallbackArray = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",41)
	this->_errorCallbackArray = Dynamic( Array_obj<Dynamic>::__new() );
}
;
	return null();
}

AbstractFontLoader_obj::~AbstractFontLoader_obj() { }

Dynamic AbstractFontLoader_obj::__CreateEmpty() { return  new AbstractFontLoader_obj; }
hx::ObjectPtr< AbstractFontLoader_obj > AbstractFontLoader_obj::__new()
{  hx::ObjectPtr< AbstractFontLoader_obj > result = new AbstractFontLoader_obj();
	result->__construct();
	return result;}

Dynamic AbstractFontLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractFontLoader_obj > result = new AbstractFontLoader_obj();
	result->__construct();
	return result;}

Void AbstractFontLoader_obj::load( ::String url,::String name){
{
		HX_SOURCE_PUSH("AbstractFontLoader_obj::load")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",60)
		::String extension = url.substr(url.lastIndexOf(HX_CSTRING("."),null()),url.length);
		struct _Function_1_1{
			inline static Dynamic Block( ::String &url,::String &name){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("url") , url,false);
				__result->Add(HX_CSTRING("name") , name,false);
				__result->Add(HX_CSTRING("type") , ::cocktail::core::font::FontType_obj::unknown_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",61)
		this->fontData = _Function_1_1::Block(url,name);
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",68)
		if (((extension == HX_CSTRING(".ttf")))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",69)
			this->fontData->__FieldRef(HX_CSTRING("type")) = ::cocktail::core::font::FontType_obj::ttf_dyn();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",70)
			if (((extension == HX_CSTRING(".eot")))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",71)
				this->fontData->__FieldRef(HX_CSTRING("type")) = ::cocktail::core::font::FontType_obj::eot_dyn();
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",72)
				if (((extension == HX_CSTRING(".otf")))){
					HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",73)
					this->fontData->__FieldRef(HX_CSTRING("type")) = ::cocktail::core::font::FontType_obj::otf_dyn();
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",74)
					if (((extension == HX_CSTRING(".swf")))){
						HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",75)
						this->fontData->__FieldRef(HX_CSTRING("type")) = ::cocktail::core::font::FontType_obj::swf_dyn();
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",77)
						this->fontData->__FieldRef(HX_CSTRING("type")) = ::cocktail::core::font::FontType_obj::unknown_dyn();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontLoader_obj,load,(void))

Void AbstractFontLoader_obj::addCallback( Dynamic successCallback,Dynamic errorCallback){
{
		HX_SOURCE_PUSH("AbstractFontLoader_obj::addCallback")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",89)
		if (((successCallback != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",90)
			this->_successCallbackArray->__Field(HX_CSTRING("push"))(successCallback);
		}
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",93)
		if (((errorCallback != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",94)
			this->_errorCallbackArray->__Field(HX_CSTRING("push"))(errorCallback);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontLoader_obj,addCallback,(void))

Void AbstractFontLoader_obj::_successCallback( ){
{
		HX_SOURCE_PUSH("AbstractFontLoader_obj::_successCallback")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",105)
		int idx;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",106)
		{
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",106)
			int _g1 = (int)0;
			int _g = this->_successCallbackArray->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",106)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",106)
				int idx1 = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",107)
				this->_successCallbackArray->__GetItem(idx1)(this->fontData).Cast< Void >();
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",110)
		this->cleanup();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFontLoader_obj,_successCallback,(void))

Void AbstractFontLoader_obj::_errorCallback( ::String errorStr){
{
		HX_SOURCE_PUSH("AbstractFontLoader_obj::_errorCallback")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",118)
		int idx;
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",119)
		{
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",119)
			int _g1 = (int)0;
			int _g = this->_errorCallbackArray->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",119)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",119)
				int idx1 = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",120)
				this->_errorCallbackArray->__GetItem(idx1)(this->fontData,errorStr).Cast< Void >();
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",123)
		this->cleanup();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontLoader_obj,_errorCallback,(void))

Void AbstractFontLoader_obj::cleanup( ){
{
		HX_SOURCE_PUSH("AbstractFontLoader_obj::cleanup")
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",130)
		while(((this->_successCallbackArray->__Field(HX_CSTRING("length")) > (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",131)
			this->_successCallbackArray->__Field(HX_CSTRING("pop"))();
		}
		HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",132)
		while(((this->_errorCallbackArray->__Field(HX_CSTRING("length")) > (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/font/AbstractFontLoader.hx",133)
			this->_errorCallbackArray->__Field(HX_CSTRING("pop"))();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFontLoader_obj,cleanup,(void))


AbstractFontLoader_obj::AbstractFontLoader_obj()
{
}

void AbstractFontLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractFontLoader);
	HX_MARK_MEMBER_NAME(fontData,"fontData");
	HX_MARK_MEMBER_NAME(_successCallbackArray,"_successCallbackArray");
	HX_MARK_MEMBER_NAME(_errorCallbackArray,"_errorCallbackArray");
	HX_MARK_END_CLASS();
}

Dynamic AbstractFontLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cleanup") ) { return cleanup_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fontData") ) { return fontData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addCallback") ) { return addCallback_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_errorCallback") ) { return _errorCallback_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_successCallback") ) { return _successCallback_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_errorCallbackArray") ) { return _errorCallbackArray; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_successCallbackArray") ) { return _successCallbackArray; }
	}
	return super::__Field(inName);
}

Dynamic AbstractFontLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"fontData") ) { fontData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_errorCallbackArray") ) { _errorCallbackArray=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_successCallbackArray") ) { _successCallbackArray=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractFontLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fontData"));
	outFields->push(HX_CSTRING("_successCallbackArray"));
	outFields->push(HX_CSTRING("_errorCallbackArray"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("fontData"),
	HX_CSTRING("_successCallbackArray"),
	HX_CSTRING("_errorCallbackArray"),
	HX_CSTRING("load"),
	HX_CSTRING("addCallback"),
	HX_CSTRING("_successCallback"),
	HX_CSTRING("_errorCallback"),
	HX_CSTRING("cleanup"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractFontLoader_obj::__mClass;

void AbstractFontLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.AbstractFontLoader"), hx::TCanCast< AbstractFontLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractFontLoader_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace font
