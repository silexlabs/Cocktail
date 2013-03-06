#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_ObjectPool
#include <cocktail/core/utils/ObjectPool.h>
#endif
namespace cocktail{
namespace core{
namespace utils{

Void ObjectPool_obj::__construct(::Class pooledClass)
{
HX_STACK_PUSH("ObjectPool::new","cocktail/core/utils/ObjectPool.hx",19);
{
	HX_STACK_LINE(20)
	this->_pooledClass = pooledClass;
	HX_STACK_LINE(21)
	this->_pool = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(22)
	this->_freeObjectIndex = (int)-1;
	HX_STACK_LINE(23)
	this->_args = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

ObjectPool_obj::~ObjectPool_obj() { }

Dynamic ObjectPool_obj::__CreateEmpty() { return  new ObjectPool_obj; }
hx::ObjectPtr< ObjectPool_obj > ObjectPool_obj::__new(::Class pooledClass)
{  hx::ObjectPtr< ObjectPool_obj > result = new ObjectPool_obj();
	result->__construct(pooledClass);
	return result;}

Dynamic ObjectPool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectPool_obj > result = new ObjectPool_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ObjectPool_obj::release( Dynamic object){
{
		HX_STACK_PUSH("ObjectPool::release","cocktail/core/utils/ObjectPool.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(object,"object");
		HX_STACK_LINE(42)
		object->__Field(HX_CSTRING("reset"),true)();
		HX_STACK_LINE(43)
		(this->_freeObjectIndex)++;
		HX_STACK_LINE(44)
		hx::IndexRef((this->_pool).mPtr,this->_freeObjectIndex) = object;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,release,(void))

Dynamic ObjectPool_obj::get( ){
	HX_STACK_PUSH("ObjectPool::get","cocktail/core/utils/ObjectPool.hx",27);
	HX_STACK_THIS(this);
	HX_STACK_LINE(27)
	if (((this->_freeObjectIndex == (int)-1))){
		HX_STACK_LINE(29)
		return ::Type_obj::createInstance(this->_pooledClass,this->_args);
	}
	else{
		HX_STACK_LINE(34)
		Dynamic object = this->_pool->__GetItem(this->_freeObjectIndex);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(35)
		(this->_freeObjectIndex)--;
		HX_STACK_LINE(36)
		return object;
	}
	HX_STACK_LINE(27)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectPool_obj,get,return )


ObjectPool_obj::ObjectPool_obj()
{
}

void ObjectPool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectPool);
	HX_MARK_MEMBER_NAME(_args,"_args");
	HX_MARK_MEMBER_NAME(_pooledClass,"_pooledClass");
	HX_MARK_MEMBER_NAME(_freeObjectIndex,"_freeObjectIndex");
	HX_MARK_MEMBER_NAME(_pool,"_pool");
	HX_MARK_END_CLASS();
}

void ObjectPool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_args,"_args");
	HX_VISIT_MEMBER_NAME(_pooledClass,"_pooledClass");
	HX_VISIT_MEMBER_NAME(_freeObjectIndex,"_freeObjectIndex");
	HX_VISIT_MEMBER_NAME(_pool,"_pool");
}

Dynamic ObjectPool_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_args") ) { return _args; }
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"release") ) { return release_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_pooledClass") ) { return _pooledClass; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_freeObjectIndex") ) { return _freeObjectIndex; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectPool_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_args") ) { _args=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_pooledClass") ) { _pooledClass=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_freeObjectIndex") ) { _freeObjectIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectPool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_args"));
	outFields->push(HX_CSTRING("_pooledClass"));
	outFields->push(HX_CSTRING("_freeObjectIndex"));
	outFields->push(HX_CSTRING("_pool"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("release"),
	HX_CSTRING("get"),
	HX_CSTRING("_args"),
	HX_CSTRING("_pooledClass"),
	HX_CSTRING("_freeObjectIndex"),
	HX_CSTRING("_pool"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectPool_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectPool_obj::__mClass,"__mClass");
};

Class ObjectPool_obj::__mClass;

void ObjectPool_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.utils.ObjectPool"), hx::TCanCast< ObjectPool_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ObjectPool_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace utils
