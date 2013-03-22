#ifndef INCLUDED_neash_errors_ArgumentError
#define INCLUDED_neash_errors_ArgumentError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/errors/Error.h>
HX_DECLARE_CLASS2(neash,errors,ArgumentError)
HX_DECLARE_CLASS2(neash,errors,Error)
namespace neash{
namespace errors{


class ArgumentError_obj : public ::neash::errors::Error_obj{
	public:
		typedef ::neash::errors::Error_obj super;
		typedef ArgumentError_obj OBJ_;
		ArgumentError_obj();
		Void __construct(Dynamic inMessage,Dynamic id);

	public:
		static hx::ObjectPtr< ArgumentError_obj > __new(Dynamic inMessage,Dynamic id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArgumentError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ArgumentError"); }

};

} // end namespace neash
} // end namespace errors

#endif /* INCLUDED_neash_errors_ArgumentError */ 
