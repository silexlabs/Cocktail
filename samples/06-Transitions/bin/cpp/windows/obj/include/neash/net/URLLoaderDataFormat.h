#ifndef INCLUDED_neash_net_URLLoaderDataFormat
#define INCLUDED_neash_net_URLLoaderDataFormat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,net,URLLoaderDataFormat)
namespace neash{
namespace net{


class URLLoaderDataFormat_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef URLLoaderDataFormat_obj OBJ_;

	public:
		URLLoaderDataFormat_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.net.URLLoaderDataFormat"); }
		::String __ToString() const { return HX_CSTRING("URLLoaderDataFormat.") + tag; }

		static ::neash::net::URLLoaderDataFormat BINARY;
		static inline ::neash::net::URLLoaderDataFormat BINARY_dyn() { return BINARY; }
		static ::neash::net::URLLoaderDataFormat TEXT;
		static inline ::neash::net::URLLoaderDataFormat TEXT_dyn() { return TEXT; }
		static ::neash::net::URLLoaderDataFormat VARIABLES;
		static inline ::neash::net::URLLoaderDataFormat VARIABLES_dyn() { return VARIABLES; }
};

} // end namespace neash
} // end namespace net

#endif /* INCLUDED_neash_net_URLLoaderDataFormat */ 
