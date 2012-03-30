#ifndef INCLUDED_core_dom_AnchorTarget
#define INCLUDED_core_dom_AnchorTarget

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,AnchorTarget)
namespace core{
namespace dom{


class AnchorTarget_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AnchorTarget_obj OBJ_;

	public:
		AnchorTarget_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.AnchorTarget"); }
		::String __ToString() const { return HX_CSTRING("AnchorTarget.") + tag; }

		static ::core::dom::AnchorTarget blank;
		static inline ::core::dom::AnchorTarget blank_dyn() { return blank; }
		static ::core::dom::AnchorTarget parent;
		static inline ::core::dom::AnchorTarget parent_dyn() { return parent; }
		static ::core::dom::AnchorTarget self;
		static inline ::core::dom::AnchorTarget self_dyn() { return self; }
		static ::core::dom::AnchorTarget top;
		static inline ::core::dom::AnchorTarget top_dyn() { return top; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_AnchorTarget */ 
