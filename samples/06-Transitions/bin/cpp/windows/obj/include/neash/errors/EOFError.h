#ifndef INCLUDED_neash_errors_EOFError
#define INCLUDED_neash_errors_EOFError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/errors/Error.h>
HX_DECLARE_CLASS2(neash,errors,EOFError)
HX_DECLARE_CLASS2(neash,errors,Error)
namespace neash{
namespace errors{


class EOFError_obj : public ::neash::errors::Error_obj{
	public:
		typedef ::neash::errors::Error_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EOFError"); }

};

} // end namespace neash
} // end namespace errors

#endif /* INCLUDED_neash_errors_EOFError */ 
