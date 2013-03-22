#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_errors_ArgumentError
#include <neash/errors/ArgumentError.h>
#endif
#ifndef INCLUDED_neash_errors_Error
#include <neash/errors/Error.h>
#endif
#ifndef INCLUDED_neash_errors_RangeError
#include <neash/errors/RangeError.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace neash{
namespace display{

Void DisplayObjectContainer_obj::__construct(Dynamic inHandle,::String inType)
{
HX_STACK_PUSH("DisplayObjectContainer::new","neash/display/DisplayObjectContainer.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct(inHandle,inType);
	HX_STACK_LINE(25)
	this->nmeChildren = Array_obj< ::neash::display::DisplayObject >::__new();
}
;
	return null();
}

DisplayObjectContainer_obj::~DisplayObjectContainer_obj() { }

Dynamic DisplayObjectContainer_obj::__CreateEmpty() { return  new DisplayObjectContainer_obj; }
hx::ObjectPtr< DisplayObjectContainer_obj > DisplayObjectContainer_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic DisplayObjectContainer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool DisplayObjectContainer_obj::nmeSetTabChildren( bool inValue){
	HX_STACK_PUSH("DisplayObjectContainer::nmeSetTabChildren","neash/display/DisplayObjectContainer.hx",355);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inValue,"inValue");
	HX_STACK_LINE(355)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetTabChildren,return )

bool DisplayObjectContainer_obj::nmeGetTabChildren( ){
	HX_STACK_PUSH("DisplayObjectContainer::nmeGetTabChildren","neash/display/DisplayObjectContainer.hx",354);
	HX_STACK_THIS(this);
	HX_STACK_LINE(354)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetTabChildren,return )

int DisplayObjectContainer_obj::nmeGetNumChildren( ){
	HX_STACK_PUSH("DisplayObjectContainer::nmeGetNumChildren","neash/display/DisplayObjectContainer.hx",353);
	HX_STACK_THIS(this);
	HX_STACK_LINE(353)
	return this->nmeChildren->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetNumChildren,return )

bool DisplayObjectContainer_obj::nmeSetMouseChildren( bool inVal){
	HX_STACK_PUSH("DisplayObjectContainer::nmeSetMouseChildren","neash/display/DisplayObjectContainer.hx",347);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(348)
	::neash::display::DisplayObjectContainer_obj::nme_doc_set_mouse_children(this->nmeHandle,inVal);
	HX_STACK_LINE(349)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetMouseChildren,return )

bool DisplayObjectContainer_obj::nmeGetMouseChildren( ){
	HX_STACK_PUSH("DisplayObjectContainer::nmeGetMouseChildren","neash/display/DisplayObjectContainer.hx",345);
	HX_STACK_THIS(this);
	HX_STACK_LINE(345)
	return ::neash::display::DisplayObjectContainer_obj::nme_doc_get_mouse_children(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetMouseChildren,return )

Void DisplayObjectContainer_obj::swapChildrenAt( int index1,int index2){
{
		HX_STACK_PUSH("DisplayObjectContainer::swapChildrenAt","neash/display/DisplayObjectContainer.hx",335);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index1,"index1");
		HX_STACK_ARG(index2,"index2");
		HX_STACK_LINE(336)
		if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
			HX_STACK_LINE(336)
			hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
		}
		HX_STACK_LINE(336)
		if (((index1 != index2))){
			HX_STACK_LINE(336)
			::neash::display::DisplayObject tmp = this->nmeChildren->__get(index1);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(336)
			this->nmeChildren[index1] = this->nmeChildren->__get(index2);
			HX_STACK_LINE(336)
			this->nmeChildren[index2] = tmp;
			HX_STACK_LINE(336)
			::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildrenAt,(void))

Void DisplayObjectContainer_obj::swapChildren( ::neash::display::DisplayObject child1,::neash::display::DisplayObject child2){
{
		HX_STACK_PUSH("DisplayObjectContainer::swapChildren","neash/display/DisplayObjectContainer.hx",325);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child1,"child1");
		HX_STACK_ARG(child2,"child2");
		HX_STACK_LINE(326)
		int idx1 = this->nmeGetChildIndex(child1);		HX_STACK_VAR(idx1,"idx1");
		HX_STACK_LINE(327)
		int idx2 = this->nmeGetChildIndex(child2);		HX_STACK_VAR(idx2,"idx2");
		HX_STACK_LINE(328)
		if (((bool((idx1 < (int)0)) || bool((idx2 < (int)0))))){
			HX_STACK_LINE(329)
			hx::Throw (HX_CSTRING("swapChildren:Could not find children"));
		}
		HX_STACK_LINE(330)
		{
			HX_STACK_LINE(330)
			if (((bool((bool((bool((idx1 < (int)0)) || bool((idx2 < (int)0)))) || bool((idx1 > this->nmeChildren->length)))) || bool((idx2 > this->nmeChildren->length))))){
				HX_STACK_LINE(330)
				hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
			}
			HX_STACK_LINE(330)
			if (((idx1 != idx2))){
				HX_STACK_LINE(330)
				::neash::display::DisplayObject tmp = this->nmeChildren->__get(idx1);		HX_STACK_VAR(tmp,"tmp");
				HX_STACK_LINE(330)
				this->nmeChildren[idx1] = this->nmeChildren->__get(idx2);
				HX_STACK_LINE(330)
				this->nmeChildren[idx2] = tmp;
				HX_STACK_LINE(330)
				::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,idx1,idx2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildren,(void))

Void DisplayObjectContainer_obj::setChildIndex( ::neash::display::DisplayObject child,int index){
{
		HX_STACK_PUSH("DisplayObjectContainer::setChildIndex","neash/display/DisplayObjectContainer.hx",319);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(320)
		if (((index > this->nmeChildren->length))){
			HX_STACK_LINE(320)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_STACK_LINE(320)
		::neash::display::DisplayObject s = null();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(320)
		int orig = this->nmeGetChildIndex(child);		HX_STACK_VAR(orig,"orig");
		HX_STACK_LINE(320)
		if (((orig < (int)0))){
			HX_STACK_LINE(320)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));		HX_STACK_VAR(msg,"msg");
			HX_STACK_LINE(320)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_STACK_LINE(320)
				int realindex = (int)-1;		HX_STACK_VAR(realindex,"realindex");
				HX_STACK_LINE(320)
				{
					HX_STACK_LINE(320)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->nmeChildren->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(320)
					while(((_g1 < _g))){
						HX_STACK_LINE(320)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(320)
						if (((this->nmeChildren->__get(i) == child))){
							HX_STACK_LINE(320)
							realindex = i;
							HX_STACK_LINE(320)
							break;
						}
					}
				}
				HX_STACK_LINE(320)
				if (((realindex != (int)-1))){
					HX_STACK_LINE(320)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_STACK_LINE(320)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_STACK_LINE(320)
			hx::Throw (msg);
		}
		HX_STACK_LINE(320)
		::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_STACK_LINE(320)
		if (((index < orig))){
			HX_STACK_LINE(320)
			int i = orig;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(320)
			while(((i > index))){
				HX_STACK_LINE(320)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_STACK_LINE(320)
				(i)--;
			}
			HX_STACK_LINE(320)
			this->nmeChildren[index] = child;
		}
		else{
			HX_STACK_LINE(320)
			if (((orig < index))){
				HX_STACK_LINE(320)
				int i = orig;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(320)
				while(((i < index))){
					HX_STACK_LINE(320)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_STACK_LINE(320)
					(i)++;
				}
				HX_STACK_LINE(320)
				this->nmeChildren[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,setChildIndex,(void))

::neash::display::DisplayObject DisplayObjectContainer_obj::removeChildAt( int index){
	HX_STACK_PUSH("DisplayObjectContainer::removeChildAt","neash/display/DisplayObjectContainer.hx",306);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(307)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_STACK_LINE(309)
		::neash::display::DisplayObject result = this->nmeChildren->__get(index);		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(310)
		result->nmeSetParent(null());
		HX_STACK_LINE(311)
		return result;
	}
	HX_STACK_LINE(314)
	hx::Throw (::neash::errors::ArgumentError_obj::__new(HX_CSTRING("The supplied DisplayObject must be a child of the caller."),null()));
	HX_STACK_LINE(314)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChildAt,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::removeChild( ::neash::display::DisplayObject child){
	HX_STACK_PUSH("DisplayObjectContainer::removeChild","neash/display/DisplayObjectContainer.hx",290);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(291)
	int c = this->nmeGetChildIndex(child);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(293)
	if (((c >= (int)0))){
		HX_STACK_LINE(295)
		child->nmeSetParent(null());
		HX_STACK_LINE(296)
		return child;
	}
	HX_STACK_LINE(301)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChild,return )

Void DisplayObjectContainer_obj::nmeSwapChildrenAt( int index1,int index2){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeSwapChildrenAt","neash/display/DisplayObjectContainer.hx",275);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index1,"index1");
		HX_STACK_ARG(index2,"index2");
		HX_STACK_LINE(276)
		if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
			HX_STACK_LINE(277)
			hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
		}
		HX_STACK_LINE(279)
		if (((index1 != index2))){
			HX_STACK_LINE(281)
			::neash::display::DisplayObject tmp = this->nmeChildren->__get(index1);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(282)
			this->nmeChildren[index1] = this->nmeChildren->__get(index2);
			HX_STACK_LINE(283)
			this->nmeChildren[index2] = tmp;
			HX_STACK_LINE(284)
			::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSwapChildrenAt,(void))

Void DisplayObjectContainer_obj::nmeSetChildIndex( ::neash::display::DisplayObject child,int index){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeSetChildIndex","neash/display/DisplayObjectContainer.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(213)
		if (((index > this->nmeChildren->length))){
			HX_STACK_LINE(214)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_STACK_LINE(216)
		::neash::display::DisplayObject s = null();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(217)
		int orig = this->nmeGetChildIndex(child);		HX_STACK_VAR(orig,"orig");
		HX_STACK_LINE(219)
		if (((orig < (int)0))){
			HX_STACK_LINE(221)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));		HX_STACK_VAR(msg,"msg");
			HX_STACK_LINE(223)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_STACK_LINE(225)
				int realindex = (int)-1;		HX_STACK_VAR(realindex,"realindex");
				HX_STACK_LINE(227)
				{
					HX_STACK_LINE(227)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->nmeChildren->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(227)
					while(((_g1 < _g))){
						HX_STACK_LINE(227)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(229)
						if (((this->nmeChildren->__get(i) == child))){
							HX_STACK_LINE(231)
							realindex = i;
							HX_STACK_LINE(232)
							break;
						}
					}
				}
				HX_STACK_LINE(236)
				if (((realindex != (int)-1))){
					HX_STACK_LINE(237)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_STACK_LINE(239)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_STACK_LINE(242)
			hx::Throw (msg);
		}
		HX_STACK_LINE(245)
		::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_STACK_LINE(247)
		if (((index < orig))){
			HX_STACK_LINE(249)
			int i = orig;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(251)
			while(((i > index))){
				HX_STACK_LINE(253)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_STACK_LINE(254)
				(i)--;
			}
			HX_STACK_LINE(257)
			this->nmeChildren[index] = child;
		}
		else{
			HX_STACK_LINE(260)
			if (((orig < index))){
				HX_STACK_LINE(262)
				int i = orig;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(263)
				while(((i < index))){
					HX_STACK_LINE(265)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_STACK_LINE(266)
					(i)++;
				}
				HX_STACK_LINE(269)
				this->nmeChildren[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSetChildIndex,(void))

Void DisplayObjectContainer_obj::nmeRemoveChildFromArray( ::neash::display::DisplayObject child){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeRemoveChildFromArray","neash/display/DisplayObjectContainer.hx",200);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(201)
		int i = this->nmeGetChildIndex(child);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(203)
		if (((i >= (int)0))){
			HX_STACK_LINE(205)
			::neash::display::DisplayObjectContainer_obj::nme_doc_remove_child(this->nmeHandle,i);
			HX_STACK_LINE(206)
			this->nmeChildren->splice(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeRemoveChildFromArray,(void))

Void DisplayObjectContainer_obj::nmeOnRemoved( ::neash::display::DisplayObject inObj,bool inWasOnStage){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeOnRemoved","neash/display/DisplayObjectContainer.hx",191);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inObj,"inObj");
		HX_STACK_ARG(inWasOnStage,"inWasOnStage");
		HX_STACK_LINE(192)
		this->super::nmeOnRemoved(inObj,inWasOnStage);
		HX_STACK_LINE(194)
		{
			HX_STACK_LINE(194)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(194)
			while(((_g < _g1->length))){
				HX_STACK_LINE(194)
				::neash::display::DisplayObject child = _g1->__get(_g);		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(194)
				++(_g);
				HX_STACK_LINE(195)
				child->nmeOnRemoved(inObj,inWasOnStage);
			}
		}
	}
return null();
}


Void DisplayObjectContainer_obj::nmeOnAdded( ::neash::display::DisplayObject inObj,bool inIsOnStage){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeOnAdded","neash/display/DisplayObjectContainer.hx",182);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inObj,"inObj");
		HX_STACK_ARG(inIsOnStage,"inIsOnStage");
		HX_STACK_LINE(183)
		this->super::nmeOnAdded(inObj,inIsOnStage);
		HX_STACK_LINE(185)
		{
			HX_STACK_LINE(185)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(185)
			while(((_g < _g1->length))){
				HX_STACK_LINE(185)
				::neash::display::DisplayObject child = _g1->__get(_g);		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(185)
				++(_g);
				HX_STACK_LINE(186)
				child->nmeOnAdded(inObj,inIsOnStage);
			}
		}
	}
return null();
}


Void DisplayObjectContainer_obj::nmeGetObjectsUnderPoint( ::neash::geom::Point point,Array< ::neash::display::DisplayObject > result){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeGetObjectsUnderPoint","neash/display/DisplayObjectContainer.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(174)
		this->super::nmeGetObjectsUnderPoint(point,result);
		HX_STACK_LINE(176)
		{
			HX_STACK_LINE(176)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(176)
			while(((_g < _g1->length))){
				HX_STACK_LINE(176)
				::neash::display::DisplayObject child = _g1->__get(_g);		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(176)
				++(_g);
				HX_STACK_LINE(177)
				child->nmeGetObjectsUnderPoint(point,result);
			}
		}
	}
return null();
}


int DisplayObjectContainer_obj::nmeGetChildIndex( ::neash::display::DisplayObject child){
	HX_STACK_PUSH("DisplayObjectContainer::nmeGetChildIndex","neash/display/DisplayObjectContainer.hx",164);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(165)
	{
		HX_STACK_LINE(165)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->nmeChildren->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(165)
		while(((_g1 < _g))){
			HX_STACK_LINE(165)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(166)
			if (((this->nmeChildren->__get(i) == child))){
				HX_STACK_LINE(167)
				return i;
			}
		}
	}
	HX_STACK_LINE(168)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeGetChildIndex,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::nmeFindByID( int inID){
	HX_STACK_PUSH("DisplayObjectContainer::nmeFindByID","neash/display/DisplayObjectContainer.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inID,"inID");
	HX_STACK_LINE(148)
	if (((this->nmeID == inID))){
		HX_STACK_LINE(149)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(151)
	{
		HX_STACK_LINE(151)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(151)
		while(((_g < _g1->length))){
			HX_STACK_LINE(151)
			::neash::display::DisplayObject child = _g1->__get(_g);		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(151)
			++(_g);
			HX_STACK_LINE(153)
			::neash::display::DisplayObject found = child->nmeFindByID(inID);		HX_STACK_VAR(found,"found");
			HX_STACK_LINE(155)
			if (((found != null()))){
				HX_STACK_LINE(156)
				return found;
			}
		}
	}
	HX_STACK_LINE(159)
	return this->super::nmeFindByID(inID);
}


Void DisplayObjectContainer_obj::nmeBroadcast( ::neash::events::Event inEvt){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeBroadcast","neash/display/DisplayObjectContainer.hx",122);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvt,"inEvt");
		HX_STACK_LINE(123)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(125)
		if (((this->nmeChildren->length > (int)0))){
			HX_STACK_LINE(126)
			while((true)){
				HX_STACK_LINE(128)
				::neash::display::DisplayObject child = this->nmeChildren->__get(i);		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(129)
				child->nmeBroadcast(inEvt);
				HX_STACK_LINE(131)
				if (((i >= this->nmeChildren->length))){
					HX_STACK_LINE(132)
					break;
				}
				HX_STACK_LINE(134)
				if (((this->nmeChildren->__get(i) == child))){
					HX_STACK_LINE(136)
					(i)++;
					HX_STACK_LINE(137)
					if (((i >= this->nmeChildren->length))){
						HX_STACK_LINE(138)
						break;
					}
				}
			}
		}
		HX_STACK_LINE(142)
		this->super::nmeBroadcast(inEvt);
	}
return null();
}


Void DisplayObjectContainer_obj::nmeAddChild( ::neash::display::DisplayObject child){
{
		HX_STACK_PUSH("DisplayObjectContainer::nmeAddChild","neash/display/DisplayObjectContainer.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(103)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(104)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_STACK_LINE(108)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(109)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_STACK_LINE(114)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(115)
			this->nmeChildren->push(child);
			HX_STACK_LINE(116)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeAddChild,(void))

Array< ::neash::display::DisplayObject > DisplayObjectContainer_obj::getObjectsUnderPoint( ::neash::geom::Point point){
	HX_STACK_PUSH("DisplayObjectContainer::getObjectsUnderPoint","neash/display/DisplayObjectContainer.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(95)
	Array< ::neash::display::DisplayObject > result = Array_obj< ::neash::display::DisplayObject >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(96)
	this->nmeGetObjectsUnderPoint(point,result);
	HX_STACK_LINE(97)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getObjectsUnderPoint,return )

int DisplayObjectContainer_obj::getChildIndex( ::neash::display::DisplayObject child){
	HX_STACK_PUSH("DisplayObjectContainer::getChildIndex","neash/display/DisplayObjectContainer.hx",88);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(88)
	return this->nmeGetChildIndex(child);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildIndex,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildByName( ::String name){
	HX_STACK_PUSH("DisplayObjectContainer::getChildByName","neash/display/DisplayObjectContainer.hx",79);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(80)
	{
		HX_STACK_LINE(80)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(80)
		while(((_g < _g1->length))){
			HX_STACK_LINE(80)
			::neash::display::DisplayObject c = _g1->__get(_g);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(80)
			++(_g);
			HX_STACK_LINE(81)
			if (((name == c->nmeGetName()))){
				HX_STACK_LINE(82)
				return c;
			}
		}
	}
	HX_STACK_LINE(83)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildByName,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildAt( int index){
	HX_STACK_PUSH("DisplayObjectContainer::getChildAt","neash/display/DisplayObjectContainer.hx",67);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(68)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_STACK_LINE(69)
		return this->nmeChildren->__get(index);
	}
	HX_STACK_LINE(72)
	hx::Throw (::neash::errors::RangeError_obj::__new((((HX_CSTRING("getChildAt : index out of bounds ") + index) + HX_CSTRING("/")) + this->nmeChildren->length)));
	HX_STACK_LINE(74)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildAt,return )

bool DisplayObjectContainer_obj::contains( ::neash::display::DisplayObject child){
	HX_STACK_PUSH("DisplayObjectContainer::contains","neash/display/DisplayObjectContainer.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(52)
	if (((child == null()))){
		HX_STACK_LINE(53)
		return false;
	}
	HX_STACK_LINE(55)
	if (((hx::ObjectPtr<OBJ_>(this) == child))){
		HX_STACK_LINE(56)
		return true;
	}
	HX_STACK_LINE(58)
	{
		HX_STACK_LINE(58)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(58)
		while(((_g < _g1->length))){
			HX_STACK_LINE(58)
			::neash::display::DisplayObject c = _g1->__get(_g);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(58)
			++(_g);
			HX_STACK_LINE(59)
			if (((c == child))){
				HX_STACK_LINE(60)
				return true;
			}
		}
	}
	HX_STACK_LINE(62)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,contains,return )

bool DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint( ::neash::geom::Point point){
	HX_STACK_PUSH("DisplayObjectContainer::areInaccessibleObjectsUnderPoint","neash/display/DisplayObjectContainer.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(45)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,areInaccessibleObjectsUnderPoint,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::addChildAt( ::neash::display::DisplayObject child,int index){
	HX_STACK_PUSH("DisplayObjectContainer::addChildAt","neash/display/DisplayObjectContainer.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(38)
	{
		HX_STACK_LINE(38)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(38)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_STACK_LINE(38)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(38)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_STACK_LINE(38)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(38)
			this->nmeChildren->push(child);
			HX_STACK_LINE(38)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_STACK_LINE(39)
	{
		HX_STACK_LINE(39)
		if (((index > this->nmeChildren->length))){
			HX_STACK_LINE(39)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_STACK_LINE(39)
		::neash::display::DisplayObject s = null();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(39)
		int orig = this->nmeGetChildIndex(child);		HX_STACK_VAR(orig,"orig");
		HX_STACK_LINE(39)
		if (((orig < (int)0))){
			HX_STACK_LINE(39)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));		HX_STACK_VAR(msg,"msg");
			HX_STACK_LINE(39)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_STACK_LINE(39)
				int realindex = (int)-1;		HX_STACK_VAR(realindex,"realindex");
				HX_STACK_LINE(39)
				{
					HX_STACK_LINE(39)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = this->nmeChildren->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(39)
					while(((_g1 < _g))){
						HX_STACK_LINE(39)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(39)
						if (((this->nmeChildren->__get(i) == child))){
							HX_STACK_LINE(39)
							realindex = i;
							HX_STACK_LINE(39)
							break;
						}
					}
				}
				HX_STACK_LINE(39)
				if (((realindex != (int)-1))){
					HX_STACK_LINE(39)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_STACK_LINE(39)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_STACK_LINE(39)
			hx::Throw (msg);
		}
		HX_STACK_LINE(39)
		::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_STACK_LINE(39)
		if (((index < orig))){
			HX_STACK_LINE(39)
			int i = orig;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(39)
			while(((i > index))){
				HX_STACK_LINE(39)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_STACK_LINE(39)
				(i)--;
			}
			HX_STACK_LINE(39)
			this->nmeChildren[index] = child;
		}
		else{
			HX_STACK_LINE(39)
			if (((orig < index))){
				HX_STACK_LINE(39)
				int i = orig;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(39)
				while(((i < index))){
					HX_STACK_LINE(39)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_STACK_LINE(39)
					(i)++;
				}
				HX_STACK_LINE(39)
				this->nmeChildren[index] = child;
			}
		}
	}
	HX_STACK_LINE(40)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,addChildAt,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::addChild( ::neash::display::DisplayObject child){
	HX_STACK_PUSH("DisplayObjectContainer::addChild","neash/display/DisplayObjectContainer.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(31)
	{
		HX_STACK_LINE(31)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(31)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_STACK_LINE(31)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(31)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_STACK_LINE(31)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(31)
			this->nmeChildren->push(child);
			HX_STACK_LINE(31)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_STACK_LINE(32)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,addChild,return )

Dynamic DisplayObjectContainer_obj::nme_create_display_object_container;

Dynamic DisplayObjectContainer_obj::nme_doc_add_child;

Dynamic DisplayObjectContainer_obj::nme_doc_remove_child;

Dynamic DisplayObjectContainer_obj::nme_doc_set_child_index;

Dynamic DisplayObjectContainer_obj::nme_doc_get_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_set_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_swap_children;


DisplayObjectContainer_obj::DisplayObjectContainer_obj()
{
}

void DisplayObjectContainer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObjectContainer);
	HX_MARK_MEMBER_NAME(nmeChildren,"nmeChildren");
	HX_MARK_MEMBER_NAME(tabChildren,"tabChildren");
	HX_MARK_MEMBER_NAME(numChildren,"numChildren");
	HX_MARK_MEMBER_NAME(mouseChildren,"mouseChildren");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DisplayObjectContainer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeChildren,"nmeChildren");
	HX_VISIT_MEMBER_NAME(tabChildren,"tabChildren");
	HX_VISIT_MEMBER_NAME(numChildren,"numChildren");
	HX_VISIT_MEMBER_NAME(mouseChildren,"mouseChildren");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic DisplayObjectContainer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildAt") ) { return getChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"addChildAt") ) { return addChildAt_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeAddChild") ) { return nmeAddChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { return nmeChildren; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return inCallProp ? nmeGetTabChildren() : tabChildren; }
		if (HX_FIELD_EQ(inName,"numChildren") ) { return inCallProp ? nmeGetNumChildren() : numChildren; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"swapChildren") ) { return swapChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setChildIndex") ) { return setChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChildAt") ) { return removeChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildIndex") ) { return getChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return inCallProp ? nmeGetMouseChildren() : mouseChildren; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"swapChildrenAt") ) { return swapChildrenAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildByName") ) { return getChildByName_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeSetChildIndex") ) { return nmeSetChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetChildIndex") ) { return nmeGetChildIndex_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { return nme_doc_add_child; }
		if (HX_FIELD_EQ(inName,"nmeSetTabChildren") ) { return nmeSetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTabChildren") ) { return nmeGetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumChildren") ) { return nmeGetNumChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSwapChildrenAt") ) { return nmeSwapChildrenAt_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeSetMouseChildren") ) { return nmeSetMouseChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseChildren") ) { return nmeGetMouseChildren_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { return nme_doc_remove_child; }
		if (HX_FIELD_EQ(inName,"getObjectsUnderPoint") ) { return getObjectsUnderPoint_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { return nme_doc_swap_children; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { return nme_doc_set_child_index; }
		if (HX_FIELD_EQ(inName,"nmeRemoveChildFromArray") ) { return nmeRemoveChildFromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { return nme_doc_get_mouse_children; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { return nme_doc_set_mouse_children; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"areInaccessibleObjectsUnderPoint") ) { return areInaccessibleObjectsUnderPoint_dyn(); }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { return nme_create_display_object_container; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObjectContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { nmeChildren=inValue.Cast< Array< ::neash::display::DisplayObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { if (inCallProp) return nmeSetTabChildren(inValue);tabChildren=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numChildren") ) { numChildren=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { if (inCallProp) return nmeSetMouseChildren(inValue);mouseChildren=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { nme_doc_add_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { nme_doc_remove_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { nme_doc_swap_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { nme_doc_set_child_index=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { nme_doc_get_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { nme_doc_set_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { nme_create_display_object_container=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObjectContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeChildren"));
	outFields->push(HX_CSTRING("tabChildren"));
	outFields->push(HX_CSTRING("numChildren"));
	outFields->push(HX_CSTRING("mouseChildren"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_create_display_object_container"),
	HX_CSTRING("nme_doc_add_child"),
	HX_CSTRING("nme_doc_remove_child"),
	HX_CSTRING("nme_doc_set_child_index"),
	HX_CSTRING("nme_doc_get_mouse_children"),
	HX_CSTRING("nme_doc_set_mouse_children"),
	HX_CSTRING("nme_doc_swap_children"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetTabChildren"),
	HX_CSTRING("nmeGetTabChildren"),
	HX_CSTRING("nmeGetNumChildren"),
	HX_CSTRING("nmeSetMouseChildren"),
	HX_CSTRING("nmeGetMouseChildren"),
	HX_CSTRING("swapChildrenAt"),
	HX_CSTRING("swapChildren"),
	HX_CSTRING("setChildIndex"),
	HX_CSTRING("removeChildAt"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("nmeSwapChildrenAt"),
	HX_CSTRING("nmeSetChildIndex"),
	HX_CSTRING("nmeRemoveChildFromArray"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("nmeGetChildIndex"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeAddChild"),
	HX_CSTRING("getObjectsUnderPoint"),
	HX_CSTRING("getChildIndex"),
	HX_CSTRING("getChildByName"),
	HX_CSTRING("getChildAt"),
	HX_CSTRING("contains"),
	HX_CSTRING("areInaccessibleObjectsUnderPoint"),
	HX_CSTRING("addChildAt"),
	HX_CSTRING("addChild"),
	HX_CSTRING("nmeChildren"),
	HX_CSTRING("tabChildren"),
	HX_CSTRING("numChildren"),
	HX_CSTRING("mouseChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_create_display_object_container,"nme_create_display_object_container");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_add_child,"nme_doc_add_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_remove_child,"nme_doc_remove_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_child_index,"nme_doc_set_child_index");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_get_mouse_children,"nme_doc_get_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_mouse_children,"nme_doc_set_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_swap_children,"nme_doc_swap_children");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_create_display_object_container,"nme_create_display_object_container");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_add_child,"nme_doc_add_child");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_remove_child,"nme_doc_remove_child");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_child_index,"nme_doc_set_child_index");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_get_mouse_children,"nme_doc_get_mouse_children");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_mouse_children,"nme_doc_set_mouse_children");
	HX_VISIT_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_swap_children,"nme_doc_swap_children");
};

Class DisplayObjectContainer_obj::__mClass;

void DisplayObjectContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.DisplayObjectContainer"), hx::TCanCast< DisplayObjectContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DisplayObjectContainer_obj::__boot()
{
	nme_create_display_object_container= ::neash::Loader_obj::load(HX_CSTRING("nme_create_display_object_container"),(int)0);
	nme_doc_add_child= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_add_child"),(int)2);
	nme_doc_remove_child= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_remove_child"),(int)2);
	nme_doc_set_child_index= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_set_child_index"),(int)3);
	nme_doc_get_mouse_children= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_get_mouse_children"),(int)1);
	nme_doc_set_mouse_children= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_set_mouse_children"),(int)2);
	nme_doc_swap_children= ::neash::Loader_obj::load(HX_CSTRING("nme_doc_swap_children"),(int)3);
}

} // end namespace neash
} // end namespace display
