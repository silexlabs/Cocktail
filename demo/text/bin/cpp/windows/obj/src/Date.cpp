#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Date_obj::__construct(int year,int month,int day,int hour,int min,int sec)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",31)
	this->mSeconds = ::__hxcpp_new_date(year,month,day,hour,min,sec);
}
;
	return null();
}

Date_obj::~Date_obj() { }

Dynamic Date_obj::__CreateEmpty() { return  new Date_obj; }
hx::ObjectPtr< Date_obj > Date_obj::__new(int year,int month,int day,int hour,int min,int sec)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(year,month,day,hour,min,sec);
	return result;}

Dynamic Date_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

double Date_obj::getTime( ){
	HX_SOURCE_PUSH("Date_obj::getTime")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",35)
	return (this->mSeconds * 1000.0);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getTime,return )

int Date_obj::getHours( ){
	HX_SOURCE_PUSH("Date_obj::getHours")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",39)
	return ::__hxcpp_get_hours(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getHours,return )

int Date_obj::getMinutes( ){
	HX_SOURCE_PUSH("Date_obj::getMinutes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",41)
	return ::__hxcpp_get_minutes(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getMinutes,return )

int Date_obj::getSeconds( ){
	HX_SOURCE_PUSH("Date_obj::getSeconds")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",43)
	return ::__hxcpp_get_seconds(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getSeconds,return )

int Date_obj::getFullYear( ){
	HX_SOURCE_PUSH("Date_obj::getFullYear")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",45)
	return ::__hxcpp_get_year(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getFullYear,return )

int Date_obj::getMonth( ){
	HX_SOURCE_PUSH("Date_obj::getMonth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",47)
	return ::__hxcpp_get_month(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getMonth,return )

int Date_obj::getDate( ){
	HX_SOURCE_PUSH("Date_obj::getDate")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",49)
	return ::__hxcpp_get_date(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getDate,return )

int Date_obj::getDay( ){
	HX_SOURCE_PUSH("Date_obj::getDay")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",51)
	return ::__hxcpp_get_day(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,getDay,return )

::String Date_obj::toString( ){
	HX_SOURCE_PUSH("Date_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",53)
	return ::__hxcpp_to_string(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,toString,return )

::Date Date_obj::now( ){
	HX_SOURCE_PUSH("Date_obj::now")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",55)
	return ::Date_obj::fromTime((::__hxcpp_date_now() * 1000.0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Date_obj,now,return )

::Date Date_obj::fromTime( double t){
	HX_SOURCE_PUSH("Date_obj::fromTime")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",60)
	::Date result = ::Date_obj::__new((int)0,(int)0,(int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",61)
	result->mSeconds = (t * 0.001);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",62)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Date_obj,fromTime,return )

::Date Date_obj::fromString( ::String s){
	HX_SOURCE_PUSH("Date_obj::fromString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",66)
	switch( (int)(s.length)){
		case (int)8: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",68)
			Array< ::String > k = s.split(HX_CSTRING(":"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",69)
			::Date d = ::Date_obj::__new((int)0,(int)0,(int)0,::Std_obj::parseInt(k->__get((int)0)),::Std_obj::parseInt(k->__get((int)1)),::Std_obj::parseInt(k->__get((int)2)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",70)
			return d;
		}
		;break;
		case (int)10: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",72)
			Array< ::String > k = s.split(HX_CSTRING("-"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",73)
			return ::Date_obj::__new(::Std_obj::parseInt(k->__get((int)0)),(::Std_obj::parseInt(k->__get((int)1)) - (int)1),::Std_obj::parseInt(k->__get((int)2)),(int)0,(int)0,(int)0);
		}
		;break;
		case (int)19: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",75)
			Array< ::String > k = s.split(HX_CSTRING(" "));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",76)
			Array< ::String > y = k->__get((int)0).split(HX_CSTRING("-"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",77)
			Array< ::String > t = k->__get((int)1).split(HX_CSTRING(":"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",78)
			return ::Date_obj::__new(::Std_obj::parseInt(y->__get((int)0)),(::Std_obj::parseInt(y->__get((int)1)) - (int)1),::Std_obj::parseInt(y->__get((int)2)),::Std_obj::parseInt(t->__get((int)0)),::Std_obj::parseInt(t->__get((int)1)),::Std_obj::parseInt(t->__get((int)2)));
		}
		;break;
		default: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",80)
			hx::Throw ((HX_CSTRING("Invalid date format : ") + s));
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Date.hx",83)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Date_obj,fromString,return )


Date_obj::Date_obj()
{
}

void Date_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Date);
	HX_MARK_MEMBER_NAME(mSeconds,"mSeconds");
	HX_MARK_END_CLASS();
}

Dynamic Date_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"now") ) { return now_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"getDay") ) { return getDay_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getTime") ) { return getTime_dyn(); }
		if (HX_FIELD_EQ(inName,"getDate") ) { return getDate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fromTime") ) { return fromTime_dyn(); }
		if (HX_FIELD_EQ(inName,"mSeconds") ) { return mSeconds; }
		if (HX_FIELD_EQ(inName,"getHours") ) { return getHours_dyn(); }
		if (HX_FIELD_EQ(inName,"getMonth") ) { return getMonth_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
		if (HX_FIELD_EQ(inName,"getMinutes") ) { return getMinutes_dyn(); }
		if (HX_FIELD_EQ(inName,"getSeconds") ) { return getSeconds_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getFullYear") ) { return getFullYear_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Date_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mSeconds") ) { mSeconds=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Date_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mSeconds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("now"),
	HX_CSTRING("fromTime"),
	HX_CSTRING("fromString"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mSeconds"),
	HX_CSTRING("getTime"),
	HX_CSTRING("getHours"),
	HX_CSTRING("getMinutes"),
	HX_CSTRING("getSeconds"),
	HX_CSTRING("getFullYear"),
	HX_CSTRING("getMonth"),
	HX_CSTRING("getDate"),
	HX_CSTRING("getDay"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Date_obj::__mClass;

void Date_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Date"), hx::TCanCast< Date_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Date_obj::__boot()
{
}

