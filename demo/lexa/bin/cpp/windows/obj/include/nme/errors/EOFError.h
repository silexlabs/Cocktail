#ifndef INCLUDED_nme_errors_EOFError
#define INCLUDED_nme_errors_EOFError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/errors/Error.h>
HX_DECLARE_CLASS2(nme,errors,EOFError)
HX_DECLARE_CLASS2(nme,errors,Error)
namespace nme{
namespace errors{


class EOFError_obj : public ::nme::errors::Error_obj{
	public:
		typedef ::nme::errors::Error_obj super;
		typedef EOFError_obj OBJ_;
		EOFError_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EOFError_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EOFError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EOFError"); }

};

} // end namespace nme
} // end namespace errors

#endif /* INCLUDED_nme_errors_EOFError */ 
