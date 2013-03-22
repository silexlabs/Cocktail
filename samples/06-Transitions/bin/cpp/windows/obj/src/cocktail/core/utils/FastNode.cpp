#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace utils{

Void FastNode_obj::__construct()
{
HX_STACK_PUSH("FastNode::new","cocktail/core/utils/FastNode.hx",21);
{
}
;
	return null();
}

FastNode_obj::~FastNode_obj() { }

Dynamic FastNode_obj::__CreateEmpty() { return  new FastNode_obj; }
hx::ObjectPtr< FastNode_obj > FastNode_obj::__new()
{  hx::ObjectPtr< FastNode_obj > result = new FastNode_obj();
	result->__construct();
	return result;}

Dynamic FastNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastNode_obj > result = new FastNode_obj();
	result->__construct();
	return result;}

Void FastNode_obj::insertBefore( Dynamic newChild,Dynamic refChild){
{
		HX_STACK_PUSH("FastNode::insertBefore","cocktail/core/utils/FastNode.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newChild,"newChild");
		HX_STACK_ARG(refChild,"refChild");
		HX_STACK_LINE(98)
		if (((bool((this->firstChild == null())) || bool((refChild == null()))))){
			HX_STACK_LINE(100)
			this->appendChild(newChild);
			HX_STACK_LINE(101)
			return null();
		}
		HX_STACK_LINE(104)
		this->removeFromParentIfNecessary(newChild);
		HX_STACK_LINE(105)
		newChild->__FieldRef(HX_CSTRING("parentNode")) = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(107)
		Dynamic oldPreviousSibling = refChild->__Field(HX_CSTRING("previousSibling"),true);		HX_STACK_VAR(oldPreviousSibling,"oldPreviousSibling");
		HX_STACK_LINE(108)
		if (((oldPreviousSibling == null()))){
			HX_STACK_LINE(110)
			this->firstChild = newChild;
			HX_STACK_LINE(111)
			refChild->__FieldRef(HX_CSTRING("previousSibling")) = newChild;
			HX_STACK_LINE(112)
			newChild->__FieldRef(HX_CSTRING("nextSibling")) = refChild;
			HX_STACK_LINE(113)
			newChild->__FieldRef(HX_CSTRING("previousSibling")) = null();
		}
		else{
			HX_STACK_LINE(117)
			oldPreviousSibling->__FieldRef(HX_CSTRING("nextSibling")) = newChild;
			HX_STACK_LINE(118)
			refChild->__FieldRef(HX_CSTRING("previousSibling")) = newChild;
			HX_STACK_LINE(120)
			newChild->__FieldRef(HX_CSTRING("previousSibling")) = oldPreviousSibling;
			HX_STACK_LINE(121)
			newChild->__FieldRef(HX_CSTRING("nextSibling")) = refChild;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FastNode_obj,insertBefore,(void))

Void FastNode_obj::removeFromParentIfNecessary( Dynamic newChild){
{
		HX_STACK_PUSH("FastNode::removeFromParentIfNecessary","cocktail/core/utils/FastNode.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newChild,"newChild");
		HX_STACK_LINE(88)
		if (((newChild->__Field(HX_CSTRING("parentNode"),true) != null()))){
			HX_STACK_LINE(91)
			Dynamic parentNode = newChild->__Field(HX_CSTRING("parentNode"),true);		HX_STACK_VAR(parentNode,"parentNode");
			HX_STACK_LINE(92)
			parentNode->__Field(HX_CSTRING("removeChild"),true)(newChild);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FastNode_obj,removeFromParentIfNecessary,(void))

Void FastNode_obj::appendChild( Dynamic newChild){
{
		HX_STACK_PUSH("FastNode::appendChild","cocktail/core/utils/FastNode.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newChild,"newChild");
		HX_STACK_LINE(67)
		this->removeFromParentIfNecessary(newChild);
		HX_STACK_LINE(68)
		newChild->__FieldRef(HX_CSTRING("parentNode")) = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(70)
		if (((this->firstChild == null()))){
			HX_STACK_LINE(72)
			this->firstChild = newChild;
			HX_STACK_LINE(73)
			this->lastChild = newChild;
			HX_STACK_LINE(74)
			newChild->__FieldRef(HX_CSTRING("previousSibling")) = null();
			HX_STACK_LINE(75)
			newChild->__FieldRef(HX_CSTRING("nextSibling")) = null();
		}
		else{
			HX_STACK_LINE(79)
			Dynamic oldLastChild = this->lastChild;		HX_STACK_VAR(oldLastChild,"oldLastChild");
			HX_STACK_LINE(80)
			this->lastChild = newChild;
			HX_STACK_LINE(81)
			oldLastChild->__FieldRef(HX_CSTRING("nextSibling")) = newChild;
			HX_STACK_LINE(82)
			newChild->__FieldRef(HX_CSTRING("previousSibling")) = oldLastChild;
			HX_STACK_LINE(83)
			newChild->__FieldRef(HX_CSTRING("nextSibling")) = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FastNode_obj,appendChild,(void))

Void FastNode_obj::removeChild( Dynamic oldChild){
{
		HX_STACK_PUSH("FastNode::removeChild","cocktail/core/utils/FastNode.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_ARG(oldChild,"oldChild");
		HX_STACK_LINE(27)
		oldChild->__FieldRef(HX_CSTRING("parentNode")) = null();
		HX_STACK_LINE(29)
		if (((bool((this->firstChild == oldChild)) && bool((this->lastChild == oldChild))))){
			HX_STACK_LINE(31)
			this->firstChild = null();
			HX_STACK_LINE(32)
			this->lastChild = null();
		}
		else{
			HX_STACK_LINE(34)
			if (((this->firstChild == oldChild))){
				HX_STACK_LINE(36)
				Dynamic nextSibling = oldChild->__Field(HX_CSTRING("nextSibling"),true);		HX_STACK_VAR(nextSibling,"nextSibling");
				HX_STACK_LINE(37)
				this->firstChild = nextSibling;
				HX_STACK_LINE(38)
				if (((nextSibling != null()))){
					HX_STACK_LINE(39)
					nextSibling->__FieldRef(HX_CSTRING("previousSibling")) = null();
				}
			}
			else{
				HX_STACK_LINE(43)
				if (((this->lastChild == oldChild))){
					HX_STACK_LINE(45)
					Dynamic previousSibling = oldChild->__Field(HX_CSTRING("previousSibling"),true);		HX_STACK_VAR(previousSibling,"previousSibling");
					HX_STACK_LINE(46)
					this->lastChild = previousSibling;
					HX_STACK_LINE(47)
					if (((previousSibling != null()))){
						HX_STACK_LINE(48)
						previousSibling->__FieldRef(HX_CSTRING("nextSibling")) = null();
					}
				}
				else{
					HX_STACK_LINE(54)
					Dynamic previousSibling = oldChild->__Field(HX_CSTRING("previousSibling"),true);		HX_STACK_VAR(previousSibling,"previousSibling");
					HX_STACK_LINE(55)
					Dynamic nextSibling = oldChild->__Field(HX_CSTRING("nextSibling"),true);		HX_STACK_VAR(nextSibling,"nextSibling");
					HX_STACK_LINE(57)
					previousSibling->__FieldRef(HX_CSTRING("nextSibling")) = nextSibling;
					HX_STACK_LINE(58)
					nextSibling->__FieldRef(HX_CSTRING("previousSibling")) = previousSibling;
				}
			}
		}
		HX_STACK_LINE(61)
		oldChild->__FieldRef(HX_CSTRING("previousSibling")) = null();
		HX_STACK_LINE(62)
		oldChild->__FieldRef(HX_CSTRING("nextSibling")) = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FastNode_obj,removeChild,(void))


FastNode_obj::FastNode_obj()
{
}

void FastNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FastNode);
	HX_MARK_MEMBER_NAME(previousSibling,"previousSibling");
	HX_MARK_MEMBER_NAME(nextSibling,"nextSibling");
	HX_MARK_MEMBER_NAME(lastChild,"lastChild");
	HX_MARK_MEMBER_NAME(firstChild,"firstChild");
	HX_MARK_MEMBER_NAME(parentNode,"parentNode");
	HX_MARK_END_CLASS();
}

void FastNode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(previousSibling,"previousSibling");
	HX_VISIT_MEMBER_NAME(nextSibling,"nextSibling");
	HX_VISIT_MEMBER_NAME(lastChild,"lastChild");
	HX_VISIT_MEMBER_NAME(firstChild,"firstChild");
	HX_VISIT_MEMBER_NAME(parentNode,"parentNode");
}

Dynamic FastNode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lastChild") ) { return lastChild; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstChild") ) { return firstChild; }
		if (HX_FIELD_EQ(inName,"parentNode") ) { return parentNode; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { return nextSibling; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { return previousSibling; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"removeFromParentIfNecessary") ) { return removeFromParentIfNecessary_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FastNode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lastChild") ) { lastChild=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstChild") ) { firstChild=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parentNode") ) { parentNode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nextSibling") ) { nextSibling=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { previousSibling=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FastNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("previousSibling"));
	outFields->push(HX_CSTRING("nextSibling"));
	outFields->push(HX_CSTRING("lastChild"));
	outFields->push(HX_CSTRING("firstChild"));
	outFields->push(HX_CSTRING("parentNode"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("insertBefore"),
	HX_CSTRING("removeFromParentIfNecessary"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("previousSibling"),
	HX_CSTRING("nextSibling"),
	HX_CSTRING("lastChild"),
	HX_CSTRING("firstChild"),
	HX_CSTRING("parentNode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FastNode_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FastNode_obj::__mClass,"__mClass");
};

Class FastNode_obj::__mClass;

void FastNode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.utils.FastNode"), hx::TCanCast< FastNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FastNode_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace utils
