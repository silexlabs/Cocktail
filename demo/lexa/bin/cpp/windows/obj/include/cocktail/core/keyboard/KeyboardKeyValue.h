#ifndef INCLUDED_cocktail_core_keyboard_KeyboardKeyValue
#define INCLUDED_cocktail_core_keyboard_KeyboardKeyValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,keyboard,KeyboardKeyValue)
namespace cocktail{
namespace core{
namespace keyboard{


class KeyboardKeyValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef KeyboardKeyValue_obj OBJ_;

	public:
		KeyboardKeyValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.keyboard.KeyboardKeyValue"); }
		::String __ToString() const { return HX_CSTRING("KeyboardKeyValue.") + tag; }

		static ::cocktail::core::keyboard::KeyboardKeyValue F1;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F1_dyn() { return F1; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F10;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F10_dyn() { return F10; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F11;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F11_dyn() { return F11; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F12;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F12_dyn() { return F12; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F13;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F13_dyn() { return F13; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F14;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F14_dyn() { return F14; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F15;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F15_dyn() { return F15; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F2;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F2_dyn() { return F2; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F3;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F3_dyn() { return F3; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F4;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F4_dyn() { return F4; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F5;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F5_dyn() { return F5; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F6;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F6_dyn() { return F6; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F7;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F7_dyn() { return F7; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F8;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F8_dyn() { return F8; }
		static ::cocktail::core::keyboard::KeyboardKeyValue F9;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue F9_dyn() { return F9; }
		static ::cocktail::core::keyboard::KeyboardKeyValue a;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue a_dyn() { return a; }
		static ::cocktail::core::keyboard::KeyboardKeyValue b;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue b_dyn() { return b; }
		static ::cocktail::core::keyboard::KeyboardKeyValue backSpace;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue backSpace_dyn() { return backSpace; }
		static ::cocktail::core::keyboard::KeyboardKeyValue c;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue c_dyn() { return c; }
		static ::cocktail::core::keyboard::KeyboardKeyValue capsLock;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue capsLock_dyn() { return capsLock; }
		static ::cocktail::core::keyboard::KeyboardKeyValue control;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue control_dyn() { return control; }
		static ::cocktail::core::keyboard::KeyboardKeyValue d;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue d_dyn() { return d; }
		static ::cocktail::core::keyboard::KeyboardKeyValue del;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue del_dyn() { return del; }
		static ::cocktail::core::keyboard::KeyboardKeyValue down;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue down_dyn() { return down; }
		static ::cocktail::core::keyboard::KeyboardKeyValue e;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue e_dyn() { return e; }
		static ::cocktail::core::keyboard::KeyboardKeyValue end;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue end_dyn() { return end; }
		static ::cocktail::core::keyboard::KeyboardKeyValue enter;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue enter_dyn() { return enter; }
		static ::cocktail::core::keyboard::KeyboardKeyValue escape;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue escape_dyn() { return escape; }
		static ::cocktail::core::keyboard::KeyboardKeyValue f;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue f_dyn() { return f; }
		static ::cocktail::core::keyboard::KeyboardKeyValue g;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue g_dyn() { return g; }
		static ::cocktail::core::keyboard::KeyboardKeyValue h;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue h_dyn() { return h; }
		static ::cocktail::core::keyboard::KeyboardKeyValue home;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue home_dyn() { return home; }
		static ::cocktail::core::keyboard::KeyboardKeyValue i;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue i_dyn() { return i; }
		static ::cocktail::core::keyboard::KeyboardKeyValue insert;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue insert_dyn() { return insert; }
		static ::cocktail::core::keyboard::KeyboardKeyValue j;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue j_dyn() { return j; }
		static ::cocktail::core::keyboard::KeyboardKeyValue k;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue k_dyn() { return k; }
		static ::cocktail::core::keyboard::KeyboardKeyValue l;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue l_dyn() { return l; }
		static ::cocktail::core::keyboard::KeyboardKeyValue left;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue left_dyn() { return left; }
		static ::cocktail::core::keyboard::KeyboardKeyValue m;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue m_dyn() { return m; }
		static ::cocktail::core::keyboard::KeyboardKeyValue n;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue n_dyn() { return n; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad0;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad0_dyn() { return numpad0; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad1;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad1_dyn() { return numpad1; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad2;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad2_dyn() { return numpad2; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad3;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad3_dyn() { return numpad3; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad4;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad4_dyn() { return numpad4; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad5;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad5_dyn() { return numpad5; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad6;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad6_dyn() { return numpad6; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad7;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad7_dyn() { return numpad7; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad8;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad8_dyn() { return numpad8; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpad9;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpad9_dyn() { return numpad9; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadAdd;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadAdd_dyn() { return numpadAdd; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadDecimal;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadDecimal_dyn() { return numpadDecimal; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadDivide;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadDivide_dyn() { return numpadDivide; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadEnter;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadEnter_dyn() { return numpadEnter; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadMultiply;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadMultiply_dyn() { return numpadMultiply; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadSpecial;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadSpecial_dyn() { return numpadSpecial; }
		static ::cocktail::core::keyboard::KeyboardKeyValue numpadSubstract;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue numpadSubstract_dyn() { return numpadSubstract; }
		static ::cocktail::core::keyboard::KeyboardKeyValue o;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue o_dyn() { return o; }
		static ::cocktail::core::keyboard::KeyboardKeyValue p;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue p_dyn() { return p; }
		static ::cocktail::core::keyboard::KeyboardKeyValue pageDown;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue pageDown_dyn() { return pageDown; }
		static ::cocktail::core::keyboard::KeyboardKeyValue pageUp;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue pageUp_dyn() { return pageUp; }
		static ::cocktail::core::keyboard::KeyboardKeyValue q;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue q_dyn() { return q; }
		static ::cocktail::core::keyboard::KeyboardKeyValue r;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue r_dyn() { return r; }
		static ::cocktail::core::keyboard::KeyboardKeyValue right;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue right_dyn() { return right; }
		static ::cocktail::core::keyboard::KeyboardKeyValue s;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue s_dyn() { return s; }
		static ::cocktail::core::keyboard::KeyboardKeyValue shift;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue shift_dyn() { return shift; }
		static ::cocktail::core::keyboard::KeyboardKeyValue space;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue space_dyn() { return space; }
		static ::cocktail::core::keyboard::KeyboardKeyValue t;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue t_dyn() { return t; }
		static ::cocktail::core::keyboard::KeyboardKeyValue tab;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue tab_dyn() { return tab; }
		static ::cocktail::core::keyboard::KeyboardKeyValue u;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue u_dyn() { return u; }
		static ::cocktail::core::keyboard::KeyboardKeyValue unknown;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue unknown_dyn() { return unknown; }
		static ::cocktail::core::keyboard::KeyboardKeyValue up;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue up_dyn() { return up; }
		static ::cocktail::core::keyboard::KeyboardKeyValue v;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue v_dyn() { return v; }
		static ::cocktail::core::keyboard::KeyboardKeyValue w;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue w_dyn() { return w; }
		static ::cocktail::core::keyboard::KeyboardKeyValue x;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue x_dyn() { return x; }
		static ::cocktail::core::keyboard::KeyboardKeyValue y;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue y_dyn() { return y; }
		static ::cocktail::core::keyboard::KeyboardKeyValue z;
		static inline ::cocktail::core::keyboard::KeyboardKeyValue z_dyn() { return z; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace keyboard

#endif /* INCLUDED_cocktail_core_keyboard_KeyboardKeyValue */ 
