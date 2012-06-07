#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_errors_ArgumentError
#include <nme/errors/ArgumentError.h>
#endif
#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
#endif
#ifndef INCLUDED_nme_errors_RangeError
#include <nme/errors/RangeError.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace display{

Void DisplayObjectContainer_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",25)
	super::__construct(inHandle,inType);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",26)
	this->nmeChildren = Array_obj< ::nme::display::DisplayObject >::__new();
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

::nme::display::DisplayObject DisplayObjectContainer_obj::addChild( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",32)
			::nme::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",33)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,addChild,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::addChildAt( ::nme::display::DisplayObject child,int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",39)
			::nme::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		if (((index > this->nmeChildren->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		::nme::display::DisplayObject s = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		int orig = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		if (((orig < (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				int realindex = (int)-1;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					int _g1 = (int)0;
					int _g = this->nmeChildren->length;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
						if (((this->nmeChildren->__get(i) == child))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
							realindex = i;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
							break;
						}
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				if (((realindex != (int)-1))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			hx::Throw (msg);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		::nme::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
		if (((index < orig))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			int i = orig;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			while(((i > index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				(i)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			this->nmeChildren[index] = child;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
			if (((orig < index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				while(((i < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
					(i)++;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",40)
				this->nmeChildren[index] = child;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",41)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,addChildAt,return )

bool DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint( ::nme::geom::Point point){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",46)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,areInaccessibleObjectsUnderPoint,return )

bool DisplayObjectContainer_obj::contains( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::contains")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",53)
	if (((child == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",54)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",56)
	if (((hx::ObjectPtr<OBJ_>(this) == child))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",57)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",59)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",59)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",59)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",59)
			::nme::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",59)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",60)
			if (((c == child))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",61)
				return true;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",63)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,contains,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::getChildAt( int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",69)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",70)
		return this->nmeChildren->__get(index);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",73)
	hx::Throw (::nme::errors::RangeError_obj::__new((((HX_CSTRING("getChildAt : index out of bounds ") + index) + HX_CSTRING("/")) + this->nmeChildren->length)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",75)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildAt,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::getChildByName( ::String name){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildByName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",81)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",81)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",81)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",81)
			::nme::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",81)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",82)
			if (((name == c->nmeGetName()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",83)
				return c;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",84)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildByName,return )

int DisplayObjectContainer_obj::getChildIndex( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",89)
	return this->nmeGetChildIndex(child);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildIndex,return )

Array< ::nme::display::DisplayObject > DisplayObjectContainer_obj::getObjectsUnderPoint( ::nme::geom::Point point){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getObjectsUnderPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",96)
	Array< ::nme::display::DisplayObject > result = Array_obj< ::nme::display::DisplayObject >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",97)
	this->nmeGetObjectsUnderPoint(point,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",98)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getObjectsUnderPoint,return )

Void DisplayObjectContainer_obj::nmeAddChild( ::nme::display::DisplayObject child){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeAddChild")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",104)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",105)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",109)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",110)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",115)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",116)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",117)
			::nme::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeAddChild,(void))

Void DisplayObjectContainer_obj::nmeBroadcast( ::nme::events::Event inEvt){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeBroadcast")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",124)
		int i = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",126)
		if (((this->nmeChildren->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",127)
			while((true)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",129)
				::nme::display::DisplayObject child = this->nmeChildren->__get(i);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",130)
				child->nmeBroadcast(inEvt);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",132)
				if (((i >= this->nmeChildren->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",133)
					break;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",135)
				if (((this->nmeChildren->__get(i) == child))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",137)
					(i)++;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",138)
					if (((i >= this->nmeChildren->length))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",139)
						break;
					}
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",143)
		this->super::nmeBroadcast(inEvt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeBroadcast,(void))

::nme::display::DisplayObject DisplayObjectContainer_obj::nmeFindByID( int inID){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeFindByID")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",149)
	if (((this->nmeID == inID))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",150)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",152)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",152)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",152)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",152)
			::nme::display::DisplayObject child = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",152)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",154)
			::nme::display::DisplayObject found = child->nmeFindByID(inID);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",156)
			if (((found != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",157)
				return found;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",160)
	return this->super::nmeFindByID(inID);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeFindByID,return )

int DisplayObjectContainer_obj::nmeGetChildIndex( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetChildIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",166)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",166)
		int _g1 = (int)0;
		int _g = this->nmeChildren->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",166)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",166)
			int i = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",167)
			if (((this->nmeChildren->__get(i) == child))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",168)
				return i;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",169)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeGetChildIndex,return )

Void DisplayObjectContainer_obj::nmeGetObjectsUnderPoint( ::nme::geom::Point point,Array< ::nme::display::DisplayObject > result){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetObjectsUnderPoint")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",175)
		this->super::nmeGetObjectsUnderPoint(point,result);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",177)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",177)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",177)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",177)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",177)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",178)
				this->nmeGetObjectsUnderPoint(point,result);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeGetObjectsUnderPoint,(void))

Void DisplayObjectContainer_obj::nmeOnAdded( ::nme::display::DisplayObject inObj,bool inIsOnStage){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnAdded")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",184)
		this->super::nmeOnAdded(inObj,inIsOnStage);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",186)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",186)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",186)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",186)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",186)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",187)
				child->nmeOnAdded(inObj,inIsOnStage);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeOnAdded,(void))

Void DisplayObjectContainer_obj::nmeOnRemoved( ::nme::display::DisplayObject inObj,bool inWasOnStage){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnRemoved")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",193)
		this->super::nmeOnRemoved(inObj,inWasOnStage);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",195)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",195)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",195)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",195)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",195)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",196)
				child->nmeOnRemoved(inObj,inWasOnStage);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeOnRemoved,(void))

Void DisplayObjectContainer_obj::nmeRemoveChildFromArray( ::nme::display::DisplayObject child){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeRemoveChildFromArray")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",205)
		int i = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",207)
		if (((i >= (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",209)
			::nme::display::DisplayObjectContainer_obj::nme_doc_remove_child(this->nmeHandle,i);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",210)
			this->nmeChildren->splice(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeRemoveChildFromArray,(void))

Void DisplayObjectContainer_obj::nmeSetChildIndex( ::nme::display::DisplayObject child,int index){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetChildIndex")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",217)
		if (((index > this->nmeChildren->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",218)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",220)
		::nme::display::DisplayObject s = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",221)
		int orig = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",223)
		if (((orig < (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",225)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",227)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",229)
				int realindex = (int)-1;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",231)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",231)
					int _g1 = (int)0;
					int _g = this->nmeChildren->length;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",231)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",231)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",233)
						if (((this->nmeChildren->__get(i) == child))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",235)
							realindex = i;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",236)
							break;
						}
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",240)
				if (((realindex != (int)-1))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",241)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",243)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",246)
			hx::Throw (msg);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",249)
		::nme::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",251)
		if (((index < orig))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",253)
			int i = orig;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",255)
			while(((i > index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",257)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",258)
				(i)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",261)
			this->nmeChildren[index] = child;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",264)
			if (((orig < index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",266)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",267)
				while(((i < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",269)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",270)
					(i)++;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",273)
				this->nmeChildren[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSetChildIndex,(void))

Void DisplayObjectContainer_obj::nmeSwapChildrenAt( int index1,int index2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSwapChildrenAt")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",280)
		if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",281)
			hx::Throw (::nme::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",283)
		if (((index1 != index2))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",285)
			::nme::display::DisplayObject tmp = this->nmeChildren->__get(index1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",286)
			this->nmeChildren[index1] = this->nmeChildren->__get(index2);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",287)
			this->nmeChildren[index2] = tmp;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",288)
			::nme::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSwapChildrenAt,(void))

::nme::display::DisplayObject DisplayObjectContainer_obj::removeChild( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",295)
	int c = this->nmeGetChildIndex(child);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",297)
	if (((c >= (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",299)
		child->nmeSetParent(null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",300)
		return child;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",303)
	hx::Throw (::nme::errors::ArgumentError_obj::__new(HX_CSTRING("The supplied DisplayObject must be a child of the caller."),null()));
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChild,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::removeChildAt( int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",309)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",311)
		::nme::display::DisplayObject result = this->nmeChildren->__get(index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",312)
		result->nmeSetParent(null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",313)
		return result;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",316)
	hx::Throw (::nme::errors::ArgumentError_obj::__new(HX_CSTRING("The supplied DisplayObject must be a child of the caller."),null()));
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChildAt,return )

Void DisplayObjectContainer_obj::setChildIndex( ::nme::display::DisplayObject child,int index){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::setChildIndex")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",321)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			if (((index > this->nmeChildren->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				hx::Throw ((HX_CSTRING("Invalid index position ") + index));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			::nme::display::DisplayObject s = null();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			int orig = this->nmeGetChildIndex(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			if (((orig < (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					int realindex = (int)-1;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						int _g1 = (int)0;
						int _g = this->nmeChildren->length;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						while(((_g1 < _g))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
							int i = (_g1)++;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
							if (((this->nmeChildren->__get(i) == child))){
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
								realindex = i;
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
								break;
							}
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					if (((realindex != (int)-1))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				hx::Throw (msg);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			::nme::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
			if (((index < orig))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				while(((i > index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					(i)--;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				this->nmeChildren[index] = child;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
				if (((orig < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					int i = orig;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					while(((i < index))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
						(i)++;
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",322)
					this->nmeChildren[index] = child;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,setChildIndex,(void))

Void DisplayObjectContainer_obj::swapChildren( ::nme::display::DisplayObject child1,::nme::display::DisplayObject child2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildren")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",328)
		int idx1 = this->nmeGetChildIndex(child1);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",329)
		int idx2 = this->nmeGetChildIndex(child2);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",330)
		if (((bool((idx1 < (int)0)) || bool((idx2 < (int)0))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",331)
			hx::Throw (HX_CSTRING("swapChildren:Could not find children"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
			if (((bool((bool((bool((idx1 < (int)0)) || bool((idx2 < (int)0)))) || bool((idx1 > this->nmeChildren->length)))) || bool((idx2 > this->nmeChildren->length))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
				hx::Throw (::nme::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
			if (((idx1 != idx2))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
				::nme::display::DisplayObject tmp = this->nmeChildren->__get(idx1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
				this->nmeChildren[idx1] = this->nmeChildren->__get(idx2);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
				this->nmeChildren[idx2] = tmp;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",332)
				::nme::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,idx1,idx2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildren,(void))

Void DisplayObjectContainer_obj::swapChildrenAt( int index1,int index2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildrenAt")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",337)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
			if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
				hx::Throw (::nme::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
			if (((index1 != index2))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
				::nme::display::DisplayObject tmp = this->nmeChildren->__get(index1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
				this->nmeChildren[index1] = this->nmeChildren->__get(index2);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
				this->nmeChildren[index2] = tmp;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",338)
				::nme::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildrenAt,(void))

bool DisplayObjectContainer_obj::nmeGetMouseChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetMouseChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",347)
	return ::nme::display::DisplayObjectContainer_obj::nme_doc_get_mouse_children(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetMouseChildren,return )

bool DisplayObjectContainer_obj::nmeSetMouseChildren( bool inVal){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetMouseChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",350)
	::nme::display::DisplayObjectContainer_obj::nme_doc_set_mouse_children(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",351)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetMouseChildren,return )

int DisplayObjectContainer_obj::nmeGetNumChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetNumChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",355)
	return this->nmeChildren->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetNumChildren,return )

bool DisplayObjectContainer_obj::nmeGetTabChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetTabChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",356)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetTabChildren,return )

bool DisplayObjectContainer_obj::nmeSetTabChildren( bool inValue){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetTabChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/DisplayObjectContainer.hx",357)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetTabChildren,return )

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
	HX_MARK_MEMBER_NAME(mouseChildren,"mouseChildren");
	HX_MARK_MEMBER_NAME(numChildren,"numChildren");
	HX_MARK_MEMBER_NAME(tabChildren,"tabChildren");
	HX_MARK_MEMBER_NAME(nmeChildren,"nmeChildren");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic DisplayObjectContainer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addChildAt") ) { return addChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildAt") ) { return getChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { return nmeGetNumChildren(); }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return nmeGetTabChildren(); }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { return nmeChildren; }
		if (HX_FIELD_EQ(inName,"nmeAddChild") ) { return nmeAddChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildren") ) { return swapChildren_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return nmeGetMouseChildren(); }
		if (HX_FIELD_EQ(inName,"getChildIndex") ) { return getChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChildAt") ) { return removeChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"setChildIndex") ) { return setChildIndex_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getChildByName") ) { return getChildByName_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildrenAt") ) { return swapChildrenAt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeGetChildIndex") ) { return nmeGetChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetChildIndex") ) { return nmeSetChildIndex_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { return nme_doc_add_child; }
		if (HX_FIELD_EQ(inName,"nmeSwapChildrenAt") ) { return nmeSwapChildrenAt_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumChildren") ) { return nmeGetNumChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTabChildren") ) { return nmeGetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTabChildren") ) { return nmeSetTabChildren_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetMouseChildren") ) { return nmeGetMouseChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMouseChildren") ) { return nmeSetMouseChildren_dyn(); }
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
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeRemoveChildFromArray") ) { return nmeRemoveChildFromArray_dyn(); }
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
	return super::__Field(inName);
}

Dynamic DisplayObjectContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { numChildren=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return nmeSetTabChildren(inValue); }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { nmeChildren=inValue.Cast< Array< ::nme::display::DisplayObject > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return nmeSetMouseChildren(inValue); }
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
	return super::__SetField(inName,inValue);
}

void DisplayObjectContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouseChildren"));
	outFields->push(HX_CSTRING("numChildren"));
	outFields->push(HX_CSTRING("tabChildren"));
	outFields->push(HX_CSTRING("nmeChildren"));
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
	HX_CSTRING("mouseChildren"),
	HX_CSTRING("numChildren"),
	HX_CSTRING("tabChildren"),
	HX_CSTRING("nmeChildren"),
	HX_CSTRING("addChild"),
	HX_CSTRING("addChildAt"),
	HX_CSTRING("areInaccessibleObjectsUnderPoint"),
	HX_CSTRING("contains"),
	HX_CSTRING("getChildAt"),
	HX_CSTRING("getChildByName"),
	HX_CSTRING("getChildIndex"),
	HX_CSTRING("getObjectsUnderPoint"),
	HX_CSTRING("nmeAddChild"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeGetChildIndex"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("nmeRemoveChildFromArray"),
	HX_CSTRING("nmeSetChildIndex"),
	HX_CSTRING("nmeSwapChildrenAt"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("removeChildAt"),
	HX_CSTRING("setChildIndex"),
	HX_CSTRING("swapChildren"),
	HX_CSTRING("swapChildrenAt"),
	HX_CSTRING("nmeGetMouseChildren"),
	HX_CSTRING("nmeSetMouseChildren"),
	HX_CSTRING("nmeGetNumChildren"),
	HX_CSTRING("nmeGetTabChildren"),
	HX_CSTRING("nmeSetTabChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_create_display_object_container,"nme_create_display_object_container");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_add_child,"nme_doc_add_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_remove_child,"nme_doc_remove_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_child_index,"nme_doc_set_child_index");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_get_mouse_children,"nme_doc_get_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_mouse_children,"nme_doc_set_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_swap_children,"nme_doc_swap_children");
};

Class DisplayObjectContainer_obj::__mClass;

void DisplayObjectContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.DisplayObjectContainer"), hx::TCanCast< DisplayObjectContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObjectContainer_obj::__boot()
{
	hx::Static(nme_create_display_object_container) = ::nme::Loader_obj::load(HX_CSTRING("nme_create_display_object_container"),(int)0);
	hx::Static(nme_doc_add_child) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_add_child"),(int)2);
	hx::Static(nme_doc_remove_child) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_remove_child"),(int)2);
	hx::Static(nme_doc_set_child_index) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_set_child_index"),(int)3);
	hx::Static(nme_doc_get_mouse_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_get_mouse_children"),(int)1);
	hx::Static(nme_doc_set_mouse_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_set_mouse_children"),(int)2);
	hx::Static(nme_doc_swap_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_swap_children"),(int)3);
}

} // end namespace nme
} // end namespace display
