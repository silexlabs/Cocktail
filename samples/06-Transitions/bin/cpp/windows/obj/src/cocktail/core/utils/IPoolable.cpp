#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace utils{

HX_DEFINE_DYNAMIC_FUNC0(IPoolable_obj,reset,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IPoolable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IPoolable_obj::__mClass,"__mClass");
};

Class IPoolable_obj::__mClass;

void IPoolable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.utils.IPoolable"), hx::TCanCast< IPoolable_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IPoolable_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace utils
