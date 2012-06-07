#ifndef INCLUDED_nme_display_DisplayObjectContainer
#define INCLUDED_nme_display_DisplayObjectContainer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/InteractiveObject.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace nme{
namespace display{


class DisplayObjectContainer_obj : public ::nme::display::InteractiveObject_obj{
	public:
		typedef ::nme::display::InteractiveObject_obj super;
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
		::String __ToString() const { return HX_CSTRING("DisplayObjectContainer"); }

		bool mouseChildren; /* REM */ 
		int numChildren; /* REM */ 
		bool tabChildren; /* REM */ 
		Array< ::nme::display::DisplayObject > nmeChildren; /* REM */ 
		virtual ::nme::display::DisplayObject addChild( ::nme::display::DisplayObject child);
		Dynamic addChild_dyn();

		virtual ::nme::display::DisplayObject addChildAt( ::nme::display::DisplayObject child,int index);
		Dynamic addChildAt_dyn();

		virtual bool areInaccessibleObjectsUnderPoint( ::nme::geom::Point point);
		Dynamic areInaccessibleObjectsUnderPoint_dyn();

		virtual bool contains( ::nme::display::DisplayObject child);
		Dynamic contains_dyn();

		virtual ::nme::display::DisplayObject getChildAt( int index);
		Dynamic getChildAt_dyn();

		virtual ::nme::display::DisplayObject getChildByName( ::String name);
		Dynamic getChildByName_dyn();

		virtual int getChildIndex( ::nme::display::DisplayObject child);
		Dynamic getChildIndex_dyn();

		virtual Array< ::nme::display::DisplayObject > getObjectsUnderPoint( ::nme::geom::Point point);
		Dynamic getObjectsUnderPoint_dyn();

		virtual Void nmeAddChild( ::nme::display::DisplayObject child);
		Dynamic nmeAddChild_dyn();

		virtual Void nmeBroadcast( ::nme::events::Event inEvt);
		Dynamic nmeBroadcast_dyn();

		virtual ::nme::display::DisplayObject nmeFindByID( int inID);
		Dynamic nmeFindByID_dyn();

		virtual int nmeGetChildIndex( ::nme::display::DisplayObject child);
		Dynamic nmeGetChildIndex_dyn();

		virtual Void nmeGetObjectsUnderPoint( ::nme::geom::Point point,Array< ::nme::display::DisplayObject > result);
		Dynamic nmeGetObjectsUnderPoint_dyn();

		virtual Void nmeOnAdded( ::nme::display::DisplayObject inObj,bool inIsOnStage);
		Dynamic nmeOnAdded_dyn();

		virtual Void nmeOnRemoved( ::nme::display::DisplayObject inObj,bool inWasOnStage);
		Dynamic nmeOnRemoved_dyn();

		virtual Void nmeRemoveChildFromArray( ::nme::display::DisplayObject child);
		Dynamic nmeRemoveChildFromArray_dyn();

		virtual Void nmeSetChildIndex( ::nme::display::DisplayObject child,int index);
		Dynamic nmeSetChildIndex_dyn();

		virtual Void nmeSwapChildrenAt( int index1,int index2);
		Dynamic nmeSwapChildrenAt_dyn();

		virtual ::nme::display::DisplayObject removeChild( ::nme::display::DisplayObject child);
		Dynamic removeChild_dyn();

		virtual ::nme::display::DisplayObject removeChildAt( int index);
		Dynamic removeChildAt_dyn();

		virtual Void setChildIndex( ::nme::display::DisplayObject child,int index);
		Dynamic setChildIndex_dyn();

		virtual Void swapChildren( ::nme::display::DisplayObject child1,::nme::display::DisplayObject child2);
		Dynamic swapChildren_dyn();

		virtual Void swapChildrenAt( int index1,int index2);
		Dynamic swapChildrenAt_dyn();

		virtual bool nmeGetMouseChildren( );
		Dynamic nmeGetMouseChildren_dyn();

		virtual bool nmeSetMouseChildren( bool inVal);
		Dynamic nmeSetMouseChildren_dyn();

		virtual int nmeGetNumChildren( );
		Dynamic nmeGetNumChildren_dyn();

		virtual bool nmeGetTabChildren( );
		Dynamic nmeGetTabChildren_dyn();

		virtual bool nmeSetTabChildren( bool inValue);
		Dynamic nmeSetTabChildren_dyn();

		static Dynamic nme_create_display_object_container; /* REM */ 
	Dynamic &nme_create_display_object_container_dyn() { return nme_create_display_object_container;}
		static Dynamic nme_doc_add_child; /* REM */ 
	Dynamic &nme_doc_add_child_dyn() { return nme_doc_add_child;}
		static Dynamic nme_doc_remove_child; /* REM */ 
	Dynamic &nme_doc_remove_child_dyn() { return nme_doc_remove_child;}
		static Dynamic nme_doc_set_child_index; /* REM */ 
	Dynamic &nme_doc_set_child_index_dyn() { return nme_doc_set_child_index;}
		static Dynamic nme_doc_get_mouse_children; /* REM */ 
	Dynamic &nme_doc_get_mouse_children_dyn() { return nme_doc_get_mouse_children;}
		static Dynamic nme_doc_set_mouse_children; /* REM */ 
	Dynamic &nme_doc_set_mouse_children_dyn() { return nme_doc_set_mouse_children;}
		static Dynamic nme_doc_swap_children; /* REM */ 
	Dynamic &nme_doc_swap_children_dyn() { return nme_doc_swap_children;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_DisplayObjectContainer */ 
