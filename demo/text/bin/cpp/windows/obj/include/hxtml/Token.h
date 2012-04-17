#ifndef INCLUDED_hxtml_Token
#define INCLUDED_hxtml_Token

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxtml,Token)
namespace hxtml{


class Token_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Token_obj OBJ_;

	public:
		Token_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("hxtml.Token"); }
		::String __ToString() const { return HX_CSTRING("Token.") + tag; }

		static ::hxtml::Token TBrClose;
		static inline ::hxtml::Token TBrClose_dyn() { return TBrClose; }
		static ::hxtml::Token TBrOpen;
		static inline ::hxtml::Token TBrOpen_dyn() { return TBrOpen; }
		static ::hxtml::Token TComma;
		static inline ::hxtml::Token TComma_dyn() { return TComma; }
		static ::hxtml::Token TDblDot;
		static inline ::hxtml::Token TDblDot_dyn() { return TDblDot; }
		static ::hxtml::Token TDot;
		static inline ::hxtml::Token TDot_dyn() { return TDot; }
		static ::hxtml::Token TEof;
		static inline ::hxtml::Token TEof_dyn() { return TEof; }
		static ::hxtml::Token TExclam;
		static inline ::hxtml::Token TExclam_dyn() { return TExclam; }
		static ::hxtml::Token TFloat(double f);
		static Dynamic TFloat_dyn();
		static ::hxtml::Token TIdent(::String i);
		static Dynamic TIdent_dyn();
		static ::hxtml::Token TInt(int i);
		static Dynamic TInt_dyn();
		static ::hxtml::Token TPClose;
		static inline ::hxtml::Token TPClose_dyn() { return TPClose; }
		static ::hxtml::Token TPOpen;
		static inline ::hxtml::Token TPOpen_dyn() { return TPOpen; }
		static ::hxtml::Token TPercent;
		static inline ::hxtml::Token TPercent_dyn() { return TPercent; }
		static ::hxtml::Token TSemicolon;
		static inline ::hxtml::Token TSemicolon_dyn() { return TSemicolon; }
		static ::hxtml::Token TSharp;
		static inline ::hxtml::Token TSharp_dyn() { return TSharp; }
		static ::hxtml::Token TSlash;
		static inline ::hxtml::Token TSlash_dyn() { return TSlash; }
		static ::hxtml::Token TSpaces;
		static inline ::hxtml::Token TSpaces_dyn() { return TSpaces; }
		static ::hxtml::Token TString(::String s);
		static Dynamic TString_dyn();
};

} // end namespace hxtml

#endif /* INCLUDED_hxtml_Token */ 
