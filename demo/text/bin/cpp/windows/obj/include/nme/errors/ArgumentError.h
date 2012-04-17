#ifndef INCLUDED_nme_errors_ArgumentError
#define INCLUDED_nme_errors_ArgumentError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/errors/Error.h>
HX_DECLARE_CLASS2(nme,errors,ArgumentError)
HX_DECLARE_CLASS2(nme,errors,Error)
namespace nme{
namespace errors{


class ArgumentError_obj : public ::nme::errors::Error_obj{
	public:
		typedef ::nme::errors::Error_obj super;
		typedef ArgumentError_obj OBJ_;
		ArgumentError_obj();
		Void __construct(Dynamic inMessage,Dynamic __o_id);

	public:
		static hx::ObjectPtr< ArgumentError_obj > __new(Dynamic inMessage,Dynamic __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArgumentError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ArgumentError"); }

};

} // end namespace nme
} // end namespace errors

#endif /* INCLUDED_nme_errors_ArgumentError */ 
