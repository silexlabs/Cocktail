#ifndef INCLUDED_core_style_floats_FloatsManager
#define INCLUDED_core_style_floats_FloatsManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,style,Clear)
HX_DECLARE_CLASS3(core,style,floats,FloatsManager)
namespace core{
namespace style{
namespace floats{


class FloatsManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FloatsManager_obj OBJ_;
		FloatsManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FloatsManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FloatsManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatsManager"); }

		Dynamic _floats; /* REM */ 
		Dynamic floats; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual int clearFloat( ::core::style::Clear clear,Dynamic formattingContextData);
		Dynamic clearFloat_dyn();

		virtual int clearLeft( Dynamic formattingContextData);
		Dynamic clearLeft_dyn();

		virtual int clearRight( Dynamic formattingContextData);
		Dynamic clearRight_dyn();

		virtual int clearBoth( Dynamic formattingContextData);
		Dynamic clearBoth_dyn();

		virtual int doClearFloat( Dynamic formattingContextData,Dynamic floats);
		Dynamic doClearFloat_dyn();

		virtual Dynamic computeFloatData( ::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth);
		Dynamic computeFloatData_dyn();

		virtual Dynamic getLeftFloatData( ::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth);
		Dynamic getLeftFloatData_dyn();

		virtual Dynamic getRightFloatData( ::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth);
		Dynamic getRightFloatData_dyn();

		virtual Dynamic getFloatData( ::core::renderer::ElementRenderer elementRenderer,Dynamic formattingContextData,int containingBlockWidth);
		Dynamic getFloatData_dyn();

		virtual int getFirstAvailableY( Dynamic formattingContextData,int elementWidth,int containingBlockWidth);
		Dynamic getFirstAvailableY_dyn();

		virtual Void removeFloats( int flowY);
		Dynamic removeFloats_dyn();

		virtual Dynamic doRemoveFloat( Dynamic floats,int flowY);
		Dynamic doRemoveFloat_dyn();

		virtual int getRightFloatOffset( int y,int containingWidth);
		Dynamic getRightFloatOffset_dyn();

		virtual int getLeftFloatOffset( int y);
		Dynamic getLeftFloatOffset_dyn();

		virtual Dynamic getFloats( );
		Dynamic getFloats_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace floats

#endif /* INCLUDED_core_style_floats_FloatsManager */ 
