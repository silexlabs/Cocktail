#ifndef INCLUDED_neash_net_URLRequestHeader
#define INCLUDED_neash_net_URLRequestHeader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,net,URLRequestHeader)
namespace neash{
namespace net{


class URLRequestHeader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef URLRequestHeader_obj OBJ_;
		URLRequestHeader_obj();
		Void __construct(::String name,::String value);

	public:
		static hx::ObjectPtr< URLRequestHeader_obj > __new(::String name,::String value);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~URLRequestHeader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("URLRequestHeader"); }

		::String value; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace neash
} // end namespace net

#endif /* INCLUDED_neash_net_URLRequestHeader */ 
