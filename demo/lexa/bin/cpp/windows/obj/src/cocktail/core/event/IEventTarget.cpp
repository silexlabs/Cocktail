#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
namespace cocktail{
namespace core{
namespace event{


Class IEventTarget_obj::__mClass;

void IEventTarget_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.IEventTarget"), hx::TCanCast< IEventTarget_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
