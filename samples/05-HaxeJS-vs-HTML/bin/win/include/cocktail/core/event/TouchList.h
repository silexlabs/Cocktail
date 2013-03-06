#ifndef INCLUDED_cocktail_core_event_TouchList
#define INCLUDED_cocktail_core_event_TouchList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,TouchList)
namespace cocktail{
namespace core{
namespace event{


class TouchList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TouchList_obj OBJ_;
		TouchList_obj();
		Void __construct(Dynamic touches);

	public:
		static hx::ObjectPtr< TouchList_obj > __new(Dynamic touches);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchList"); }

		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual Dynamic identifiedTouch( int identifier);
		Dynamic identifiedTouch_dyn();

		virtual Dynamic item( int index);
		Dynamic item_dyn();

		int length; /* REM */ 
		Dynamic _touches; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_TouchList */ 
