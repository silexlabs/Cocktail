#ifndef INCLUDED_native_errors_SecurityError
#define INCLUDED_native_errors_SecurityError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/errors/Error.h>
HX_DECLARE_CLASS2(native,errors,Error)
HX_DECLARE_CLASS2(native,errors,SecurityError)
namespace native{
namespace errors{


class SecurityError_obj : public ::native::errors::Error_obj{
	public:
		typedef ::native::errors::Error_obj super;
		typedef SecurityError_obj OBJ_;
		SecurityError_obj();
		Void __construct(::String __o_inMessage);

	public:
		static hx::ObjectPtr< SecurityError_obj > __new(::String __o_inMessage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SecurityError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SecurityError"); }

};

} // end namespace native
} // end namespace errors

#endif /* INCLUDED_native_errors_SecurityError */ 
