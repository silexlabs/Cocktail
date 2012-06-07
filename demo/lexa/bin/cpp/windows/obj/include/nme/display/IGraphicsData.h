#ifndef INCLUDED_nme_display_IGraphicsData
#define INCLUDED_nme_display_IGraphicsData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,IGraphicsData)
namespace nme{
namespace display{


class IGraphicsData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IGraphicsData_obj OBJ_;
		IGraphicsData_obj();
		Void __construct(Dynamic inHandle);

	public:
		static hx::ObjectPtr< IGraphicsData_obj > __new(Dynamic inHandle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IGraphicsData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("IGraphicsData"); }

		Dynamic nmeHandle; /* REM */ 
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_IGraphicsData */ 
