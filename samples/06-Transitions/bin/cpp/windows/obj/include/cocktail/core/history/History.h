#ifndef INCLUDED_cocktail_core_history_History
#define INCLUDED_cocktail_core_history_History

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,history,History)
namespace cocktail{
namespace core{
namespace history{


class History_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef History_obj OBJ_;
		History_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< History_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~History_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("History"); }

		virtual ::String resolveUrl( ::String url,::String base);
		Dynamic resolveUrl_dyn();

		virtual Dynamic computeStateData( Dynamic data,::String title,::String url);
		Dynamic computeStateData_dyn();

		virtual Dynamic cloneData( Dynamic data);
		Dynamic cloneData_dyn();

		virtual Void onPopState( Dynamic stateData);
		Dynamic onPopState_dyn();

		virtual Void replaceState( Dynamic data,::String title,::String url);
		Dynamic replaceState_dyn();

		virtual Void pushState( Dynamic data,::String title,::String url);
		Dynamic pushState_dyn();

		virtual Void forward( );
		Dynamic forward_dyn();

		virtual Void back( );
		Dynamic back_dyn();

		virtual Void go( int delta);
		Dynamic go_dyn();

		virtual int getLength( );
		Dynamic getLength_dyn();

		int currentIdx; /* REM */ 
		Dynamic stateDataArray; /* REM */ 
		Dynamic state; /* REM */ 
		int length; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace history

#endif /* INCLUDED_cocktail_core_history_History */ 
