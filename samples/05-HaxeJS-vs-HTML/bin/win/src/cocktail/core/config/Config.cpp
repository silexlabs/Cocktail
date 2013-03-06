#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
namespace cocktail{
namespace core{
namespace config{

Void Config_obj::__construct()
{
HX_STACK_PUSH("Config::new","cocktail/core/config/Config.hx",223);
{
	HX_STACK_LINE(224)
	this->enableMouseEvent = true;
	HX_STACK_LINE(225)
	this->touchMovePreventClickDistance = (int)10;
	HX_STACK_LINE(226)
	this->enableBitmapSmoothing = true;
	HX_STACK_LINE(227)
	this->useLowStageQuality = false;
	HX_STACK_LINE(228)
	this->enableSynchronousUpdate = true;
	HX_STACK_LINE(229)
	this->useAdvancedHitTesting = true;
	HX_STACK_LINE(230)
	this->useStageVideoIfAvailable = true;
	HX_STACK_LINE(231)
	this->defaultFont = HX_CSTRING("serif");
	HX_STACK_LINE(232)
	this->defaultFontColor = HX_CSTRING("#000000");
	HX_STACK_LINE(234)
	this->xxSmallFontSize = (int)9;
	HX_STACK_LINE(235)
	this->xSmallFontSize = (int)10;
	HX_STACK_LINE(236)
	this->smallFontSize = (int)13;
	HX_STACK_LINE(237)
	this->mediumFontSize = (int)16;
	HX_STACK_LINE(238)
	this->largeFontSize = (int)18;
	HX_STACK_LINE(239)
	this->xLargeFontSize = (int)24;
	HX_STACK_LINE(240)
	this->xxLargeFontSize = (int)32;
	HX_STACK_LINE(242)
	this->thinBorderWidth = (int)1;
	HX_STACK_LINE(243)
	this->mediumBorderWidth = (int)3;
	HX_STACK_LINE(244)
	this->thickBorderWidth = (int)5;
	HX_STACK_LINE(246)
	this->enableCompositing = false;
	HX_STACK_LINE(247)
	this->objectBelowWhenNoCompositing = true;
	HX_STACK_LINE(248)
	this->videoBelowWhenNoCompositing = true;
}
;
	return null();
}

Config_obj::~Config_obj() { }

Dynamic Config_obj::__CreateEmpty() { return  new Config_obj; }
hx::ObjectPtr< Config_obj > Config_obj::__new()
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

Dynamic Config_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

Void Config_obj::updateStringParam( ::String name,::String value){
{
		HX_STACK_PUSH("Config::updateStringParam","cocktail/core/config/Config.hx",319);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(319)
		this->__SetField(name,value,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Config_obj,updateStringParam,(void))

Void Config_obj::updateIntParam( ::String name,::String value){
{
		HX_STACK_PUSH("Config::updateIntParam","cocktail/core/config/Config.hx",307);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(308)
		Dynamic _int = ::Std_obj::parseInt(value);		HX_STACK_VAR(_int,"int");
		HX_STACK_LINE(309)
		if (((_int != null()))){
			HX_STACK_LINE(310)
			this->__SetField(name,_int,false);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Config_obj,updateIntParam,(void))

Void Config_obj::updateBoolParam( ::String name,::String value){
{
		HX_STACK_PUSH("Config::updateBoolParam","cocktail/core/config/Config.hx",291);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(291)
		if (((value == HX_CSTRING("true")))){
			HX_STACK_LINE(293)
			this->__SetField(name,true,false);
		}
		else{
			HX_STACK_LINE(296)
			if (((value == HX_CSTRING("false")))){
				HX_STACK_LINE(297)
				this->__SetField(name,false,false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Config_obj,updateBoolParam,(void))

Void Config_obj::updateConfig( ::String name,::String value){
{
		HX_STACK_PUSH("Config::updateConfig","cocktail/core/config/Config.hx",269);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(269)
		::String _switch_1 = (name);
		if (  ( _switch_1==HX_CSTRING("enableMouseEvent")) ||  ( _switch_1==HX_CSTRING("useLowStageQuality")) ||  ( _switch_1==HX_CSTRING("enableSynchronousUpdate")) ||  ( _switch_1==HX_CSTRING("enableBitmapSmoothing")) ||  ( _switch_1==HX_CSTRING("useAdvancedHitTesting")) ||  ( _switch_1==HX_CSTRING("useStageVideoIfAvailable")) ||  ( _switch_1==HX_CSTRING("enableCompositing")) ||  ( _switch_1==HX_CSTRING("objectBelowWhenNoCompositing")) ||  ( _switch_1==HX_CSTRING("videoBelowWhenNoCompositing"))){
			HX_STACK_LINE(272)
			this->updateBoolParam(name,value);
		}
		else if (  ( _switch_1==HX_CSTRING("touchMovePreventClickDistance")) ||  ( _switch_1==HX_CSTRING("xxSmallFontSize")) ||  ( _switch_1==HX_CSTRING("xSmallFontSize")) ||  ( _switch_1==HX_CSTRING("smallFontSize")) ||  ( _switch_1==HX_CSTRING("mediumFontSize")) ||  ( _switch_1==HX_CSTRING("largeFontSize")) ||  ( _switch_1==HX_CSTRING("xLargeFontSize")) ||  ( _switch_1==HX_CSTRING("xxLargeFontSize")) ||  ( _switch_1==HX_CSTRING("thinBorderWidth")) ||  ( _switch_1==HX_CSTRING("mediumBorderWidth")) ||  ( _switch_1==HX_CSTRING("thickBorderWidth"))){
			HX_STACK_LINE(277)
			this->updateIntParam(name,value);
		}
		else if (  ( _switch_1==HX_CSTRING("defaultFont")) ||  ( _switch_1==HX_CSTRING("defaultFontColor"))){
			HX_STACK_LINE(282)
			this->updateStringParam(name,value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Config_obj,updateConfig,(void))

::cocktail::core::config::Config Config_obj::_instance;

::cocktail::core::config::Config Config_obj::getInstance( ){
	HX_STACK_PUSH("Config::getInstance","cocktail/core/config/Config.hx",255);
	HX_STACK_LINE(256)
	if (((::cocktail::core::config::Config_obj::_instance == null()))){
		HX_STACK_LINE(257)
		::cocktail::core::config::Config_obj::_instance = ::cocktail::core::config::Config_obj::__new();
	}
	HX_STACK_LINE(261)
	return ::cocktail::core::config::Config_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Config_obj,getInstance,return )


Config_obj::Config_obj()
{
}

void Config_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Config);
	HX_MARK_MEMBER_NAME(videoBelowWhenNoCompositing,"videoBelowWhenNoCompositing");
	HX_MARK_MEMBER_NAME(objectBelowWhenNoCompositing,"objectBelowWhenNoCompositing");
	HX_MARK_MEMBER_NAME(enableCompositing,"enableCompositing");
	HX_MARK_MEMBER_NAME(thickBorderWidth,"thickBorderWidth");
	HX_MARK_MEMBER_NAME(mediumBorderWidth,"mediumBorderWidth");
	HX_MARK_MEMBER_NAME(thinBorderWidth,"thinBorderWidth");
	HX_MARK_MEMBER_NAME(xxLargeFontSize,"xxLargeFontSize");
	HX_MARK_MEMBER_NAME(xLargeFontSize,"xLargeFontSize");
	HX_MARK_MEMBER_NAME(largeFontSize,"largeFontSize");
	HX_MARK_MEMBER_NAME(mediumFontSize,"mediumFontSize");
	HX_MARK_MEMBER_NAME(smallFontSize,"smallFontSize");
	HX_MARK_MEMBER_NAME(xSmallFontSize,"xSmallFontSize");
	HX_MARK_MEMBER_NAME(xxSmallFontSize,"xxSmallFontSize");
	HX_MARK_MEMBER_NAME(defaultFontColor,"defaultFontColor");
	HX_MARK_MEMBER_NAME(defaultFont,"defaultFont");
	HX_MARK_MEMBER_NAME(useStageVideoIfAvailable,"useStageVideoIfAvailable");
	HX_MARK_MEMBER_NAME(useAdvancedHitTesting,"useAdvancedHitTesting");
	HX_MARK_MEMBER_NAME(enableSynchronousUpdate,"enableSynchronousUpdate");
	HX_MARK_MEMBER_NAME(useLowStageQuality,"useLowStageQuality");
	HX_MARK_MEMBER_NAME(enableBitmapSmoothing,"enableBitmapSmoothing");
	HX_MARK_MEMBER_NAME(touchMovePreventClickDistance,"touchMovePreventClickDistance");
	HX_MARK_MEMBER_NAME(enableMouseEvent,"enableMouseEvent");
	HX_MARK_END_CLASS();
}

void Config_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(videoBelowWhenNoCompositing,"videoBelowWhenNoCompositing");
	HX_VISIT_MEMBER_NAME(objectBelowWhenNoCompositing,"objectBelowWhenNoCompositing");
	HX_VISIT_MEMBER_NAME(enableCompositing,"enableCompositing");
	HX_VISIT_MEMBER_NAME(thickBorderWidth,"thickBorderWidth");
	HX_VISIT_MEMBER_NAME(mediumBorderWidth,"mediumBorderWidth");
	HX_VISIT_MEMBER_NAME(thinBorderWidth,"thinBorderWidth");
	HX_VISIT_MEMBER_NAME(xxLargeFontSize,"xxLargeFontSize");
	HX_VISIT_MEMBER_NAME(xLargeFontSize,"xLargeFontSize");
	HX_VISIT_MEMBER_NAME(largeFontSize,"largeFontSize");
	HX_VISIT_MEMBER_NAME(mediumFontSize,"mediumFontSize");
	HX_VISIT_MEMBER_NAME(smallFontSize,"smallFontSize");
	HX_VISIT_MEMBER_NAME(xSmallFontSize,"xSmallFontSize");
	HX_VISIT_MEMBER_NAME(xxSmallFontSize,"xxSmallFontSize");
	HX_VISIT_MEMBER_NAME(defaultFontColor,"defaultFontColor");
	HX_VISIT_MEMBER_NAME(defaultFont,"defaultFont");
	HX_VISIT_MEMBER_NAME(useStageVideoIfAvailable,"useStageVideoIfAvailable");
	HX_VISIT_MEMBER_NAME(useAdvancedHitTesting,"useAdvancedHitTesting");
	HX_VISIT_MEMBER_NAME(enableSynchronousUpdate,"enableSynchronousUpdate");
	HX_VISIT_MEMBER_NAME(useLowStageQuality,"useLowStageQuality");
	HX_VISIT_MEMBER_NAME(enableBitmapSmoothing,"enableBitmapSmoothing");
	HX_VISIT_MEMBER_NAME(touchMovePreventClickDistance,"touchMovePreventClickDistance");
	HX_VISIT_MEMBER_NAME(enableMouseEvent,"enableMouseEvent");
}

Dynamic Config_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"defaultFont") ) { return defaultFont; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateConfig") ) { return updateConfig_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"largeFontSize") ) { return largeFontSize; }
		if (HX_FIELD_EQ(inName,"smallFontSize") ) { return smallFontSize; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateIntParam") ) { return updateIntParam_dyn(); }
		if (HX_FIELD_EQ(inName,"xLargeFontSize") ) { return xLargeFontSize; }
		if (HX_FIELD_EQ(inName,"mediumFontSize") ) { return mediumFontSize; }
		if (HX_FIELD_EQ(inName,"xSmallFontSize") ) { return xSmallFontSize; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateBoolParam") ) { return updateBoolParam_dyn(); }
		if (HX_FIELD_EQ(inName,"thinBorderWidth") ) { return thinBorderWidth; }
		if (HX_FIELD_EQ(inName,"xxLargeFontSize") ) { return xxLargeFontSize; }
		if (HX_FIELD_EQ(inName,"xxSmallFontSize") ) { return xxSmallFontSize; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"thickBorderWidth") ) { return thickBorderWidth; }
		if (HX_FIELD_EQ(inName,"defaultFontColor") ) { return defaultFontColor; }
		if (HX_FIELD_EQ(inName,"enableMouseEvent") ) { return enableMouseEvent; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateStringParam") ) { return updateStringParam_dyn(); }
		if (HX_FIELD_EQ(inName,"enableCompositing") ) { return enableCompositing; }
		if (HX_FIELD_EQ(inName,"mediumBorderWidth") ) { return mediumBorderWidth; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"useLowStageQuality") ) { return useLowStageQuality; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"useAdvancedHitTesting") ) { return useAdvancedHitTesting; }
		if (HX_FIELD_EQ(inName,"enableBitmapSmoothing") ) { return enableBitmapSmoothing; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"enableSynchronousUpdate") ) { return enableSynchronousUpdate; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"useStageVideoIfAvailable") ) { return useStageVideoIfAvailable; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"videoBelowWhenNoCompositing") ) { return videoBelowWhenNoCompositing; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"objectBelowWhenNoCompositing") ) { return objectBelowWhenNoCompositing; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"touchMovePreventClickDistance") ) { return touchMovePreventClickDistance; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Config_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::cocktail::core::config::Config >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultFont") ) { defaultFont=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"largeFontSize") ) { largeFontSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"smallFontSize") ) { smallFontSize=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"xLargeFontSize") ) { xLargeFontSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mediumFontSize") ) { mediumFontSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xSmallFontSize") ) { xSmallFontSize=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"thinBorderWidth") ) { thinBorderWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xxLargeFontSize") ) { xxLargeFontSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xxSmallFontSize") ) { xxSmallFontSize=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"thickBorderWidth") ) { thickBorderWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"defaultFontColor") ) { defaultFontColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enableMouseEvent") ) { enableMouseEvent=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"enableCompositing") ) { enableCompositing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mediumBorderWidth") ) { mediumBorderWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"useLowStageQuality") ) { useLowStageQuality=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"useAdvancedHitTesting") ) { useAdvancedHitTesting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enableBitmapSmoothing") ) { enableBitmapSmoothing=inValue.Cast< bool >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"enableSynchronousUpdate") ) { enableSynchronousUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"useStageVideoIfAvailable") ) { useStageVideoIfAvailable=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"videoBelowWhenNoCompositing") ) { videoBelowWhenNoCompositing=inValue.Cast< bool >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"objectBelowWhenNoCompositing") ) { objectBelowWhenNoCompositing=inValue.Cast< bool >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"touchMovePreventClickDistance") ) { touchMovePreventClickDistance=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Config_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("videoBelowWhenNoCompositing"));
	outFields->push(HX_CSTRING("objectBelowWhenNoCompositing"));
	outFields->push(HX_CSTRING("enableCompositing"));
	outFields->push(HX_CSTRING("thickBorderWidth"));
	outFields->push(HX_CSTRING("mediumBorderWidth"));
	outFields->push(HX_CSTRING("thinBorderWidth"));
	outFields->push(HX_CSTRING("xxLargeFontSize"));
	outFields->push(HX_CSTRING("xLargeFontSize"));
	outFields->push(HX_CSTRING("largeFontSize"));
	outFields->push(HX_CSTRING("mediumFontSize"));
	outFields->push(HX_CSTRING("smallFontSize"));
	outFields->push(HX_CSTRING("xSmallFontSize"));
	outFields->push(HX_CSTRING("xxSmallFontSize"));
	outFields->push(HX_CSTRING("defaultFontColor"));
	outFields->push(HX_CSTRING("defaultFont"));
	outFields->push(HX_CSTRING("useStageVideoIfAvailable"));
	outFields->push(HX_CSTRING("useAdvancedHitTesting"));
	outFields->push(HX_CSTRING("enableSynchronousUpdate"));
	outFields->push(HX_CSTRING("useLowStageQuality"));
	outFields->push(HX_CSTRING("enableBitmapSmoothing"));
	outFields->push(HX_CSTRING("touchMovePreventClickDistance"));
	outFields->push(HX_CSTRING("enableMouseEvent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateStringParam"),
	HX_CSTRING("updateIntParam"),
	HX_CSTRING("updateBoolParam"),
	HX_CSTRING("updateConfig"),
	HX_CSTRING("videoBelowWhenNoCompositing"),
	HX_CSTRING("objectBelowWhenNoCompositing"),
	HX_CSTRING("enableCompositing"),
	HX_CSTRING("thickBorderWidth"),
	HX_CSTRING("mediumBorderWidth"),
	HX_CSTRING("thinBorderWidth"),
	HX_CSTRING("xxLargeFontSize"),
	HX_CSTRING("xLargeFontSize"),
	HX_CSTRING("largeFontSize"),
	HX_CSTRING("mediumFontSize"),
	HX_CSTRING("smallFontSize"),
	HX_CSTRING("xSmallFontSize"),
	HX_CSTRING("xxSmallFontSize"),
	HX_CSTRING("defaultFontColor"),
	HX_CSTRING("defaultFont"),
	HX_CSTRING("useStageVideoIfAvailable"),
	HX_CSTRING("useAdvancedHitTesting"),
	HX_CSTRING("enableSynchronousUpdate"),
	HX_CSTRING("useLowStageQuality"),
	HX_CSTRING("enableBitmapSmoothing"),
	HX_CSTRING("touchMovePreventClickDistance"),
	HX_CSTRING("enableMouseEvent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Config_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Config_obj::_instance,"_instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Config_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Config_obj::_instance,"_instance");
};

Class Config_obj::__mClass;

void Config_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.config.Config"), hx::TCanCast< Config_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Config_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace config
