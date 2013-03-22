#ifndef INCLUDED_cocktail_core_utils_IPoolable
#define INCLUDED_cocktail_core_utils_IPoolable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace utils{


class IPoolable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IPoolable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void reset( )=0;
		Dynamic reset_dyn();
};

#define DELEGATE_cocktail_core_utils_IPoolable \
virtual Void reset( ) { return mDelegate->reset();}  \
virtual Dynamic reset_dyn() { return mDelegate->reset_dyn();}  \


template<typename IMPL>
class IPoolable_delegate_ : public IPoolable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IPoolable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_cocktail_core_utils_IPoolable
};

} // end namespace cocktail
} // end namespace core
} // end namespace utils

#endif /* INCLUDED_cocktail_core_utils_IPoolable */ 
