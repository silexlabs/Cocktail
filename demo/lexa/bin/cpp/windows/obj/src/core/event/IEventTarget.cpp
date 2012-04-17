#include <hxcpp.h>

#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
namespace core{
namespace event{


Class IEventTarget_obj::__mClass;

void IEventTarget_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.event.IEventTarget"), hx::TCanCast< IEventTarget_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace core
} // end namespace event
