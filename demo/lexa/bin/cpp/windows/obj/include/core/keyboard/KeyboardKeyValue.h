#ifndef INCLUDED_core_keyboard_KeyboardKeyValue
#define INCLUDED_core_keyboard_KeyboardKeyValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,keyboard,KeyboardKeyValue)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.keyboard.KeyboardKeyValue"); }
		::String __ToString() const { return HX_CSTRING("KeyboardKeyValue.") + tag; }

		static ::core::keyboard::KeyboardKeyValue F1;
		static inline ::core::keyboard::KeyboardKeyValue F1_dyn() { return F1; }
		static ::core::keyboard::KeyboardKeyValue F10;
		static inline ::core::keyboard::KeyboardKeyValue F10_dyn() { return F10; }
		static ::core::keyboard::KeyboardKeyValue F11;
		static inline ::core::keyboard::KeyboardKeyValue F11_dyn() { return F11; }
		static ::core::keyboard::KeyboardKeyValue F12;
		static inline ::core::keyboard::KeyboardKeyValue F12_dyn() { return F12; }
		static ::core::keyboard::KeyboardKeyValue F13;
		static inline ::core::keyboard::KeyboardKeyValue F13_dyn() { return F13; }
		static ::core::keyboard::KeyboardKeyValue F14;
		static inline ::core::keyboard::KeyboardKeyValue F14_dyn() { return F14; }
		static ::core::keyboard::KeyboardKeyValue F15;
		static inline ::core::keyboard::KeyboardKeyValue F15_dyn() { return F15; }
		static ::core::keyboard::KeyboardKeyValue F2;
		static inline ::core::keyboard::KeyboardKeyValue F2_dyn() { return F2; }
		static ::core::keyboard::KeyboardKeyValue F3;
		static inline ::core::keyboard::KeyboardKeyValue F3_dyn() { return F3; }
		static ::core::keyboard::KeyboardKeyValue F4;
		static inline ::core::keyboard::KeyboardKeyValue F4_dyn() { return F4; }
		static ::core::keyboard::KeyboardKeyValue F5;
		static inline ::core::keyboard::KeyboardKeyValue F5_dyn() { return F5; }
		static ::core::keyboard::KeyboardKeyValue F6;
		static inline ::core::keyboard::KeyboardKeyValue F6_dyn() { return F6; }
		static ::core::keyboard::KeyboardKeyValue F7;
		static inline ::core::keyboard::KeyboardKeyValue F7_dyn() { return F7; }
		static ::core::keyboard::KeyboardKeyValue F8;
		static inline ::core::keyboard::KeyboardKeyValue F8_dyn() { return F8; }
		static ::core::keyboard::KeyboardKeyValue F9;
		static inline ::core::keyboard::KeyboardKeyValue F9_dyn() { return F9; }
		static ::core::keyboard::KeyboardKeyValue a;
		static inline ::core::keyboard::KeyboardKeyValue a_dyn() { return a; }
		static ::core::keyboard::KeyboardKeyValue b;
		static inline ::core::keyboard::KeyboardKeyValue b_dyn() { return b; }
		static ::core::keyboard::KeyboardKeyValue backSpace;
		static inline ::core::keyboard::KeyboardKeyValue backSpace_dyn() { return backSpace; }
		static ::core::keyboard::KeyboardKeyValue c;
		static inline ::core::keyboard::KeyboardKeyValue c_dyn() { return c; }
		static ::core::keyboard::KeyboardKeyValue capsLock;
		static inline ::core::keyboard::KeyboardKeyValue capsLock_dyn() { return capsLock; }
		static ::core::keyboard::KeyboardKeyValue control;
		static inline ::core::keyboard::KeyboardKeyValue control_dyn() { return control; }
		static ::core::keyboard::KeyboardKeyValue d;
		static inline ::core::keyboard::KeyboardKeyValue d_dyn() { return d; }
		static ::core::keyboard::KeyboardKeyValue del;
		static inline ::core::keyboard::KeyboardKeyValue del_dyn() { return del; }
		static ::core::keyboard::KeyboardKeyValue down;
		static inline ::core::keyboard::KeyboardKeyValue down_dyn() { return down; }
		static ::core::keyboard::KeyboardKeyValue e;
		static inline ::core::keyboard::KeyboardKeyValue e_dyn() { return e; }
		static ::core::keyboard::KeyboardKeyValue end;
		static inline ::core::keyboard::KeyboardKeyValue end_dyn() { return end; }
		static ::core::keyboard::KeyboardKeyValue enter;
		static inline ::core::keyboard::KeyboardKeyValue enter_dyn() { return enter; }
		static ::core::keyboard::KeyboardKeyValue escape;
		static inline ::core::keyboard::KeyboardKeyValue escape_dyn() { return escape; }
		static ::core::keyboard::KeyboardKeyValue f;
		static inline ::core::keyboard::KeyboardKeyValue f_dyn() { return f; }
		static ::core::keyboard::KeyboardKeyValue g;
		static inline ::core::keyboard::KeyboardKeyValue g_dyn() { return g; }
		static ::core::keyboard::KeyboardKeyValue h;
		static inline ::core::keyboard::KeyboardKeyValue h_dyn() { return h; }
		static ::core::keyboard::KeyboardKeyValue home;
		static inline ::core::keyboard::KeyboardKeyValue home_dyn() { return home; }
		static ::core::keyboard::KeyboardKeyValue i;
		static inline ::core::keyboard::KeyboardKeyValue i_dyn() { return i; }
		static ::core::keyboard::KeyboardKeyValue insert;
		static inline ::core::keyboard::KeyboardKeyValue insert_dyn() { return insert; }
		static ::core::keyboard::KeyboardKeyValue j;
		static inline ::core::keyboard::KeyboardKeyValue j_dyn() { return j; }
		static ::core::keyboard::KeyboardKeyValue k;
		static inline ::core::keyboard::KeyboardKeyValue k_dyn() { return k; }
		static ::core::keyboard::KeyboardKeyValue l;
		static inline ::core::keyboard::KeyboardKeyValue l_dyn() { return l; }
		static ::core::keyboard::KeyboardKeyValue left;
		static inline ::core::keyboard::KeyboardKeyValue left_dyn() { return left; }
		static ::core::keyboard::KeyboardKeyValue m;
		static inline ::core::keyboard::KeyboardKeyValue m_dyn() { return m; }
		static ::core::keyboard::KeyboardKeyValue n;
		static inline ::core::keyboard::KeyboardKeyValue n_dyn() { return n; }
		static ::core::keyboard::KeyboardKeyValue numpad0;
		static inline ::core::keyboard::KeyboardKeyValue numpad0_dyn() { return numpad0; }
		static ::core::keyboard::KeyboardKeyValue numpad1;
		static inline ::core::keyboard::KeyboardKeyValue numpad1_dyn() { return numpad1; }
		static ::core::keyboard::KeyboardKeyValue numpad2;
		static inline ::core::keyboard::KeyboardKeyValue numpad2_dyn() { return numpad2; }
		static ::core::keyboard::KeyboardKeyValue numpad3;
		static inline ::core::keyboard::KeyboardKeyValue numpad3_dyn() { return numpad3; }
		static ::core::keyboard::KeyboardKeyValue numpad4;
		static inline ::core::keyboard::KeyboardKeyValue numpad4_dyn() { return numpad4; }
		static ::core::keyboard::KeyboardKeyValue numpad5;
		static inline ::core::keyboard::KeyboardKeyValue numpad5_dyn() { return numpad5; }
		static ::core::keyboard::KeyboardKeyValue numpad6;
		static inline ::core::keyboard::KeyboardKeyValue numpad6_dyn() { return numpad6; }
		static ::core::keyboard::KeyboardKeyValue numpad7;
		static inline ::core::keyboard::KeyboardKeyValue numpad7_dyn() { return numpad7; }
		static ::core::keyboard::KeyboardKeyValue numpad8;
		static inline ::core::keyboard::KeyboardKeyValue numpad8_dyn() { return numpad8; }
		static ::core::keyboard::KeyboardKeyValue numpad9;
		static inline ::core::keyboard::KeyboardKeyValue numpad9_dyn() { return numpad9; }
		static ::core::keyboard::KeyboardKeyValue numpadAdd;
		static inline ::core::keyboard::KeyboardKeyValue numpadAdd_dyn() { return numpadAdd; }
		static ::core::keyboard::KeyboardKeyValue numpadDecimal;
		static inline ::core::keyboard::KeyboardKeyValue numpadDecimal_dyn() { return numpadDecimal; }
		static ::core::keyboard::KeyboardKeyValue numpadDivide;
		static inline ::core::keyboard::KeyboardKeyValue numpadDivide_dyn() { return numpadDivide; }
		static ::core::keyboard::KeyboardKeyValue numpadEnter;
		static inline ::core::keyboard::KeyboardKeyValue numpadEnter_dyn() { return numpadEnter; }
		static ::core::keyboard::KeyboardKeyValue numpadMultiply;
		static inline ::core::keyboard::KeyboardKeyValue numpadMultiply_dyn() { return numpadMultiply; }
		static ::core::keyboard::KeyboardKeyValue numpadSpecial;
		static inline ::core::keyboard::KeyboardKeyValue numpadSpecial_dyn() { return numpadSpecial; }
		static ::core::keyboard::KeyboardKeyValue numpadSubstract;
		static inline ::core::keyboard::KeyboardKeyValue numpadSubstract_dyn() { return numpadSubstract; }
		static ::core::keyboard::KeyboardKeyValue o;
		static inline ::core::keyboard::KeyboardKeyValue o_dyn() { return o; }
		static ::core::keyboard::KeyboardKeyValue p;
		static inline ::core::keyboard::KeyboardKeyValue p_dyn() { return p; }
		static ::core::keyboard::KeyboardKeyValue pageDown;
		static inline ::core::keyboard::KeyboardKeyValue pageDown_dyn() { return pageDown; }
		static ::core::keyboard::KeyboardKeyValue pageUp;
		static inline ::core::keyboard::KeyboardKeyValue pageUp_dyn() { return pageUp; }
		static ::core::keyboard::KeyboardKeyValue q;
		static inline ::core::keyboard::KeyboardKeyValue q_dyn() { return q; }
		static ::core::keyboard::KeyboardKeyValue r;
		static inline ::core::keyboard::KeyboardKeyValue r_dyn() { return r; }
		static ::core::keyboard::KeyboardKeyValue right;
		static inline ::core::keyboard::KeyboardKeyValue right_dyn() { return right; }
		static ::core::keyboard::KeyboardKeyValue s;
		static inline ::core::keyboard::KeyboardKeyValue s_dyn() { return s; }
		static ::core::keyboard::KeyboardKeyValue shift;
		static inline ::core::keyboard::KeyboardKeyValue shift_dyn() { return shift; }
		static ::core::keyboard::KeyboardKeyValue space;
		static inline ::core::keyboard::KeyboardKeyValue space_dyn() { return space; }
		static ::core::keyboard::KeyboardKeyValue t;
		static inline ::core::keyboard::KeyboardKeyValue t_dyn() { return t; }
		static ::core::keyboard::KeyboardKeyValue tab;
		static inline ::core::keyboard::KeyboardKeyValue tab_dyn() { return tab; }
		static ::core::keyboard::KeyboardKeyValue u;
		static inline ::core::keyboard::KeyboardKeyValue u_dyn() { return u; }
		static ::core::keyboard::KeyboardKeyValue unknown;
		static inline ::core::keyboard::KeyboardKeyValue unknown_dyn() { return unknown; }
		static ::core::keyboard::KeyboardKeyValue up;
		static inline ::core::keyboard::KeyboardKeyValue up_dyn() { return up; }
		static ::core::keyboard::KeyboardKeyValue v;
		static inline ::core::keyboard::KeyboardKeyValue v_dyn() { return v; }
		static ::core::keyboard::KeyboardKeyValue w;
		static inline ::core::keyboard::KeyboardKeyValue w_dyn() { return w; }
		static ::core::keyboard::KeyboardKeyValue x;
		static inline ::core::keyboard::KeyboardKeyValue x_dyn() { return x; }
		static ::core::keyboard::KeyboardKeyValue y;
		static inline ::core::keyboard::KeyboardKeyValue y_dyn() { return y; }
		static ::core::keyboard::KeyboardKeyValue z;
		static inline ::core::keyboard::KeyboardKeyValue z_dyn() { return z; }
};

} // end namespace core
} // end namespace keyboard

#endif /* INCLUDED_core_keyboard_KeyboardKeyValue */ 
