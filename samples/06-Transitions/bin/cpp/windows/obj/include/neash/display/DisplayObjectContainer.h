#ifndef INCLUDED_neash_display_DisplayObjectContainer
#define INCLUDED_neash_display_DisplayObjectContainer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/InteractiveObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace neash{
namespace display{


class DisplayObjectContainer_obj : public ::neash::display::InteractiveObject_obj{
	public:
		typedef ::neash::display::InteractiveObject_obj super;
		typedef DisplayObjectContainer_obj OBJ_;
		DisplayObjectContainer_obj();
		Void __construct(Dynamic inHandle,::String inType);

	public:
		static hx::ObjectPtr< DisplayObjectContainer_obj > __new(Dynamic inHandle,::String inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayObjectContainer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DisplayObjectContainer"); }

		virtual bool nmeSetTabChildren( bool inValue);
		Dynamic nmeSetTabChildren_dyn();

		virtual bool nmeGetTabChildren( );
		Dynamic nmeGetTabChildren_dyn();

		virtual int nmeGetNumChildren( );
		Dynamic nmeGetNumChildren_dyn();

		virtual bool nmeSetMouseChildren( bool inVal);
		Dynamic nmeSetMouseChildren_dyn();

		virtual bool nmeGetMouseChildren( );
		Dynamic nmeGetMouseChildren_dyn();

		virtual Void swapChildrenAt( int index1,int index2);
		Dynamic swapChildrenAt_dyn();

		virtual Void swapChildren( ::neash::display::DisplayObject child1,::neash::display::DisplayObject child2);
		Dynamic swapChildren_dyn();

		virtual Void setChildIndex( ::neash::display::DisplayObject child,int index);
		Dynamic setChildIndex_dyn();

		virtual ::neash::display::DisplayObject removeChildAt( int index);
		Dynamic removeChildAt_dyn();

		virtual ::neash::display::DisplayObject removeChild( ::neash::display::DisplayObject child);
		Dynamic removeChild_dyn();

		virtual Void nmeSwapChildrenAt( int index1,int index2);
		Dynamic nmeSwapChildrenAt_dyn();

		virtual Void nmeSetChildIndex( ::neash::display::DisplayObject child,int index);
		Dynamic nmeSetChildIndex_dyn();

		virtual Void nmeRemoveChildFromArray( ::neash::display::DisplayObject child);
		Dynamic nmeRemoveChildFromArray_dyn();

		virtual Void nmeOnRemoved( ::neash::display::DisplayObject inObj,bool inWasOnStage);

		virtual Void nmeOnAdded( ::neash::display::DisplayObject inObj,bool inIsOnStage);

		virtual Void nmeGetObjectsUnderPoint( ::neash::geom::Point point,Array< ::neash::display::DisplayObject > result);

		virtual int nmeGetChildIndex( ::neash::display::DisplayObject child);
		Dynamic nmeGetChildIndex_dyn();

		virtual ::neash::display::DisplayObject nmeFindByID( int inID);

		virtual Void nmeBroadcast( ::neash::events::Event inEvt);

		virtual Void nmeAddChild( ::neash::display::DisplayObject child);
		Dynamic nmeAddChild_dyn();

		virtual Array< ::neash::display::DisplayObject > getObjectsUnderPoint( ::neash::geom::Point point);
		Dynamic getObjectsUnderPoint_dyn();

		virtual int getChildIndex( ::neash::display::DisplayObject child);
		Dynamic getChildIndex_dyn();

		virtual ::neash::display::DisplayObject getChildByName( ::String name);
		Dynamic getChildByName_dyn();

		virtual ::neash::display::DisplayObject getChildAt( int index);
		Dynamic getChildAt_dyn();

		virtual bool contains( ::neash::display::DisplayObject child);
		Dynamic contains_dyn();

		virtual bool areInaccessibleObjectsUnderPoint( ::neash::geom::Point point);
		Dynamic areInaccessibleObjectsUnderPoint_dyn();

		virtual ::neash::display::DisplayObject addChildAt( ::neash::display::DisplayObject child,int index);
		Dynamic addChildAt_dyn();

		virtual ::neash::display::DisplayObject addChild( ::neash::display::DisplayObject child);
		Dynamic addChild_dyn();

		Array< ::neash::display::DisplayObject > nmeChildren; /* REM */ 
		bool tabChildren; /* REM */ 
		int numChildren; /* REM */ 
		bool mouseChildren; /* REM */ 
		static Dynamic nme_create_display_object_container; /* REM */ 
		static Dynamic &nme_create_display_object_container_dyn() { return nme_create_display_object_container;}
		static Dynamic nme_doc_add_child; /* REM */ 
		static Dynamic &nme_doc_add_child_dyn() { return nme_doc_add_child;}
		static Dynamic nme_doc_remove_child; /* REM */ 
		static Dynamic &nme_doc_remove_child_dyn() { return nme_doc_remove_child;}
		static Dynamic nme_doc_set_child_index; /* REM */ 
		static Dynamic &nme_doc_set_child_index_dyn() { return nme_doc_set_child_index;}
		static Dynamic nme_doc_get_mouse_children; /* REM */ 
		static Dynamic &nme_doc_get_mouse_children_dyn() { return nme_doc_get_mouse_children;}
		static Dynamic nme_doc_set_mouse_children; /* REM */ 
		static Dynamic &nme_doc_set_mouse_children_dyn() { return nme_doc_set_mouse_children;}
		static Dynamic nme_doc_swap_children; /* REM */ 
		static Dynamic &nme_doc_swap_children_dyn() { return nme_doc_swap_children;}
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_DisplayObjectContainer */ 
