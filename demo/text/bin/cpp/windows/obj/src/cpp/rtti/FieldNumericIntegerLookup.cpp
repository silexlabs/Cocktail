#include <hxcpp.h>

#ifndef INCLUDED_cpp_rtti_FieldNumericIntegerLookup
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#endif
namespace cpp{
namespace rtti{


Class FieldNumericIntegerLookup_obj::__mClass;

void FieldNumericIntegerLookup_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.rtti.FieldNumericIntegerLookup"), hx::TCanCast< FieldNumericIntegerLookup_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace cpp
} // end namespace rtti
