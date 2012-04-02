#ifndef INCLUDED_core_dom_CapsStyleValue
#define INCLUDED_core_dom_CapsStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,CapsStyleValue)
namespace core{
namespace dom{


class CapsStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CapsStyleValue_obj OBJ_;

	public:
		CapsStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.CapsStyleValue"); }
		::String __ToString() const { return HX_CSTRING("CapsStyleValue.") + tag; }

		static ::core::dom::CapsStyleValue none;
		static inline ::core::dom::CapsStyleValue none_dyn() { return none; }
		static ::core::dom::CapsStyleValue round;
		static inline ::core::dom::CapsStyleValue round_dyn() { return round; }
		static ::core::dom::CapsStyleValue square;
		static inline ::core::dom::CapsStyleValue square_dyn() { return square; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_CapsStyleValue */ 
