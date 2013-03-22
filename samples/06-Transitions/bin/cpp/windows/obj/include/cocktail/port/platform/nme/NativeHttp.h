#ifndef INCLUDED_cocktail_port_platform_nme_NativeHttp
#define INCLUDED_cocktail_port_platform_nme_NativeHttp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/NativeHttpBase.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,http,DataFormatValue)
HX_DECLARE_CLASS3(cocktail,port,base,NativeHttpBase)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeHttp)
namespace cocktail{
namespace port{
namespace platform{
namespace nme{


class NativeHttp_obj : public ::cocktail::port::base::NativeHttpBase_obj{
	public:
		typedef ::cocktail::port::base::NativeHttpBase_obj super;
		typedef NativeHttp_obj OBJ_;
		NativeHttp_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeHttp_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeHttp_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeHttp"); }

		virtual Void doLoad( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat);

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_cocktail_port_platform_nme_NativeHttp */ 
