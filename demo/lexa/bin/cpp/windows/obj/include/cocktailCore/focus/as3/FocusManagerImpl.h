#ifndef INCLUDED_cocktailCore_focus_as3_FocusManagerImpl
#define INCLUDED_cocktailCore_focus_as3_FocusManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktailCore/focus/abstract/AbstractFocusManagerImpl.h>
HX_DECLARE_CLASS3(cocktailCore,focus,abstract,AbstractFocusManagerImpl)
HX_DECLARE_CLASS3(cocktailCore,focus,as3,FocusManagerImpl)
namespace cocktailCore{
namespace focus{
namespace as3{


class FocusManagerImpl_obj : public ::cocktailCore::focus::abstract::AbstractFocusManagerImpl_obj{
	public:
		typedef ::cocktailCore::focus::abstract::AbstractFocusManagerImpl_obj super;
		typedef FocusManagerImpl_obj OBJ_;
		FocusManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FocusManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FocusManagerImpl"); }

};

} // end namespace cocktailCore
} // end namespace focus
} // end namespace as3

#endif /* INCLUDED_cocktailCore_focus_as3_FocusManagerImpl */ 
