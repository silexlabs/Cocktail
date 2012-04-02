#ifndef INCLUDED_nme_errors_RangeError
#define INCLUDED_nme_errors_RangeError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/errors/Error.h>
HX_DECLARE_CLASS2(nme,errors,Error)
HX_DECLARE_CLASS2(nme,errors,RangeError)
namespace nme{
namespace errors{


class RangeError_obj : public ::nme::errors::Error_obj{
	public:
		typedef ::nme::errors::Error_obj super;
		typedef RangeError_obj OBJ_;
		RangeError_obj();
		Void __construct(Dynamic __o_inMessage);

	public:
		static hx::ObjectPtr< RangeError_obj > __new(Dynamic __o_inMessage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RangeError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("RangeError"); }

};

} // end namespace nme
} // end namespace errors

#endif /* INCLUDED_nme_errors_RangeError */ 
