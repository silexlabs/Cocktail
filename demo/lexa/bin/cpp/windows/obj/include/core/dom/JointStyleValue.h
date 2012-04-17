#ifndef INCLUDED_core_dom_JointStyleValue
#define INCLUDED_core_dom_JointStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,JointStyleValue)
namespace core{
namespace dom{


class JointStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef JointStyleValue_obj OBJ_;

	public:
		JointStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.JointStyleValue"); }
		::String __ToString() const { return HX_CSTRING("JointStyleValue.") + tag; }

		static ::core::dom::JointStyleValue bevel;
		static inline ::core::dom::JointStyleValue bevel_dyn() { return bevel; }
		static ::core::dom::JointStyleValue miter;
		static inline ::core::dom::JointStyleValue miter_dyn() { return miter; }
		static ::core::dom::JointStyleValue round;
		static inline ::core::dom::JointStyleValue round_dyn() { return round; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_JointStyleValue */ 
