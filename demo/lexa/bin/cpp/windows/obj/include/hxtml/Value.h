#ifndef INCLUDED_hxtml_Value
#define INCLUDED_hxtml_Value

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxtml,Value)
namespace hxtml{


class Value_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Value_obj OBJ_;

	public:
		Value_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("hxtml.Value"); }
		::String __ToString() const { return HX_CSTRING("Value.") + tag; }

		static ::hxtml::Value VFloat(double v);
		static Dynamic VFloat_dyn();
		static ::hxtml::Value VGroup(Array< ::hxtml::Value > l);
		static Dynamic VGroup_dyn();
		static ::hxtml::Value VHex(::String v);
		static Dynamic VHex_dyn();
		static ::hxtml::Value VIdent(::String i);
		static Dynamic VIdent_dyn();
		static ::hxtml::Value VInt(int v);
		static Dynamic VInt_dyn();
		static ::hxtml::Value VLabel(::String v,::hxtml::Value val);
		static Dynamic VLabel_dyn();
		static ::hxtml::Value VList(Array< ::hxtml::Value > l);
		static Dynamic VList_dyn();
		static ::hxtml::Value VRGBA(::String v);
		static Dynamic VRGBA_dyn();
		static ::hxtml::Value VSlash;
		static inline ::hxtml::Value VSlash_dyn() { return VSlash; }
		static ::hxtml::Value VString(::String s);
		static Dynamic VString_dyn();
		static ::hxtml::Value VUnit(double v,::String unit);
		static Dynamic VUnit_dyn();
		static ::hxtml::Value VUrl(::String v);
		static Dynamic VUrl_dyn();
};

} // end namespace hxtml

#endif /* INCLUDED_hxtml_Value */ 
