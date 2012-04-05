#include <hxcpp.h>

#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
#endif
namespace nme{
namespace errors{

Void Error_obj::__construct(Dynamic inMessage,Dynamic __o_id)
{
Dynamic id = __o_id.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/errors/Error.hx",14)
	this->message = inMessage;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/errors/Error.hx",15)
	this->errorID = id;
}
;
	return null();
}

Error_obj::~Error_obj() { }

Dynamic Error_obj::__CreateEmpty() { return  new Error_obj; }
hx::ObjectPtr< Error_obj > Error_obj::__new(Dynamic inMessage,Dynamic __o_id)
{  hx::ObjectPtr< Error_obj > result = new Error_obj();
	result->__construct(inMessage,__o_id);
	return result;}

Dynamic Error_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Error_obj > result = new Error_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String Error_obj::getStackTrace( ){
	HX_SOURCE_PUSH("Error_obj::getStackTrace")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/errors/Error.hx",20)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC0(Error_obj,getStackTrace,return )

::String Error_obj::toString( ){
	HX_SOURCE_PUSH("Error_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/errors/Error.hx",26)
	return this->message;
}


HX_DEFINE_DYNAMIC_FUNC0(Error_obj,toString,return )


Error_obj::Error_obj()
{
}

void Error_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Error);
	HX_MARK_MEMBER_NAME(errorID,"errorID");
	HX_MARK_MEMBER_NAME(message,"message");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

Dynamic Error_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"errorID") ) { return errorID; }
		if (HX_FIELD_EQ(inName,"message") ) { return message; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getStackTrace") ) { return getStackTrace_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Error_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"errorID") ) { errorID=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"message") ) { message=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Error_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("errorID"));
	outFields->push(HX_CSTRING("message"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("errorID"),
	HX_CSTRING("message"),
	HX_CSTRING("name"),
	HX_CSTRING("getStackTrace"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Error_obj::__mClass;

void Error_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.errors.Error"), hx::TCanCast< Error_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Error_obj::__boot()
{
}

} // end namespace nme
} // end namespace errors
